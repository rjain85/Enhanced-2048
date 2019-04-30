#include "theme.h"

void Theme::LoadCandyTiles() {
	tile_two_candy.load("2tile.png");
	tile_four_candy.load("4tile.png");
	tile_eight_candy.load("8tile.png");
	tile_sixteen_candy.load("16tile.png");
	tile_thirty_two_candy.load("32tile.png");
	tile_sixty_four_candy.load("64tile.png");
	tile_one_twenty_eight_candy.load("128tile.png");
	tile_two_fifty_six_candy.load("256tile.png");
	tile_five_twelve_candy.load("512tile.png");
	tile_ten_twenty_four_candy.load("1024tile.png");
	tile_twenty_forty_eight_candy.load("2048tile.png");
}

void Theme::LoadEarthyTiles() {
	tile_two_earthy.load("2f.png");
	tile_four_earthy.load("4f.png");
	tile_eight_earthy.load("8f.png");
	tile_sixteen_earthy.load("16f.png");
	tile_thirty_two_earthy.load("32f.png");
	tile_sixty_four_earthy.load("64f.png");
	tile_one_twenty_eight_earthy.load("128f.png");
	tile_two_fifty_six_earthy.load("256f.png");
	tile_five_twelve_earthy.load("512f.png");
	tile_ten_twenty_four_earthy.load("1024f.png");
	tile_twenty_forty_eight_earthy.load("2048f.png");
}

void Theme::SetUpCandyTileMap() {
	tiles[2] = tile_two_candy;
	tiles[4] = tile_four_candy;
	tiles[8] = tile_eight_candy;
	tiles[16] = tile_sixteen_candy;
	tiles[32] = tile_thirty_two_candy;
	tiles[64] = tile_sixty_four_candy;
	tiles[128] = tile_one_twenty_eight_candy;
	tiles[256] = tile_two_fifty_six_candy;
	tiles[512] = tile_five_twelve_candy;
	tiles[1024] = tile_ten_twenty_four_candy;
	tiles[2048] = tile_twenty_forty_eight_candy;
}

void Theme::SetUpEarthyTileMap() {
	tiles[2] = tile_two_earthy;
	tiles[4] = tile_four_earthy;
	tiles[8] = tile_eight_earthy;
	tiles[16] = tile_sixteen_earthy;
	tiles[32] = tile_thirty_two_earthy;
	tiles[64] = tile_sixty_four_earthy;
	tiles[128] = tile_one_twenty_eight_earthy;
	tiles[256] = tile_two_fifty_six_earthy;
	tiles[512] = tile_five_twelve_earthy;
	tiles[1024] = tile_ten_twenty_four_earthy;
	tiles[2048] = tile_twenty_forty_eight_earthy;
}
