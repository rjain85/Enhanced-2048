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
	Tile board_[4][4];
	Tile board_copy_[4][4];
	Tile loser_tester_[4][4];

	int score_ = 0;

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
	bool hasWon();
	void MakeMoves(char input);
	void LoopThroughGame();
	void InitCopy();
	void CopyBoard(Tile initial[4][4], Tile copy[4][4]);
	bool BoardsAreEqual(Tile initial[4][4], Tile copy[4][4]);
	bool hasLost();


	void CompressLeft();
	void MergeLeft();
	void CompressUp();
	void MergeUp();
	void CompressRight();
	void MergeRight();
	void CompressDown();
	void MergeDown();
};




