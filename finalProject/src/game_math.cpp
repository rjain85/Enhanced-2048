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

int Board::ChooseTwoOrFour() {
	int random = rand() % 2;
	if (random == 0) {
		return kTwo;

	} else {
		return kFour;
	}
}
