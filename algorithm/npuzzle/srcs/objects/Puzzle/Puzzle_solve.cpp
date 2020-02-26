#include "puzzle.hpp"

struct isEqual
{
    State   *m_child;

    isEqual(State *child) : m_child(child) {}

    bool operator()(const State *a) const
    {
        return (*a == *m_child);
    }
};

static State    *generate_child(const State *current, int direction, const int *goal)
{
    State   *child = new State(*current);

    child->swapZeroPosition(direction);
    child->setNbrMoves(current->getNbrMoves() + 1);
    child->setHash();
    child->setScoreManhattan(goal);
    child->setParent((State*)current);

    return (child);
}

int     Puzzle::manage_sucessors(const State *current, int direction)
{
    std::unordered_map<size_t, State*>::iterator    it;
    std::set<State*, compare>::iterator             it_queue;
    State                                           *child;

    child = generate_child(current, direction, m_goal->getArray());

    if ((it = m_list.find(child->getHash())) == m_list.end())
    {
        m_queue.insert(child);
        m_list[child->getHash()] = child;
    }
    else
    {
        if (child->getScore() < it->second->getScore())
        {
            if (!(it->second->isDone()) && (it_queue = m_queue.find(it->second)) != m_queue.end())
                m_queue.erase(it_queue);
            m_queue.insert(it->second);
            *(it->second) = *child;
        }
        delete (child);
    }
    return (0);
}

int     Puzzle::generate_successors(const State *current)
{
    int     zero_position(current->getZeroPosition());

    // Up
    if (zero_position >= State::length)
        manage_sucessors(current, -State::length);
    // Down
    if (zero_position / State::length < State::length - 1)
        manage_sucessors(current, +State::length);
    // Left
    if (zero_position % State::length > 0)
        manage_sucessors(current, -1);
    // Right
    if (zero_position % State::length < State::length - 1)
        manage_sucessors(current, +1);
    return (0);
}

int         Puzzle::solve()
{
    State   *current;
    int     c(0);

    m_queue.insert(new State(*m_start));
    m_list[m_start->getHash()] = *(m_queue.begin());
    while (!m_queue.empty())
    {
        c++;
        current = *(m_queue.begin());
        m_queue.erase(m_queue.begin());
        current->setDone();

        if (c % 1000 == 0)
            lib::printendl("C :: ", c);

        if (*current == *m_goal)
        {
            lib::printendl(BOLD, GREEN, "----- WIN -----");
            lib::printendl("C :: ", c);
            current->print();
            return (0);
        }
        else
            // GENERATE CHILD
            generate_successors(current);
    }
    lib::printendl(BOLD, RED, "(Fail)");
    return (1);
}