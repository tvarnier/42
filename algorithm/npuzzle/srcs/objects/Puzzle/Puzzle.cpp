#include "Puzzle.hpp"

Puzzle::Puzzle() : m_start(new State()), m_goal(new State())
{}

Puzzle::~Puzzle()
{
    if (m_start)
        delete (m_start);
    if (m_goal)
        delete (m_goal);
    for (auto i = m_list.begin(); i != m_list.end(); ++i)
        delete (i->second);
}

// ----- Encapsulation ----- //

State           *Puzzle::getStart() const { return (m_start); }
void            Puzzle::setStart(State *start) { m_start = start; }

State           *Puzzle::getGoal() const { return (m_goal); }
void            Puzzle::setGoal(State *goal) { m_goal = goal; }

std::set<State*, compare> Puzzle::getQueue() const { return (m_queue); }
void            Puzzle::setQueue(const set<State*, compare>& queue) { m_queue = queue; }

std::unordered_map<size_t, State*> Puzzle::getList() const { return (m_list); }
void            Puzzle::setList(const std::unordered_map<size_t, State*>& list) { m_list = list; }
