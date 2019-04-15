#pragma once

#include <vector>
#include "ofMain.h"
using std::vector;

class Board {
	struct Tile {
		int value;
		int board_position;
	};

public:
	//vector< vector<Tile>> board;
	const int kBoardDimension = 4;
	const int kNumOfTiles = 16;

	const int kTwo = 2;
	const int kFour = 4;
	void InitBoard();
	int ChooseTwoOrFour();
	void RudimentaryPrint();
	Tile board[4][4];
};


