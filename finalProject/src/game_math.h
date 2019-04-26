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

	size_t score_ = 0;
	bool has_won = false;

	const size_t kBoardDimension = 4;
	const size_t kNumOfTiles = 16;
	const size_t kTwo = 2;
	const size_t kFour = 4;
	const size_t winning_number = 2048;

	void InitBoard();
	size_t ChooseTwoOrFour();
	void SpawnNewTwo(vector<size_t> possible_positions);
	void RudimentaryPrint();
	vector<size_t> FindEmptyPositions();
	bool hasWon();
	void winningNumberReached(size_t value);
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




