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

static State    *generate_child(const State *current, int direction, const int *goal, const e_heuristic& heuristic, const e_algorithm& algorithm)
{
    State   *child = new State(*current);

    child->swapZeroPosition(direction);
    child->setNbrMoves(current->getNbrMoves() + 1);
    child->setHash();
    child->setScore(goal, heuristic, algorithm);
    child->setParent((State*)current);

    return (child);
}

int     Puzzle::manage_sucessors(const State *current, int direction)
{
    std::unordered_map<size_t, State*>::iterator    it;
    std::set<State*, compare>::iterator             it_queue;
    State                                           *child;

    child = generate_child(current, direction, m_goal->getArray(), m_options.heuristic, m_options.algorithm);

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
    if (zero_position >= m_infos.length)
        manage_sucessors(current, -m_infos.length);
    // Down
    if (zero_position / m_infos.length < m_infos.length - 1)
        manage_sucessors(current, +m_infos.length);
    // Left
    if (zero_position % m_infos.length > 0)
        manage_sucessors(current, -1);
    // Right
    if (zero_position % m_infos.length < m_infos.length - 1)
        manage_sucessors(current, +1);
    return (0);
}

static void generate_steps(State *current, std::list<State*>& steps, int& number_steps)
{
    State   *tmp;

    tmp  = current;

    while (tmp != nullptr)
    {
        steps.push_front(tmp);
        tmp = tmp->getParent();
    }
    number_steps = steps.size() - 1;
}

void print_steps(std::list<State*>& step)
{
    std::list<State*>::iterator it(step.begin());
    std::list<State*>::iterator end(step.end());

    while (it != end)
    {
        lib::printendl("=========================");
        (*it)->print();
        ++it;
    }
}

int         Puzzle::solve()
{
    State   *current;

    if (m_infos.initalize == false)
        return (lib::printerr(RED, "ERROR : The puzzle isn't initialize"));

    m_queue.insert(new State(*m_start));
    m_list[m_start->getHash()] = *(m_queue.begin());
    while (!m_queue.empty())
    {
        ++m_infos.state_selected;
        current = *(m_queue.begin());
        m_queue.erase(m_queue.begin());
        current->setDone();

        if (m_infos.state_selected % 1000 == 0)
            lib::printendl("C :: ", m_infos.state_selected);

        if (*current == *m_goal)
        {
            m_infos.max_state_memory = m_list.size();
            lib::printendl(BOLD, GREEN, "----- WIN -----");
            lib::printendl("C :: ", m_infos.state_selected);
            current->print();

            generate_steps(current, m_infos.steps, m_infos.number_steps);
            lib::printendl("STEPS :: ", m_infos.number_steps);
            //print_steps(m_steps);
            return (0);
        }
        else
            // GENERATE CHILD
            generate_successors(current);
    }
    lib::printendl(BOLD, RED, "(Fail)");
    return (1);
}