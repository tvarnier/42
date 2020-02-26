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

# include "../lib/includes/lib.hpp"

# include "../srcs/objects/State/State.hpp"
class State;

struct compare {
    bool operator() (State *a, State *b) const;
};

# include "../srcs/objects/Puzzle/Puzzle.hpp"
class Puzzle;

#endif
