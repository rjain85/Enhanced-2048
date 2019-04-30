#pragma once

#include "ofMain.h"
#include "board.h"

class Theme {
public:
	void LoadCandyTiles();

	void LoadEarthyTiles();

	void SetUpCandyTileMap();

	void SetUpEarthyTileMap();

	map<int, ofImage> tiles;

private:
	ofImage tile_two_candy;
	ofImage tile_four_candy;
	ofImage tile_eight_candy;
	ofImage tile_sixteen_candy;
	ofImage tile_thirty_two_candy;
	ofImage tile_sixty_four_candy;
	ofImage tile_one_twenty_eight_candy;
	ofImage tile_two_fifty_six_candy;
	ofImage tile_five_twelve_candy;
	ofImage tile_ten_twenty_four_candy;
	ofImage tile_twenty_forty_eight_candy;

	ofImage tile_two_earthy;
	ofImage tile_four_earthy;
	ofImage tile_eight_earthy;
	ofImage tile_sixteen_earthy;
	ofImage tile_thirty_two_earthy;
	ofImage tile_sixty_four_earthy;
	ofImage tile_one_twenty_eight_earthy;
	ofImage tile_two_fifty_six_earthy;
	ofImage tile_five_twelve_earthy;
	ofImage tile_ten_twenty_four_earthy;
	ofImage tile_twenty_forty_eight_earthy;
};