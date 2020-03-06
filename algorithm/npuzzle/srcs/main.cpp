#include "npuzzle.hpp"

int		main(int ac, char **av)
{
	Puzzle	puzzle;

	lib::printendl("===========================================");

	if (puzzle.parseOptions(ac, av))
		return (1);

	if (puzzle.init())
		return (1);

	lib::printendl("\n:: Length = ", puzzle.getLength(), "\n");

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
		puzzle.solve();
	}
	else
		lib::printendl(RED, "NOT SOLVABLE");

	lib::printendl("===========================================");
	return (0);
}