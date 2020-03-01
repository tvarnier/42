#include "Puzzle.hpp"

#include <stdlib.h>
#include <time.h>

static int     generate_number(const int& from, const int& to)
{
    srand (time(NULL));
    return (rand() % to + from);
}

static int     count_possibities(const int& zero, const int& last)
{
    int     count(0);
    if (last != +State::length && zero >= State::length) ++count;
    if (last != -State::length && zero / State::length < State::length - 1) ++count;
    if (last != +1 && zero % State::length > 0) ++count;
    if (last != -1 && zero % State::length < State::length - 1) ++count;
    return (count);
}

void    swap_values(int *start, int& zero, int& last, const int& where)
{
    start[zero] = start[zero + where];
	start[zero + where] = 0;
	zero = zero + where;
    last = where;
}

int     *Puzzle::generate_start_array(int *start, const int *goal)
{
    int     zero(0);
    int     possibilities(0);
    int     rdm;
    int     last(0);

    for (int i = 0; i < State::size; ++i) start[i] = goal[i];
    zero = m_goal->getZeroPosition();

    lib::printendl(" :: ", m_options.generation_iteration);

    for (int i = m_options.generation_iteration; i > 0; --i)
    {
        possibilities = count_possibities(zero, last);
        rdm = generate_number(1, possibilities);
        if (last != +State::length && zero >= State::length && !(--rdm))
            swap_values(start, zero, last, -State::length);
        else if (last != -State::length && zero / State::length < State::length - 1 && !(--rdm))
            swap_values(start, zero, last, +State::length);
        else if (last != +1 && zero % State::length > 0 && !(--rdm))
            swap_values(start, zero, last, -1);
        else if (last != -1 && zero % State::length < State::length - 1 && !(--rdm))
            swap_values(start, zero, last, +1);
    }
    return (start);
}