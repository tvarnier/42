#ifndef PUZZLE_HPP
# define PUZZLE_HPP

# include "npuzzle.hpp"

/*****
** Compare function for Queue
*****/
struct compare {
    bool operator() (State *a, State *b) const;
};

/*****
** Target Type Enumeration
*****/
enum e_target {
    T_SNAIL,
    T_ORDERED,
    T_RANDOM,
    T_FILE
};

/*****
** Options structure
*****/
typedef struct s_puzzleOptions {
    e_algorithm algorithm;              // Algorithm selected
    e_heuristic heuristic;              // Heuristic selected
    bool        generation;             // Is Generated
    int         generation_length;      // Generation length
    int         generation_iteration;   // Generation iteration
    e_target    target_type;            // Type of Target
    std::string target_file;            // File if Target Type = T_FILE
    bool        visualizer;             // Is visualized
} puzzleOptions;

/*****
** Informations structure
*****/
typedef struct s_puzzleInfos {
    int                 state_selected;     // Number of state selected
    int                 max_state_memory;   // Number of state maximum in memory
    int                 number_steps;       // Number of steps to get from Start to Target
    std::list<State*>   steps;              // List of steps to get from Start to Target
    bool                initalize;          // Is Puzzle initialized
    int                 length;             // Length of Puzzle
    int                 size;               // Size of Puzzle (length * length)
} puzzleInfos;

class Puzzle
{
    public :
        Puzzle();   // Constructor
        ~Puzzle();  // Destructor

        void    reset();

        int     parseOptions(const int& ac, char **av); // Parse arguments of the program and Modify Puzzle informations
        int     init();                                 // Intialize Puzzle (Necessary to isSolvable and solve)
        bool    isSolvable();                           // Check if Puzzle is Solvable
        int     solve();                                // Try to solve the Puzzle

        // ----- Encapsulation ----- //

        e_algorithm     getAlgorithm() const;
        void            setAlgorithm(const e_algorithm& algorithm);

        e_heuristic     getHeuristic() const;
        void            setHeuristic(const e_heuristic& heuristic);

        bool            isGenerate() const;
        int             getGenerationLenght() const;
        int             getGenerationIteration() const;
        void            setGeneration(const bool& has_generation, const int& generation_length, const int& generation_iteration = 10000);

        e_target        getTargetType() const;
        std::string     getTargetFile() const;
        void            setTarget(const e_target& target_type, const std::string& target_file = "");

        bool            isVisualized() const;
        void            setVisualizer(const bool& visualize);
        
        int             getNumberStateSelected() const;
    
        int             getMaxStateInMemory() const;

        int             getNumberSteps() const;

        std::list<State*>   getSteps() const;

        int             getLength() const;
        int             getSize() const;

        bool            isInitialized() const;

        State           *getStart() const;

        State           *getTarget() const;

        std::set<State*, compare> getQueue() const;

        std::unordered_map<size_t, State*> getList() const;

    private :
        State                               *m_start;   // Start State
        State                               *m_target;  // Target State
        std::set<State*, compare>           m_queue;    // Queue of non analized States (Open)
        std::unordered_map<size_t, State*>  m_list;     // All unique States Generated 
        puzzleOptions                       m_options;  // Puzzle Options
        puzzleInfos                         m_infos;    // Puzzle infos


        int     init_start(const int *target, int& line_count);         // Intialize Start
        int     *generate_start_array(int *start, const int *target);   // Generate Random Start Array
        int     init_target();                                          // Intialize Target
        void    init_target_snail(int *target);                         // Intialize Target Array to Snail form
        void    init_target_ordered(int *target);                       // Intialize Target Array to Ordered form
        void    init_target_random(int *target);                        // Intialize Target Array to Random form
        int     init_target_file(int *target);                          // Intialize Target Array from file

        void    generate_successors(const State *current);              // Try to Create Successor in all 4 directions
        void    manage_sucessor(const State *current, int direction);   // Create Successor State and Manage it
};

# endif