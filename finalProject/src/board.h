#pragma once

#include <vector>
#include "ofMain.h"
using std::vector;

class Board {

public:
	/**
	 * Store the value and position of each tile in the board using a Tile struct.
	**/
	struct Tile {
		size_t value;
		size_t board_position;
	};

	/**
	 * Initialize global varaibles for a new game.
	**/
	void SetUpGame();
	/**
	 * Compare two boards to check if they are equal.
	**/
	bool AreBoardsEqual(Tile initial[4][4], Tile copy[4][4]);
	/**
	 * Number the board positions and set the starting values.
	**/
	void InitBoard();
	/**
	 * Change a random empty tile's value to 2.
	**/
	void SpawnNewTwo(vector<size_t> &possible_positions);
	/**
	 * Find all positions on the board where value is 0.
	**/
	vector<size_t> FindEmptyPositions();
	/**
	 * Number the board positions and set each value to 0;
	**/
	void InitCopy();
	/**
	 * Copy the tile values from one board to another.
	**/
	void CopyBoard(Tile initial[4][4], Tile copy[4][4]);
	/**
	 * Check if the player has lost the game.
	**/
	bool HasLost();
	/**
	 * Reset the board so it only maintains the highest value from before.
	**/
	void ResurrectPlayer();
	/**
	 * Check if the player has won.
	**/
	void UpdateHasWon(size_t value);
	/**
	 * Check what the highest value on the board is. 
	**/
	void UpdateHighestValue(size_t value);
	/**
	 * Add new tile values to the score.
	**/
	void UpdateScore(size_t value);
	/**
	 * Compress the tiles in one direction to eliminate zeroes between nonzero values.
	**/
	void CompressLeft();

	void CompressRight();

	void CompressDown();

	void CompressUp();
	/**
	 * Merge the tiles in one direction so that adjacent values are summed.
	**/
	void MergeLeft();

	void MergeUp();

	void MergeRight();

	void MergeDown();
	/**
	 * A 4 by 4 array of tiles which are manipulated to play the game.
	**/
	Tile board_[4][4];
	/**
	 * A copy of the board. 
	 * The board is comapred to the copy to see if a move changed the board,
	 * and by extension if new 2s need to spawned.
	**/
	Tile board_copy_[4][4];
	/**
	 * The player's score
	**/
	size_t score_ = 0;
	/**
	 * This variable is flipped once the player has won.
	**/
	bool has_won_ = false;
	/**
	 * The dimension of the game board.
	**/
	const size_t kBoardDimension = 4;

private: 
	/**
	 * Randomly return either 2 or 4.
	**/
	size_t ChooseTwoOrFour(); 
	/**
	 * There are sixteen tiles on a 4 x 4 board.
	**/
	const size_t kNumOfTiles = 16;
	/**
	 * The first number on the board is 2.
	**/
	const size_t kStartingNumber1 = 2;
	/**
	 * 4 is two squared.
	**/
	const size_t kStartingNumber2 = 4;
	/**
	 * The player wins when this value is reached.
	**/
	const size_t kWinningNumber = 2048;
	/**
	 * Maintains the highest value on the board.
	**/
	size_t highest_value = 2;
	/**
	 * The position of the tile where the highest value lies.
	**/
	size_t position_of_highest_value = 0;
};