#include "State.hpp"

int     State::length = 0;
int     State::size = 0;

// ----- Constructors ----- //

State::State() : m_array(new int[size]), m_zeroPosition(-1), m_score(-1), m_nbrMoves(0), m_hash(), m_parent(nullptr), m_done(false)
{}
State::State(const State& other) : m_zeroPosition(other.m_zeroPosition), m_score(other.m_score), m_nbrMoves(other.m_nbrMoves), m_hash(other.m_hash), m_parent(other.m_parent), m_done(other.m_done)
{
    m_array = new int[size];
    copy(other.m_array, other.m_array + size, m_array);
}

State::~State() { delete (m_array); }

// ----- Encapsulation ----- //

int		*State::getArray() const { return (m_array); }
void	State::setArray(int *array) { delete (m_array); m_array = array; }

int		State::getZeroPosition() const { return (m_zeroPosition); }
void	State::setZeroPosition(const int& zero_position) { m_zeroPosition = zero_position; }

int		State::getScore() const { return (m_score); }
void	State::setScore(const int *goal, const e_heuristic& h, const e_algorithm& a)
{
	m_score = 0;

	if (a == A_STAR || a == A_UNIFORM)
	{
		if (h == H_MANHATTAN)
			m_score += scoreManhattan(goal);
		else if (h == H_EUCLIDEAN)
			m_score += scoreEuclidean(goal);
		else if (h == H_MISPLACED)
			m_score += scoreMisplaced(goal);
	}
	if (a == A_STAR || a == A_GREEDY)
		m_score += m_nbrMoves;
}

int		State::getNbrMoves() const { return (m_nbrMoves); }
void	State::setNbrMoves(const int& nbr_moves) { m_nbrMoves = nbr_moves; }

size_t	State::getHash() const { return (m_hash); }
void	State::setHash() { m_hash = State::hashArray(); }

State   *State::getParent() const { return (m_parent); }
void	State::setParent(State *parent) { m_parent = parent; }

bool	State::isDone() const { return (m_done); }
void	State::setDone() { m_done = true; }

// ----- Operator Overload ----- //

State   &State::operator=(const State& other)
{
    m_zeroPosition = other.m_zeroPosition;
    m_score = other.m_score;
    m_nbrMoves = other.m_nbrMoves;
	m_hash = other.m_hash;
    m_parent = other.m_parent;
	m_done = other.m_done;
    copy(other.m_array, other.m_array + size, m_array);
    return (*this);
}

bool	operator==(const State& a, const State& b) { return (a.getHash() == b.getHash() && a.getZeroPosition() == b.getZeroPosition()); }
bool	operator!=(const State& a, const State& b) { return !(a == b); }
bool	operator<(const State& a, const State& b) { return (a.getScore() < b.getScore() || (a.getScore() == b.getScore() && a.getNbrMoves() < b.getNbrMoves()) || (a.getScore() == b.getScore() && a != b)); }


////////////////////////////////////////////
/////// ----- Public Functions ----- ///////
////////////////////////////////////////////

void    State::print() const { lib::print(array_to_string()); }

void	State::swapZeroPosition(const int& n)
{
	m_array[m_zeroPosition] = m_array[m_zeroPosition + n];
	m_array[m_zeroPosition + n] = 0;
	m_zeroPosition = m_zeroPosition + n;
}

/////////////////////////////////////////////
/////// ----- Private Functions ----- ///////
/////////////////////////////////////////////

std::string State::array_to_string() const
{
	std::string	        s;
	std::ostringstream	s_flux;

	for (int i = 0; i < State::size; ++i)
	{
		if (m_array[i])
				s_flux << m_array[i] << " ";
		else
			s_flux << "_ ";
		if (i % State::length == State::length - 1)
			s_flux << "\n";
	}
	s = s_flux.str();
	return (s);
}

size_t	State::hashArray()
{
	std::hash<string>	hash;
	string				s;
	ostringstream		os;

	for (int i = 0; i < State::size; ++i)
		os << m_array[i];

	s = os.str();
	return (hash(s)); 
}

// ----- Heuristics ----- //

int		State::scoreManhattan(const int *goal)
{
	int		i;
	int		j;
	int		score(0);

	for(i = 0; i < State::size; ++i)
		if (m_array[i] != 0)
		{
			for (j = 0; m_array[i] != goal[j] && j < State::size; ++j);
			score += std::abs((j / State::length) - (i / State::length)) * 2;
			score += std::abs((j % State::length) - (i % State::length)) * 2;
		}
	return (score);
}

int		State::scoreEuclidean(const int *goal)
{
	int		i;
	int		j;
	int		score(0);

	for(i = 0; i < State::size; ++i)
		if (m_array[i] != 0)
		{
			for (j = 0; m_array[i] != goal[j] && j < State::size; ++j);
			score += std::sqrt(std::pow(((double)(i / State::length) - (double)(j / State::length)), 2.0) + std::pow(((double)(i % State::length) - (double)(j % State::length)), 2.0)) * 2.0;
		}
	return (score);
}

int 	State::scoreMisplaced(const int *goal)
{
	int		i;
	int		j;
	int		row;
	int		col;
	int		score(0);

	for(i = 0; i < State::size; ++i)
		if (m_array[i] != 0)
		{
			row = i / State::length;
			col = i % State::length;

			for (j = 0; j < State::length; ++j) if (goal[row * State::length + j] == m_array[i]) break ;
			if (j == State::length) score += 2;
			for (j = 0; j < State::length; ++j) if (goal[j * State::length + col] == m_array[i]) break ;
			if (j == State::length) score += 2;
		}
	return (score);
}