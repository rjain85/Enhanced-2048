#pragma once

#include "game_math.h"

void Board::InitBoard() {
	int first_tile_postion = rand() % kNumOfTiles + 1;
	int second_tile_position = first_tile_postion;

	while (second_tile_position == first_tile_postion) {
		second_tile_position = rand() % kNumOfTiles + 1;
	}
	int second_tile_value = ChooseTwoOrFour();
	
	int board_position = 1;
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			if (board_position == first_tile_postion) {
				board[i][j].value = kTwo;
			} else if (board_position == second_tile_position) {
				board[i][j].value = second_tile_value;
			} else {
				board[i][j].value = 0;
				board[i][j].board_position = board_position;
			}
			board_position++;
		}
	}
}

void Board::RudimentaryPrint() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			std::cout << board[i][j].value << " ";
		}
		std::cout << endl;
	}
}

vector<int> Board::FindEmptyPositions() {
	vector<int> possible_postions;
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			if (board[i][j].value == 0) {
				possible_postions.push_back(board[i][j].board_position);
			}
		}
	}
	return possible_postions;
}

bool Board::isWin() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			if (board[i][j].value == winning_number) {
				return true;
			}
		}
	}
	return false;
}


void Board::CompressLeft() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			if (board[i][j].value == 0) {
				for (int k = j + 1; k < kBoardDimension; k++) {
					if (board[i][k].value != 0) {
						board[i][j].value = board[i][k].value;
						board[i][k].value = 0;
						break;
					}
				}
			}
		}
	}
}

void Board::MergeLeft() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension - 1; j++) {
			if (board[i][j].value != 0 && board[i][j].value == board[i][j + 1].value) {
				board[i][j].value += board[i][j + 1].value;
				board[i][j + 1].value = 0;

				score += ((log2(board[i][j].value)) - 1) * board[i][j].value;
			}
		}
	}
	CompressLeft();
}

void Board::CompressUp() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			if (board[j][i].value == 0) {
				for (int k = j + 1; k < kBoardDimension; k++) {
					if (board[k][i].value != 0) {
						board[j][i].value = board[k][i].value;
						board[k][i].value = 0;
						break;
					}
				}
			}
		}
	}
}

void Board::MergeUp() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension - 1; j++) {
			if (board[j][i].value != 0 && board[j][i].value == board[j + 1][i].value) {
				board[j][i].value += board[j + 1][i].value;
				board[j + 1][i].value = 0;
				score += (((log2(board[j][i].value)) - 1) * board[j][i].value);
			}
		}
	}
	CompressUp();
}

void Board::CompressRight() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = kBoardDimension - 1; j >= 0; j--) {
			if (board[i][j].value == 0) {
				for (int k = j - 1; k >= 0; k--) {
					if (board[i][k].value != 0) {
						board[i][j].value = board[i][k].value;
						board[i][k].value = 0;
						break;
					}
				}
			}
		}
	}
}

void Board::MergeRight() {
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = kBoardDimension - 1; j > 0; j--) {
			if (board[i][j].value != 0 && board[i][j].value == board[i][j - 1].value) {
				board[i][j].value += board[i][j - 1].value;
				board[i][j - 1].value = 0;
				score += (((log2(board[i][j].value)) - 1) * board[i][j].value);
			}
		}
	}
	CompressRight();
}

void Board::loop_through_game() {
	InitBoard();
	RudimentaryPrint();
	while (!isWin()) {
		char input;
		cin >> input;
		 
		MakeMoves(input);
		SpawnNewTwo(FindEmptyPositions());
		cout << endl << "score: " << score << endl;
		
		RudimentaryPrint();
 		cout << endl;
	}
}

void Board::MakeMoves(char input) {
	if (input == 'a') {
		CompressLeft();
		//cout << endl << "compressed" << endl;
		//RudimentaryPrint();
		MergeLeft();
	}
	if (input == 'w') {
 		CompressUp();
		//cout << endl << "compressed" << endl;
		//RudimentaryPrint();
		MergeUp();
	}
	if (input == 'd') {
		CompressRight();
		MergeRight();
	}
}

int Board::ChooseTwoOrFour() {
	int random = rand() % 2;
	if (random == 0) {
		return kTwo;
	} else {
		return kFour;
	}
}

void Board::SpawnNewTwo(vector<int> possible_positions) {
	int new_two_position = possible_positions[rand() % possible_positions.size()];
	for (int i = 0; i < kBoardDimension; i++) {
		for (int j = 0; j < kBoardDimension; j++) {
			if (board[i][j].board_position == new_two_position) {
				board[i][j].value = kTwo;
			}
		}
	}
}

 


