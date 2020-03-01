#include "Puzzle.hpp"

static int  zero_row_from_botom(const int& zero_pos)
{
    return (State::length - (zero_pos / State::length));
}

static bool is_inverted(const int *goal, const int& nbr1, const int& nbr2)
{
    int     nbr1_pos(0);
    int     nbr2_pos(0);

    for (int i = 0; i < State::size; ++i)
        if (goal[i] == nbr1)
        {
            nbr1_pos = i;
            break ;
        }
    for (int i = 0; i < State::size; ++i)
        if (goal[i] == nbr2)
        {
            nbr2_pos = i;
            break ;
        }
    return (nbr2_pos < nbr1_pos);
}

static int  inversion_number(const int *start, const int *goal)
{
    int     inv_nbr(0);

    for (int i = 0; i < State::size; ++i)
        if (start[i] != 0)
            for (int j = i + 1; j < State::size; ++j)
                if ( start[j] != 0 && is_inverted(goal, start[i], start[j]))
                    ++inv_nbr;
    return (inv_nbr);
}

bool    Puzzle::isSolvable()
{
    if (m_infos.initalize == false)
    {
        lib::printerr(RED, "ERROR : The puzzle isn't initialize");
        return (0);
    }

    if (State::length % 2 == 1)
    {
        if (inversion_number(m_start->getArray(), m_goal->getArray()) % 2 == 0)
            return (true);
    }
    else if (State::length % 4 == 0)
    {
        if ((zero_row_from_botom(m_start->getZeroPosition()) % 2 == 0 && inversion_number(m_start->getArray(), m_goal->getArray()) % 2 == 0)
            || (zero_row_from_botom(m_start->getZeroPosition()) % 2 == 1 && inversion_number(m_start->getArray(), m_goal->getArray()) % 2 == 1))
            return (true);
    }
    else
    {
        if ((zero_row_from_botom(m_start->getZeroPosition()) % 2 == 0 && inversion_number(m_start->getArray(), m_goal->getArray()) % 2 == 1)
            || (zero_row_from_botom(m_start->getZeroPosition()) % 2 == 1 && inversion_number(m_start->getArray(), m_goal->getArray()) % 2 == 0))
            return (true);
    }

    return (0);
}