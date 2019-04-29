#pragma once

#include "board.h"

// Initialize the board at the beginning of the game to be empty with only two tiles. 
// One tile has the value two, the other one has the value two or four. 
void Board::InitBoard() {
	// Select a random position for the first tile.
	int first_tile_postion = rand() % kNumOfTiles + 1;
	int second_tile_position = first_tile_postion;

	// Select a random position for the second tile and ensure that it is not the same as the first.
	while (second_tile_position == first_tile_postion) {
		second_tile_position = rand() % kNumOfTiles + 1;
	}
	// Randomly select the value of the second tile to be two or four.
	int second_tile_value = ChooseTwoOrFour();
	
	int board_position = 1;
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			// Traverse through the board and initialize each value to be 0 unless it is the first or second tile.
			if (board_position == first_tile_postion) {
				board_[i][j].value = kTwo;

			} else if (board_position == second_tile_position) {
				board_[i][j].value = second_tile_value;

			} else {
				board_[i][j].value = 0;
				board_[i][j].board_position = board_position;
			}
			board_position++;
		}
	}
}

// Simply print the board for testing purposes.
void Board::RudimentaryPrint() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			std::cout << board_[i][j].value << " ";
		}
		std::cout << endl;
	}
}

// Return a vector of positions in the board where the value is 0 (essentially, that position is 'empty').
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

// Move all the tiles leftwards so that no zeroes lie between nonzero values.
void Board::CompressLeft() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			if (board_[i][j].value == 0) {
				for (int k = j + 1; k < kBoardDimension; k++) {
					// if a tile value is zero, and the tile to the right is not zero, change the first tile's value to that of the second tile, and the second tile's value to 0.
					if (board_[i][k].value != 0) {
						board_[i][j].value = board_[i][k].value;
						// record which tile in sliding into the place of the initial tile
						board_[i][j].contributors.push_back(board_[i][k].board_position);
						board_[i][k].value = 0;
						break;
					}
				}
			}
		}
	}
}

// Merges values of tiles leftwards.
void Board::MergeLeft() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension - 1; j++) {
			// If the tile value doesn't equal zero and the tile to the right of it has the value zero, the value of the first tile equals their sum and the value of the second tile becomes zero.
			if (board_[i][j].value != 0 && board_[i][j].value == board_[i][j + 1].value) {
				board_[i][j].value += board_[i][j + 1].value;
				//board_[i][j].contributors += board_.
				board_[i][j + 1].value = 0;
				// The score is updated.
				score_ += ((log2(board_[i][j].value)) - 1) * board_[i][j].value;
				WinningNumberReached(board_[i][j].value);
			}
		}
	}
	// Compress the tiles again to eliminate any new zeroes.
	CompressLeft();
}

// Move all the tiles upwards so that no zeroes lie between nonzero values.
void Board::CompressUp() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			// If a tile value is zero, and the tile below it is not zero, change the first tile's value to that of the second tile, and the second tile's value to 0.
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

// Merges values of tiles upwards.
void Board::MergeUp() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			// If the tile value doesn't equal zero and the tile below it has the value zero
			// the value of the first tile equals their sum and the value of the second tile becomes zero.
			if (board_[j][i].value != 0 && board_[j][i].value == board_[j + 1][i].value) {
				board_[j][i].value += board_[j + 1][i].value;
				board_[j + 1][i].value = 0;
				// The score is updated.
				score_ += (((log2(board_[j][i].value)) - 1) * board_[j][i].value);
				WinningNumberReached(board_[j][i].value);
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

// Merges values of tiles rightwards.
void Board::MergeRight() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = kBoardDimension - 1; j > 0; j--) {
			// If the tile value doesn't equal zero and the tile to the left of it has the value zero, the value of the first tile equals their sum and the value of the second tile becomes zero.
			if (board_[i][j].value != 0 && board_[i][j].value == board_[i][j - 1].value) {
				board_[i][j].value += board_[i][j - 1].value;
				board_[i][j - 1].value = 0;
				// The score is updated.
				score_ += (((log2(board_[i][j].value)) - 1) * board_[i][j].value);
				WinningNumberReached(board_[i][j].value);
			}
		}
	}
	// Compress the tiles again to eliminate any new zeroes.
	CompressRight();
}

// Move all the tiles downwards so that no zeroes lie between nonzero values.
void Board::CompressDown() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = kBoardDimension - 1; j >= 0; j--) {
			if (board_[j][i].value == 0) {
				// If a tile value is zero, and the tile above it is not zero, change the first tile's value to that of the second tile, and the second tile's value to 0.
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

// Merges values of tiles downwards.
void Board::MergeDown() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = kBoardDimension - 1; j > 0; j--) {
			// If the tile value doesn't equal zero and the tile above it has the value zero, the value of the first tile equals their sum and the value of the second tile becomes zero.
			if (board_[j][i].value != 0 && board_[j][i].value == board_[j - 1][i].value) {
				board_[j][i].value += board_[j - 1][i].value;
				board_[j - 1][i].value = 0;
				//The score is updated.
				score_ += (((log2(board_[j][i].value)) - 1) * board_[j][i].value);
				WinningNumberReached(board_[j][i].value);
			}
		}
	}
	// Compress the tiles again to eliminate any new zeroes.
	CompressDown();
}

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

void Board::CopyBoard(Tile initial[4][4], Tile copy[4][4]) {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			copy[i][j].value = initial[i][j].value;
		}
	}
}

bool Board::BoardsAreEqual(Tile initial[4][4], Tile copy[4][4]) { // rename areboardsequal
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			if (copy[i][j].value != initial[i][j].value) {
				return false;
			}
		}
	}
	return true;
}

bool Board::HasLost() {
	if (FindEmptyPositions().size() != 0) { // !.Empty
		return false;
	}
	for (int i = 0; i < kBoardDimension; i++) { // - 1 ??
		for (int j = 0; j < kBoardDimension; j++) {
			/*if (board_[i][j].value == board_[i][j + 1].value || board_[i][j].value == board_[i + 1][j].value) {
				return false;
			}*/
			if (j < kBoardDimension - 1) {
				if (board_[i][j].value == board_[i][j + 1].value) {
					return false;
				}
			}
			//check the tile below the chosen tile. Ignore last row.
			if (i < kBoardDimension - 1) {
				if (board_[i][j].value == board_[i + 1][j].value) {
					return false;
				}
			}
		}
	}
	return true;
}

void Board::WinningNumberReached(size_t value) { // updatehaswon
	if (value == kWinningNumber) {
		has_won = true;
	}
}

void Board::SetUpGame() {
	InitBoard();
	InitCopy();
	RudimentaryPrint();
}

void Board::ClearContributors() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			board_[i][j].contributors.clear();
		}
	}
} 

size_t Board::ChooseTwoOrFour() {
	int random = rand() % 2;
	if (random == 0) {
		return kTwo;
	} else {
		return kFour;
	}
}

void Board::SpawnNewTwo(vector<size_t> possible_positions) {
	int new_two_position = possible_positions[rand() % possible_positions.size()];
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			if (board_[i][j].board_position == new_two_position) {
				board_[i][j].value = kTwo;
				break;
			}
		}
	}
}

 