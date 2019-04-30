#pragma once

#include <vector>
#include "ofMain.h"
using std::vector;

class Board {

public:
	struct Tile {
		size_t value;
		size_t board_position;
		//vector<size_t> contributors;
	};

	void InitBoard();

	size_t ChooseTwoOrFour();

	void SpawnNewTwo(vector<size_t> possible_positions);

	void RudimentaryPrint();

	vector<size_t> FindEmptyPositions();
	
	void InitCopy();

	void CopyBoard(Tile initial[4][4], Tile copy[4][4]);

	bool AreBoardsEqual(Tile initial[4][4], Tile copy[4][4]);

	bool HasLost();

	void UpdateHasWon(size_t value);

	void SetUpGame();
	//void ClearContributors();

	void CompressLeft();

	void MergeLeft();

	void CompressUp();

	void MergeUp();

	void CompressRight();

	void MergeRight();

	void CompressDown();

	void MergeDown();

	Tile board_[4][4];
	Tile board_copy_[4][4];

	int score_ = 0;
	bool has_won = false;

	const size_t kBoardDimension = 4;
	const size_t kNumOfTiles = 16;
	const size_t kStartingNumber1 = 2;
	const size_t kStartingNumber2 = 4;
	const size_t kWinningNumber = 2048;
};