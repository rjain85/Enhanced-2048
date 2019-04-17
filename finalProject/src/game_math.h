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
	const int kBoardDimension = 4;
	const int kNumOfTiles = 16;

	const int kTwo = 2;
	const int kFour = 4;
	const int winning_number = 2048;
	void InitBoard();
	int ChooseTwoOrFour();
	void SpawnNewTwo(vector<int> possible_positions);
	void RudimentaryPrint();
	vector<int> FindEmptyPositions();
	bool isWin();

	void MakeMoves(char input);

	void CompressLeft();
	void MergeLeft();
	void CompressUp();
	void MergeUp();
	void CompressRight();
	void MergeRight();
	void CompressDown();
	void MergeDown();

	void loop_through_game();



	Tile board[4][4];
	int score = 0;
};




