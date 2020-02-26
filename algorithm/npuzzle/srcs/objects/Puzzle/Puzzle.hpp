#ifndef PUZZLE_HPP
# define PUZZLE_HPP

# include "npuzzle.hpp"

class Puzzle
{
    public :
        Puzzle();
        ~Puzzle();

        int     init(); // Parse entry and init Start and Goal
        bool    isSolvable();
        int     solve(); // Try to solve the Puzzle

        // ----- Encapsulation ----- //

        State           *getStart() const;
        void            setStart(State *start);

        State           *getGoal() const;
        void            setGoal(State *goal);

        std::set<State*, compare> getQueue() const;
        void            setQueue(const set<State*, compare>& queue);

        std::unordered_map<size_t, State*> getList() const;
        void            setList(const std::unordered_map<size_t, State*>& list);

    private :
        State                               *m_start;
        State                               *m_goal;
        std::set<State*, compare>           m_queue;
        std::unordered_map<size_t, State*>  m_list;

        int     init_start(const int *goal, int& line_count);
        int     init_goal();

        int     generate_successors(const State *current);
        int     manage_sucessors(const State *current, int direction);
};

# endif