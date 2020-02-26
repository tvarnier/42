#include "Puzzle.hpp"


static bool regex_comment(const string& line) { return (std::regex_search(line, std::regex("^[\t ]*($|[#])"))); }
static bool regex_length(const string& line) { return (std::regex_search(line, std::regex("^[\t ]*([+]|[-])?[0-9]+[\t ]*($|[#])"))); }
static bool regex_row(const string& line) { return (std::regex_search(line, std::regex("^[\t ]*(([+]|[-])?[0-9]+)([\t ]+(([+]|[-])?[0-9]+))+[\t ]*($|[#])"))); }
static bool regex_row_wlength(const string& line, const int& length) { return (std::regex_search(line, std::regex("^[\t ]*(([+]|[-])?[0-9]+)([\t ]+(([+]|[-])?[0-9]+)){" + std::to_string(length - 1) + "}[\t ]*($|[#])"))); }

static bool get_length(int& line_count)
{
    std::string     line;

    while (std::getline(std::cin, line))
    {
        ++line_count;
        if (regex_length(line))
        {
            State::length = std::atoi(line.c_str());
            if (State::length <= 2 || State::length > 256)
                return (lib::printerr(RED, "ERROR: Size must be greater strictly greater than 2 and smaller than 256"));
            return (false);
        }
        else if (regex_row(line))
            return (lib::printerr(RED, "ERROR: No Size"));
        else if (!regex_comment(line))
            return (lib::printerr(RED, "ERROR: Line ", line_count, " : \"", line, "\" : Expect Size"));
        
    }
    return (lib::printerr(RED, "ERROR: file is empty"));
}

int     Puzzle::init_goal()
{
    int     *goal;

    goal = new int[State::size];

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
    
    m_goal->setArray(goal);
    m_goal->setScore(0);
    m_goal->setNbrMoves(0);
    m_goal->setHash();
    m_goal->setScoreManhattan(goal);
    return (0);
}

static bool get_array(int *array, int& line_count)
{
    std::string     line;
    int             row_count(0);

    while (std::getline(std::cin, line))
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

int     Puzzle::init_start(const int *goal, int& line_count)
{
	int     *start;
    start = new int[State::size];

    if (get_array(start, line_count))
    {
        delete (start);
        return (1);
    }

    m_start->setArray(start);
    m_start->setNbrMoves(0);
    m_start->setHash();
    m_start->setScoreManhattan(goal);
    return (0);
}

bool    verif_start(const int *start)
{
    bool    *verif = new bool[State::size];

    for (int i = 0; i < State::size; ++i) verif[i] = false;

    for (int i = 0; i < State::size; ++i)
    {
        if (start[i] >= 0 && start[i] < State::size && !verif[start[i]])
            verif[start[i]] = true;
        else if (verif[start[i]])
        {
            delete (verif);
            return (lib::printerr(RED, "ERROR: Value '", start[i], "' is used at least twice"));
        }
        else if (start[i] < 0)
        {
            delete (verif);
            return (lib::printerr(RED, "ERROR: Value '", start[i], "' is too small, must be positive"));
        }
        else
        {
            delete (verif);
            return (lib::printerr(RED, "ERROR: Value '", start[i], "' is too high, must be strictly smaller than ", State::size, " (Size * Size)"));
        }
    }

    for (int i = 0; i < State::size; ++i) if (!verif[i]) { delete (verif); return (lib::printerr(RED, "ERROR: Missing Value '", i, "'")); }

    delete (verif);
    return (false);
}

int     Puzzle::init()
{
    int     line_count(-1);
    string  line;

    if (get_length(line_count))
        return (1);
    
    State::size = State::length * State::length;

    if (init_goal())
        return (1);
    if (init_start(m_goal->getArray(), line_count))
        return (1);
    if (verif_start(m_start->getArray()))
        return (1);

    return (0);
}

