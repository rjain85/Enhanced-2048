#pragma once

#include <vector>
#include "ofMain.h"
using std::vector;

class Board {

public:
	struct Tile {
		size_t value;
		size_t board_position;
	};

	void SetUpGame();

	bool AreBoardsEqual(Tile initial[4][4], Tile copy[4][4]);

	void InitBoard();

	void SpawnNewTwo(vector<size_t> possible_positions);

	void RudimentaryPrint();

	vector<size_t> FindEmptyPositions();
	
	void InitCopy();

	void CopyBoard(Tile initial[4][4], Tile copy[4][4]);

	bool HasLost();

	void ResurrectPlayer();

	size_t highest_value = 2;

	size_t position_of_highest_value = 0;

	void UpdateHasWon(size_t value);

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

	size_t score_ = 0;
	bool has_won_ = false;

	const size_t kBoardDimension = 4;


private: 
	size_t ChooseTwoOrFour(); // private

	const size_t kNumOfTiles = 16;
	const size_t kStartingNumber1 = 2;
	const size_t kStartingNumber2 = 4;
	const size_t kWinningNumber = 2048;
};