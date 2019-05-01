#include "theme.h"

/**
 * Load candy tile images to ofImage objects.
 */
void Theme::LoadCandyTiles() {
	tile_two_candy_.load(k2Candy);
	tile_four_candy_.load(k4Candy);
	tile_eight_candy_.load(k8Candy);
	tile_sixteen_candy_.load(k16Candy);
	tile_thirty_two_candy_.load(k32Candy);
	tile_sixty_four_candy_.load(k64Candy);
	tile_one_twenty_eight_candy_.load(k128Candy);
	tile_two_fifty_six_candy_.load(k256Candy);
	tile_five_twelve_candy_.load(k512Candy);
	tile_ten_twenty_four_candy_.load(k1024Candy);
	tile_twenty_forty_eight_candy_.load(k2048Candy);
}

/**
 * Load earthy tile images to ofImage objects.
 */
void Theme::LoadEarthyTiles() {
	tile_two_earthy_.load(k2Earthy);
	tile_four_earthy_.load(k4Earthy);
	tile_eight_earthy_.load(k8Earthy);
	tile_sixteen_earthy_.load(k16Earthy);
	tile_thirty_two_earthy_.load(k32Earthy);
	tile_sixty_four_earthy_.load(k64Earthy);
	tile_one_twenty_eight_earthy_.load(k128Earthy);
	tile_two_fifty_six_earthy_.load(k256Earthy);
	tile_five_twelve_earthy_.load(k512Earthy);
	tile_ten_twenty_four_earthy_.load(k1024Earthy);
	tile_twenty_forty_eight_earthy_.load(k2048Earthy);
}

/**
 * Populate tile map with candy tiles so that the integer key corresponds to the value displayed on the tile.
 */
void Theme::SetUpCandyTileMap() {
	tiles[2] = tile_two_candy_;
	tiles[4] = tile_four_candy_;
	tiles[8] = tile_eight_candy_;
	tiles[16] = tile_sixteen_candy_;
	tiles[32] = tile_thirty_two_candy_;
	tiles[64] = tile_sixty_four_candy_;
	tiles[128] = tile_one_twenty_eight_candy_;
	tiles[256] = tile_two_fifty_six_candy_;
	tiles[512] = tile_five_twelve_candy_;
	tiles[1024] = tile_ten_twenty_four_candy_;
	tiles[2048] = tile_twenty_forty_eight_candy_;
}

/**
 * Populate tile map with earthy tiles so that the integer key corresponds to the value displayed on the tile.
 */
void Theme::SetUpEarthyTileMap() {
	tiles[2] = tile_two_earthy_;
	tiles[4] = tile_four_earthy_;
	tiles[8] = tile_eight_earthy_;
	tiles[16] = tile_sixteen_earthy_;
	tiles[32] = tile_thirty_two_earthy_;
	tiles[64] = tile_sixty_four_earthy_;
	tiles[128] = tile_one_twenty_eight_earthy_;
	tiles[256] = tile_two_fifty_six_earthy_;
	tiles[512] = tile_five_twelve_earthy_;
	tiles[1024] = tile_ten_twenty_four_earthy_;
	tiles[2048] = tile_twenty_forty_eight_earthy_;
}
