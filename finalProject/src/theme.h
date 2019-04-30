#pragma once
#include "ofMain.h"

class Theme {
public:
	// Methods to load tile images:

	void LoadCandyTiles();

	void LoadEarthyTiles();

	// Methods to populate tile map:

	void SetUpCandyTileMap();

	void SetUpEarthyTileMap();

	// Map matching tile values with tile images:

	map<int, ofImage> tiles;

private:
	// ofImage objects to store candy tiles;
	ofImage tile_two_candy_;
	ofImage tile_four_candy_;
	ofImage tile_eight_candy_;
	ofImage tile_sixteen_candy_;
	ofImage tile_thirty_two_candy_;
	ofImage tile_sixty_four_candy_;
	ofImage tile_one_twenty_eight_candy_;
	ofImage tile_two_fifty_six_candy_;
	ofImage tile_five_twelve_candy_;
	ofImage tile_ten_twenty_four_candy_;
	ofImage tile_twenty_forty_eight_candy_;

	// ofImage objects to store earthy tiles
	ofImage tile_two_earthy_;
	ofImage tile_four_earthy_;
	ofImage tile_eight_earthy_;
	ofImage tile_sixteen_earthy_;
	ofImage tile_thirty_two_earthy_;
	ofImage tile_sixty_four_earthy_;
	ofImage tile_one_twenty_eight_earthy_;
	ofImage tile_two_fifty_six_earthy_;
	ofImage tile_five_twelve_earthy_;
	ofImage tile_ten_twenty_four_earthy_;
	ofImage tile_twenty_forty_eight_earthy_;

	// Candy tile file names:
	const std::string k2Candy = "2tile.png";
	const std::string k4Candy = "4tile.png";
	const std::string k8Candy = "8tile.png";
	const std::string k16Candy = "16tile.png";
	const std::string k32Candy = "32tile.png";
	const std::string k64Candy = "64tile.png";
	const std::string k128Candy = "128tile.png";
	const std::string k256Candy = "256tile.png";
	const std::string k512Candy = "512tile.png";
	const std::string k1024Candy = "1024tile.png";
	const std::string k2048Candy = "2048tile.png";

	// Earthy tile file names:
	const std::string k2Earthy = "2f.png";
	const std::string k4Earthy = "4f.png";
	const std::string k8Earthy = "8f.png";
	const std::string k16Earthy = "16f.png";
	const std::string k32Earthy = "32f.png";
	const std::string k64Earthy = "64f.png";
	const std::string k128Earthy = "128f.png";
	const std::string k256Earthy = "256f.png";
	const std::string k512Earthy = "512f.png";
	const std::string k1024Earthy = "1024f.png";
	const std::string k2048Earthy = "2048f.png";
};