#pragma once

#include "board.h"

/** 
 * Initialize the board at the beginning of the game to be empty with only two tiles. 
 * One tile has the value 2, the other one has the value 2 or 4. 
 * Number the board position of each tile.
 */
void Board::InitBoard() {
	// Select a random position for the first tile.
	int first_tile_position = rand() % kNumOfTiles + 1;
	int second_tile_position = rand() % kNumOfTiles + 1;

	// Ensure that the second tile position is not the same as the first.
	while (second_tile_position == first_tile_position) {
		second_tile_position = rand() % kNumOfTiles + 1;
	}
	// Randomly select the value of the second tile to be two or four.
	int second_tile_value = ChooseTwoOrFour();
	
	int board_position = 1;
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			// Traverse through the board and initialize each value to be 0 unless it is the first or second tile.
			if (board_position == first_tile_position) {
				board_[i][j].value = kStartingNumber1;

			} else if (board_position == second_tile_position) {
				board_[i][j].value = second_tile_value;

			} else {
				board_[i][j].value = 0;
			}
			board_[i][j].board_position = board_position;
			board_position++;
		}
	}
}

/**
 * Return a vector of positions in the board where the value is 0 (essentially, that position is 'empty').
*/
vector<size_t> Board::FindEmptyPositions() {
	vector<size_t> possible_postions;
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			if (board_[i][j].value == 0) {
				possible_postions.push_back(board_[i][j].board_position);
			}
		}
	}
	return possible_postions;
}

/** 
 * Move all the tiles leftwards so that no zeroes lie between nonzero values.
*/
void Board::CompressLeft() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			if (board_[i][j].value == 0) {
				for (int k = j + 1; k < kBoardDimension; k++) {
					// If a tile value is zero, and the tile to the right is not zero, 
					// change the first tile's value to that of the second tile, and the second tile's value to 0.
					if (board_[i][k].value != 0) {
						board_[i][j].value = board_[i][k].value;
						board_[i][k].value = 0;
						break;
					}
				}
			}
		}
	}
}

/**
 * Merge values of tiles leftwards.
 */
void Board::MergeLeft() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension - 1; j++) {
			// If the tile value doesn't equal zero and the tile to the right of it has the value zero, 
			// the value of the first tile equals their sum and the value of the second tile becomes zero.
			if (board_[i][j].value != 0 && board_[i][j].value == board_[i][j + 1].value) {

				board_[i][j].value += board_[i][j + 1].value;
				board_[i][j + 1].value = 0;

				UpdateScore(board_[i][j].value);
				UpdateHighestValue(board_[i][j].value);
				UpdateHasWon(board_[i][j].value);
			}
		}
	}
	// Compress the tiles again to eliminate any new zeroes.
	CompressLeft();
}

/**
 * Move all the tiles upwards so that no zeroes lie between nonzero values.
*/
void Board::CompressUp() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			// If a tile value is zero, and the tile below it is not zero, 
			// change the first tile's value to that of the second tile, and the second tile's value to 0.
			if (board_[j][i].value == 0) {
				for (int k = j + 1; k < kBoardDimension; k++) {
					if (board_[k][i].value != 0) {
						board_[j][i].value = board_[k][i].value;
						board_[k][i].value = 0;
						break;
					}
				}
			}
		}
	}
}

/** 
 * Merge values of tiles upwards.
*/
void Board::MergeUp() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			// If the tile value doesn't equal zero and the tile below it has the value zero.
			// the value of the first tile equals their sum and the value of the second tile becomes zero.
			if (board_[j][i].value != 0 && board_[j][i].value == board_[j + 1][i].value) {
				
				board_[j][i].value += board_[j + 1][i].value;
				board_[j + 1][i].value = 0;

				UpdateScore(board_[j][i].value);
				UpdateHasWon(board_[j][i].value);
				UpdateHighestValue(board_[j][i].value);
			}
		}
	}
	// Compress the tiles again to eliminate any new zeroes.
	CompressUp();
}

// Move all the tiles rightwards so that no zeroes lie between nonzero values.
void Board::CompressRight() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = kBoardDimension - 1; j >= 0; j--) {
			// If a tile value is zero, and the tile to the left is not zero, change the first tile's value to that of the second tile, and the second tile's value to 0.
			if (board_[i][j].value == 0) {
				for (int k = j - 1; k >= 0; k--) {
					if (board_[i][k].value != 0) {
						board_[i][j].value = board_[i][k].value;
						board_[i][k].value = 0;
						break;
					}
				}
			}
		}
	}
}

/** 
 * Merges values of tiles rightwards.
*/
void Board::MergeRight() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = kBoardDimension - 1; j > 0; j--) {
			// If the tile value doesn't equal zero and the tile to the left of it has the value zero,
			// the value of the first tile equals their sum and the value of the second tile becomes zero.
			if (board_[i][j].value != 0 && board_[i][j].value == board_[i][j - 1].value) {
				
				board_[i][j].value += board_[i][j - 1].value;
				board_[i][j - 1].value = 0;

				UpdateScore(board_[i][j].value);
				UpdateHasWon(board_[i][j].value);
				UpdateHighestValue(board_[i][j].value);
			}
		}
	}
	// Compress the tiles again to eliminate any new zeroes.
	CompressRight();
}

/**
 * Move all the tiles downwards so that no zeroes lie between nonzero values.
*/
void Board::CompressDown() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = kBoardDimension - 1; j >= 0; j--) {
			if (board_[j][i].value == 0) {
				// If a tile value is zero, and the tile above it is not zero 
				// change the first tile's value to that of the second tile, and the second tile's value to 0.
				for (int k = j - 1; k >= 0; k--) {
					if (board_[k][i].value != 0) {
						board_[j][i].value = board_[k][i].value;
						board_[k][i].value = 0;
						break;
					}
				}
			}
		}
	}
}

/** 
 * Merge values of tiles downwards.
*/
void Board::MergeDown() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = kBoardDimension - 1; j > 0; j--) {
			// If the tile value doesn't equal zero and the tile above it has the value zero, 
			// the value of the first tile equals their sum and the value of the second tile becomes zero.
			if (board_[j][i].value != 0 && board_[j][i].value == board_[j - 1][i].value) {
				
				board_[j][i].value += board_[j - 1][i].value;
				board_[j - 1][i].value = 0;

				UpdateScore(board_[j][i].value);
				UpdateHasWon(board_[j][i].value);
				UpdateHighestValue(board_[j][i].value);
			}
		}
	}
	// Compress the tiles again to eliminate any new zeroes.
	CompressDown();
}

/**
 * Initialize the positions in the copy board and set every value to 0;
*/
void Board::InitCopy() {
	int counter = 1;
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			board_copy_[i][j].board_position = counter;
			board_copy_[i][j].value = 0;
			counter++;
		}
	}
}

/** 
 * Copy the values from the initial board to the copy board.
*/
void Board::CopyBoard(Tile initial[4][4], Tile copy[4][4]) {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			copy[i][j].value = initial[i][j].value;
		}
	}
}

/** 
 * Compare each value in the initial board to the copy to see if they are equal.
 * This method is used to determine if a move actaully affected the board in any way.
*/
bool Board::AreBoardsEqual(Tile initial[4][4], Tile copy[4][4]) { 
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			if (copy[i][j].value != initial[i][j].value) {
				return false;
			}
		}
	}
	return true;
}

/**
 * Determine whether the player has lost the game.
 * If there are empty position(s) on the board, the player has NOT lost.
 * If any two tiles that are vertically or horizontally adjacent have the same value, the player has NOT lost.
 * If neither of those conditions are met, the player has won
*/
bool Board::HasLost() {
	if (!FindEmptyPositions().empty()) { 
		return false;
	}
	for (int i = 0; i < kBoardDimension; i++) { 
		for (int j = 0; j < kBoardDimension; j++) {
			// Use kBoardDimension - 1 to prevent an out-of-bounds error.
			// If the tile has the same value as the tile to its right or the tile below it, the player has NOT lost.
			if ((j < kBoardDimension - 1 && board_[i][j].value == board_[i][j + 1].value) || (i < kBoardDimension - 1 && board_[i][j].value == board_[i + 1][j].value))  {
				return false;
			}
		}
	}
	// The player has lost.
	return true;
}

/**
 * Resurrect the player by retaining the highest value(s) and changing all other tile values to 0;
 * Spawn a new two to get the player started.
*/
void Board::ResurrectPlayer() {
	for (int i = 0; i < kBoardDimension; i++) { 
		for (int j = 0; j < kBoardDimension; j++) {
			if (board_[i][j].value != highest_value) {
				board_[i][j].value = 0;
			}
		}
	}
	SpawnNewTwo(FindEmptyPositions());
}

/**
 * If the the value equals the winning number, the player has won.
*/
void Board::UpdateHasWon(size_t value) { 
	if (value == kWinningNumber) {
		has_won_ = true;
	}
}

/**
 * If the the value exceeds the highest value on the board, the variable is updated.
*/
void Board::UpdateHighestValue(size_t value) {
	if (value > highest_value) {
		highest_value = value;
	}
}

/**
 * Update the score variable.
 * Add the value of the new tile times a multiplier.
*/
void Board::UpdateScore(size_t value) {
	score_ += ((log2(value)) - 1) * value;
}

/**
 * Set up the game by initiating a new board and copy.
 * Maintain the score to be 0;
*/
void Board::SetUpGame() {
	InitBoard();
	InitCopy();
	score_ = 0;
}

/**
 * Randomly return either value 2 or 4;
*/
size_t Board::ChooseTwoOrFour() {
	int random = rand() % 2;
	if (random == 0) {
		return kStartingNumber1;
	} else {
		return kStartingNumber2;
	}
}

/**
 * Randomly select an empty position on the board and spawn a new two in its place.
*/
void Board::SpawnNewTwo(vector<size_t> &possible_positions) {
	// Prevent a divide by 0 error.
	if (possible_positions.size() == 0) {
		return;
	}

	int new_two_position = possible_positions[rand() % possible_positions.size()];
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			if (board_[i][j].board_position == new_two_position) {
				board_[i][j].value = kStartingNumber1;
				break;
			}
		}
	}
}