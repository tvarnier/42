#ifndef PUZZLE_HPP
# define PUZZLE_HPP

# include "npuzzle.hpp"

struct compare {
    bool operator() (State *a, State *b) const;
};

enum e_goal {
    T_SNAIL,
    T_ORDERED,
    T_FILE
};

typedef struct s_puzzleOptions {
    e_algorithm algorithm;
    e_heuristic heuristic;
    bool        generation;
    int         generation_length;
    int         generation_iteration;
    e_goal      goal_type;
    std::string goal_file;
    bool        visualizer;
} puzzleOptions;

typedef struct s_puzzleInfos {
    int                 state_selected;
    int                 max_state_memory;
    int                 number_steps;
    std::list<State*>   steps;
    bool                initalize;
} puzzleInfos;

class Puzzle
{
    public :
        Puzzle();
        ~Puzzle();

        void    reset();

        int     parseOptions(const int& ac, char **av);
        int     init(); // Parse entry and init Start and Goal
        bool    isSolvable();
        int     solve(); // Try to solve the Puzzle

        // ----- Encapsulation ----- //

        e_algorithm     getAlgorithm() const;
        void            setAlgorithm(const e_algorithm& algorithm);

        e_heuristic     getHeuristic() const;
        void            setHeuristic(const e_heuristic& heuristic);

        bool            isGenerate() const;
        int             getGenerationLenght() const;
        int             getGenerationIteration() const;
        void            setGeneration(const bool& has_generation, const int& generation_length, const int& generation_iteration = 10000);

        e_goal          getGoalType() const;
        std::string     getGoalFile() const;
        void            setTarget(const e_goal& goal_type, const std::string& goal_file = "");

        bool            isVisualized() const;
        void            setVisualizer(const bool& visualize);
        
        int             getNumberStateSelected() const;
    
        int             getMaxStateInMemory() const;

        int             getNumberSteps() const;

        std::list<State*>   getSteps() const;

        bool            isInitialized() const;

        State           *getStart() const;

        State           *getGoal() const;

        std::set<State*, compare> getQueue() const;

        std::unordered_map<size_t, State*> getList() const;

    private :
        State                               *m_start;
        State                               *m_goal;
        std::set<State*, compare>           m_queue;
        std::unordered_map<size_t, State*>  m_list;
        puzzleOptions                       m_options;
        puzzleInfos                         m_infos;


        int     init_start(const int *goal, int& line_count);
        int     *generate_start_array(int *start, const int *goal);
        int     init_goal();
        int     init_goal_snail(int *goal);
        int     init_goal_ordered(int *goal);
        int     init_goal_file(int *goal);

        int     generate_successors(const State *current);
        int     manage_sucessors(const State *current, int direction);
};

# endif