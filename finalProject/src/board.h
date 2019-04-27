#pragma once

#include <vector>
#include "ofMain.h"
using std::vector;

class Board {
	struct Tile {
		size_t value;
		size_t board_position;
	};

public:
	Tile board_[4][4];
	Tile board_copy_[4][4];

	int score_ = 0;
	bool has_won = false;

	const size_t kBoardDimension = 4;
	const size_t kNumOfTiles = 16;
	const size_t kTwo = 2;
	const size_t kFour = 4;
	const size_t winning_number = 8;

	void InitBoard();
	size_t ChooseTwoOrFour();
	void SpawnNewTwo(vector<size_t> possible_positions);
	void RudimentaryPrint();
	vector<size_t> FindEmptyPositions();
	//bool hasWon();
	void MakeMoves(char input);
	void LoopThroughGame();
	void InitCopy();
	void CopyBoard(Tile initial[4][4], Tile copy[4][4]);
	bool BoardsAreEqual(Tile initial[4][4], Tile copy[4][4]);
	bool HasLost();
	void WinningNumberReached(size_t value);
	void SetUpGame();

	void CompressLeft();
	void MergeLeft();
	void CompressUp();
	void MergeUp();
	void CompressRight();
	void MergeRight();
	void CompressDown();
	void MergeDown();
};




