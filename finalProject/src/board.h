#pragma once

#include <vector>
#include "ofMain.h"
using std::vector;

/**
 * class to store and manipulate the state of the 2048 game board.
 */
class Board {

public:
	/**
	 * Store the value and position of each tile in the board using a Tile struct.
	*/
	struct Tile {

		/**
		  * Either 0 or a power of 2 ranging from 2^1 to 2^11.
		 */
		size_t value;

		/**
		 * A value ranging from 1 - 16 corresponding to tile's position in the board.
		*/
		size_t board_position;
	};

	/**
	 * Initialize global varaibles for a new game.
	*/
	void SetUpGame(); 

	/**
	 * Compare two boards to check if they are equal.
	 * @param - initial - the initial board
	 * @param - copy - the array that the board is copied to
	 * @return - bool representing whether the two bools passed are equal
	*/
	bool AreBoardsEqual(Tile initial[4][4], Tile copy[4][4]);

	/**
	 * Number the board positions and set the starting values.
	*/
	void InitBoard();

	/** 
	 * Randomly select an empty position on the board and spawn a new two in its place.
	 * @param- vector<size_t> &possible_positions - with values coressponding to positions of the empty tiles on the board.
	*/
	void SpawnNewTwo(vector<size_t> &possible_positions);

	/**
	 * Find all positions on the board where value is 0.
	 * @return - vector<size_t> - with values coressponding to positions of the tiles on the board
	*/
	vector<size_t> FindEmptyPositions();

	/**
	 * Number the board positions and set each value to 0.
	*/
	void InitCopy();

	/**
	 * Copy the tile values from one board to another.
	 * @param - initial - the initial board.
	 * @param - copy - the array that the board is copied to.
	*/
	void CopyBoard(Tile initial[4][4], Tile copy[4][4]);

	/**
	 * Check if the player has lost the game.
	 * @return - bool representing whether the player has lost.
	*/
	bool HasLost();

	/**
	 * Reset the board so it only maintains the highest value from before.
	*/
	void ResurrectPlayer();

	/**
	 * Check if the player has won.
	 * @param - value - the value of a specific tile in the board.
	*/
	void UpdateHasWon(size_t value);

	/**
	 * Check what the highest value on the board is.
	 * @param - value - the value of a specific tile in the board.
	*/
	void UpdateHighestValue(size_t value);

	/**
	 * Add new tile values to the score.
	 * @param - value - the value of a specific tile in the board.
	*/
	void UpdateScore(size_t value);

	/**
	 * Move all the tiles leftwards so that no zeroes lie between nonzero values.
	*/
	void CompressLeft();

	/**
	 * Move all the tiles rightwards so that no zeroes lie between nonzero values.
	 */
	void CompressRight();

	/**
	 * Move all the tiles downwards so that no zeroes lie between nonzero values.
	*/
	void CompressDown();

	/**
	 * Move all the tiles upwards so that no zeroes lie between nonzero values.
	*/
	void CompressUp();

	/**
	 * Merge values of tiles leftwards so that adjacent values are summed.
	 * Compress them again.
	*/
	void MergeLeft();

	/**
	 * Merge values of tiles upwards so that adjacent values are summed.
	 * Compress them again.
	*/
	void MergeUp();

	/**
	 * Merge values of tiles rightwards so that adjacent values are summed.
	 * Compress them again.
	*/
	void MergeRight();

	/**
	 * Merge values of tiles downwards so that adjacent values are summed.
	 * Compress them again.
	*/
	void MergeDown();

	/**
	 * A 4 by 4 array of tiles which are manipulated to play the game.
	*/
	Tile board_[4][4];

	/**
	 * A copy of the board. 
	 * The board is comapred to the copy to see if a move changed the board,
	 * and by extension if new 2s need to spawned.
	*/
	Tile board_copy_[4][4];

	/**
	 * The player's score
	*/
	size_t score_ = 0;

	/**
	 * This variable is flipped once the player has won.
	*/
	bool has_won_ = false;

	/**
	 * The dimension of the game board.
	*/
	const size_t kBoardDimension = 4;

private: 
	/**
	 * Randomly return either 2 or 4.
	 * @return - size_t.
	*/
	size_t ChooseTwoOrFour();

	/**
	 * There are sixteen tiles on a 4 x 4 board.
	*/
	const size_t kNumOfTiles = 16;

	/**
	 * The first number on the board is 2.
	*/
	const size_t kStartingNumber1 = 2;

	/**
	 * 4 is two squared.
	*/
	const size_t kStartingNumber2 = 4;

	/**
	 * The player wins when this value is reached.
	*/
	const size_t kWinningNumber = 2048;

	/**
	 * Maintains the highest value on the board.
	*/
	size_t highest_value = 2;

	/**
	 * The position of the tile where the highest value lies.
	*/
	size_t position_of_highest_value = 0;
};