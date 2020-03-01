#ifndef STATE_HPP
# define STATE_HPP

# include "npuzzle.hpp"

class State
{
	public :
		static int	length;
		static int	size;

		State();
		State(const State& other);
		~State();

		void	print() const; // Print Array

		void	swapZeroPosition(const int& n);

		// ----- Encapsulation ----- //

		int		*getArray() const;
		void	setArray(int *array);

		int		getZeroPosition() const;
		void	setZeroPosition(const int& zero_position);

		int		getScore() const;
		void	setScore(const int *goal, const e_heuristic& h = H_MANHATTAN, const e_algorithm& a = A_STAR);

		int		getNbrMoves() const;
		void	setNbrMoves(const int& nbr_moves);

		size_t	getHash() const;
		void	setHash();

		State	*getParent() const;
		void	setParent(State *parent);

		bool	isDone() const;
		void	setDone();

		State	&operator=(const State& other);

	private :
		int				*m_array;
		int				m_zeroPosition;
		int				m_score;
		int				m_nbrMoves;
		size_t 			m_hash;
		State			*m_parent;
		bool			m_done;

		std::string		array_to_string() const;
		size_t			hashArray();

		// ----- Heuristic ----- //

		int		scoreManhattan(const int *goal);
		int		scoreEuclidean(const int *goal);
		int		scoreMisplaced(const int *goal);
};

bool	operator==(const State& a, const State& b);
bool	operator!=(const State& a, const State& b);
bool	operator<(const State& a, const State& b);

#endif