#include "npuzzle.hpp"

bool compare::operator() (State *a, State *b) const
{
    return (*a < *b);
}

int		main(void)
{
	Puzzle	puzzle;

	lib::printendl("===========================================");

	if (puzzle.init())
		return (1);

	lib::printendl("\n:: Length = ", State::length, "\n");

	lib::printendl(BOLD, "=====  Start =====");
	puzzle.getStart()->print();
	lib::printendl(":: Hash = ", puzzle.getStart()->getHash());
	lib::printendl(":: Score = ", puzzle.getStart()->getScore(), "\n");
	lib::printendl(":: ZeroPos = ", puzzle.getStart()->getZeroPosition(), "\n");

	lib::printendl(BOLD, "=====  Goal =====");
	puzzle.getGoal()->print();
	lib::printendl(":: Hash = ", puzzle.getGoal()->getHash());
	lib::printendl(":: Score = ", puzzle.getGoal()->getScore(), "\n");
	lib::printendl(":: ZeroPos = ", puzzle.getGoal()->getZeroPosition(), "\n");

	if (puzzle.isSolvable())
	{
		lib::printendl(GREEN, "SOLVABLE");
		//puzzle.solve();
	}
	else
		lib::printendl(RED, "NOT SOLVABLE");

	lib::printendl("===========================================");
	return (0);
}