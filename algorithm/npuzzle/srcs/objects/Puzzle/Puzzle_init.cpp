#include "Puzzle.hpp"


static bool regex_comment(const string& line) { return (std::regex_search(line, std::regex("^[\t ]*($|[#])"))); }
static bool regex_length(const string& line) { return (std::regex_search(line, std::regex("^[\t ]*([+]|[-])?[0-9]+[\t ]*($|[#])"))); }
static bool regex_row(const string& line) { return (std::regex_search(line, std::regex("^[\t ]*(([+]|[-])?[0-9]+)([\t ]+(([+]|[-])?[0-9]+))+[\t ]*($|[#])"))); }
static bool regex_row_wlength(const string& line, const int& length) { return (std::regex_search(line, std::regex("^[\t ]*(([+]|[-])?[0-9]+)([\t ]+(([+]|[-])?[0-9]+)){" + std::to_string(length - 1) + "}[\t ]*($|[#])"))); }

static bool get_length(std::istream& strm, int& length, int& line_count)
{
    std::string     line;

    while (std::getline(strm, line))
    {
        ++line_count;
        if (regex_length(line))
        {
           length = std::atoi(line.c_str());
            return (false);
        }
        else if (regex_row(line))
            return (lib::printerr(RED, "ERROR: No Size"));
        else if (!regex_comment(line))
            return (lib::printerr(RED, "ERROR: Line ", line_count, " : \"", line, "\" : Expect Size"));
        
    }
    return (lib::printerr(RED, "ERROR: file is empty"));
}

static bool get_array(std::istream& strm, int *array, int& line_count)
{
    std::string     line;
    int             row_count(0);

    while (std::getline(strm, line))
    {
        ++line_count;
        if (regex_row(line))
        {
            if (row_count >= State::length)
                return (lib::printerr(RED, "ERROR: Too much rows row(s) : Size is ", State::length));
            if (!regex_row_wlength(line, State::length))
                return (lib::printerr(RED, "ERROR: Line ", line_count, " : \"", line, "\" : Number of columns incorrect, Size is ", State::length));
            std::stringstream   line_strm(line);
            for (int i = 0; i < State::length; ++i)
                line_strm >> array[row_count * State::length + i];
            ++row_count;
        }
        else if (!regex_comment(line))
            return (lib::printerr(RED, "ERROR: Line ", line_count, " : \"", line, "\" (Expected Row)"));
    }
    if (row_count < State::length)
        return (lib::printerr(RED, "ERROR: Missing row(s), Only ", row_count, " row(s) : Size is ", State::length));
    return (false);
}

bool    verif_array(const int *array)
{
    bool    *verif = new bool[State::size];

    for (int i = 0; i < State::size; ++i) verif[i] = false;

    for (int i = 0; i < State::size; ++i)
    {
        if (array[i] >= 0 && array[i] < State::size && !verif[array[i]])
            verif[array[i]] = true;
        else if (verif[array[i]])
        {
            delete (verif);
            return (lib::printerr(RED, "ERROR: Value '", array[i], "' is used at least twice"));
        }
        else if (array[i] < 0)
        {
            delete (verif);
            return (lib::printerr(RED, "ERROR: Value '", array[i], "' is too small, must be positive"));
        }
        else
        {
            delete (verif);
            return (lib::printerr(RED, "ERROR: Value '", array[i], "' is too high, must be strictly smaller than ", State::size, " (Size * Size)"));
        }
    }

    for (int i = 0; i < State::size; ++i) if (!verif[i]) { delete (verif); return (lib::printerr(RED, "ERROR: Missing Value '", i, "'")); }

    delete (verif);
    return (false);
}

int     Puzzle::init_goal_snail(int *goal)
{
    int     row(0);
    int     row_end(State::length - 1);
    int     col(0);
    int     col_end(State::length - 1);
    int     i;
    int     nbr(0);

    while (row <= row_end && col <= col_end)
    {
        for (i = col; i <= col_end; ++i)
            goal[row * State::length + i] = ++nbr;
        ++row;

        for (i = row; i <= row_end; ++i)
            goal[i * State::length + col_end] = ++nbr;
        --col_end;

        for (i = col_end; i >= col; --i)
            goal[row_end * State::length + i] = ++nbr;
        --row_end;

        for (i = row_end; i >= row; --i)
            goal[i * State::length + col] = ++nbr;
        ++col;
    }

    if (State::length % 2 == 1)
        m_goal->setZeroPosition(((State::length / 2) * State::length) + (State::length / 2));
    else
        m_goal->setZeroPosition(((State::length / 2) * State::length) + (State::length / 2 - 1));
    goal[m_goal->getZeroPosition()] = 0;
    return (0);
}

int     Puzzle::init_goal_ordered(int *goal)
{
    for (int i = 0; i < State::size; ++i) goal[i] = i + 1;
    goal[State::size - 1] = 0;
    m_goal->setZeroPosition(State::size - 1);
    return (0);
}

int     Puzzle::init_goal_file(int *goal)
{
    std::ifstream   strm(m_options.goal_file);
    int     line_count(-1);
    int     length(0);

    if (strm.fail())
        return (lib::printerr(RED, "ERROR: Goal file \"", m_options.goal_file, "\" could't be open (not existing or failed to open)"));
    if (get_length(strm, length, line_count))
        return (1);
    if (State::length != length)
        return (lib::printerr(RED, "ERROR: Goal Size is different from Start"));
    if (get_array(strm, goal, line_count))
        return (1);
    strm.close();
    for (int i = 0; i < State::size; ++i) if (goal[i] == 0) { m_goal->setZeroPosition(i); break ; }
    if (verif_array(goal))
        return (1);
    return (0);
}

int     Puzzle::init_goal()
{
    int     *goal;

    goal = new int[State::size];

    if (m_options.goal_type == T_SNAIL)
        init_goal_snail(goal);
    else if (m_options.goal_type == T_ORDERED)
        init_goal_ordered(goal);
    else if (m_options.goal_type == T_FILE)
    {
        if (init_goal_file(goal))
        {
            delete (goal);
            return (1);
        }
    }

    m_goal->setArray(goal);
    m_goal->setNbrMoves(0);
    m_goal->setHash();
    m_goal->setScore(m_goal->getArray(), m_options.heuristic, m_options.algorithm);
    return (0);
}

int     Puzzle::init_start(const int *goal, int& line_count)
{
	int     *start;
    start = new int[State::size];

    if (m_options.generation)
        Puzzle::generate_start_array(start, goal);
    else if (get_array(std::cin, start, line_count))
    {
        delete (start);
        return (1);
    }

    m_start->setArray(start);
    m_start->setNbrMoves(0);
    m_start->setHash();
    m_start->setScore(goal, m_options.heuristic, m_options.algorithm);
    for (int i = 0; i < State::size; ++i) if (start[i] == 0) { m_start->setZeroPosition(i); break ; }
    return (0);
}

int     Puzzle::init()
{
    int     line_count(-1);
    string  line;

    m_infos.initalize = false;
    if (!m_options.generation && get_length(std::cin, State::length, line_count))
        return (1);
    else if (m_options.generation)
        State::length = m_options.generation_length;
    if (State::length <= 2 || State::length > 256)
        return (lib::printerr(RED, "ERROR: Size must be greater strictly greater than 2 and smaller than 256"));
    
    State::size = State::length * State::length;

    if (init_goal())
        return (1);
    if (init_start(m_goal->getArray(), line_count))
        return (1);
    if (verif_array(m_start->getArray()))
        return (1);

    m_infos.initalize = true;
    return (0);
}

