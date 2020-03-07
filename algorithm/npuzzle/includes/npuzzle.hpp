#ifndef NPUZZLE_HPP
# define NPUZZLE_HPP

# include <string>
# include <iostream>
# include <limits>
# include <iterator>
# include <sstream>
# include <algorithm>
# include <set>
# include <unordered_map>
# include <functional>
# include <regex>
# include <array>
# include <cmath>
# include <list>
# include <fstream>
# include <iomanip>

# include "../lib/includes/lib.hpp"

typedef enum {
	A_STAR,
	A_UNIFORM,
	A_GREEDY
} e_algorithm;

typedef enum {
	H_MANHATTAN,
	H_EUCLIDEAN,
	H_MISPLACED
} e_heuristic;

# include "../srcs/objects/State/State.hpp"
class State;

# include "../srcs/objects/Puzzle/Puzzle.hpp"
class Puzzle;

#endif