#include "ofApp.h"
#include "board.h"
#include "theme.h"

// Maintain values and run methods via a Board object.
Board board;

// Load tile images via a theme object.
Theme theme;

/**
 * Title and color the window.
 * Load fonts.
 * Set up and label button panel using ofxGui.
 * Load heart image and tile themes.
 * Load music.
 * Play beginning music.
**/
void ofApp::setup() {
	ofSetWindowTitle(kName);
	ofBackground(171, 197, 245);

	SetupGui();

	LoadFonts();
	LoadSound();
	LoadImages();
	
	beginning_tune_.play();
}

/**
 * Set up theme panel using ofxGui.
 * Set up button to select Candy and Earthy themes.
 * Label panel and buttons.
**/
void ofApp::SetupGui() {
	gui_.setup(kThemeLabel);
	candy_.addListener(this, &ofApp::CandyButtonPressed);
	earthy_.addListener(this, &ofApp::EarthyButtonPressed);
	gui_.add(candy_.setup(kCandyLabel));
	gui_.add(earthy_.setup(kEarthyLabel));
}

/**
 * Load a large and small pixel font.
**/
void ofApp::LoadFonts() {
	pixel_font_large_.load(kPixelFont, kLargeFontSize);
	pixel_font_small_.load(kPixelFont, kSmallFontSize);
}

/**
 * Load music and sound effects to be played throughout game.
**/
void ofApp::LoadSound() {
	winning_tune_.load(kWinningTune);
	losing_tune_.load(kLosingTune);
	beginning_tune_.load(kBeginningTune);
	click_.load(kClick);
}

/** 
 * Load heart image and candy and earthy tile images.
**/
void ofApp::LoadImages() {
	heart_.load(kHeartImage);
	theme.LoadCandyTiles();
	theme.LoadEarthyTiles();
}

/**
 * Run soley when update variable is true:
 * During SETUP, select the theme chosen by the user and initialize the board before moving to PLAY
 * During PLAY, update the game after each keypress.
**/
void ofApp::update() {
	if (should_update_ == true) {
		if (current_state_ == SETUP) {
			InitTileTheme();
			board.SetUpGame();
			current_state_ = PLAY;
		}
		if (current_state_ == PLAY && should_move_board_) {

			// Compare to board copy to verify that the move was valid
			if (!board.AreBoardsEqual(board.board_, board.board_copy_)) {
				// If the move was valid, spawn a new two
				board.SpawnNewTwo(board.FindEmptyPositions());
			}

			board.CopyBoard(board.board_, board.board_copy_);
			// Play a sound effect.
			click_.play();
			CheckGameOver();
			// Do not allow the board to update until the boolean is flipped in the next key press;
			should_move_board_ = false;
		}	
	}
}

/**
 * Set color to white.
 * During BEGIN, draw beginning stage and ofxGui panel.
 * During PLAY, draw the board, score, tiles, replay message, and also the heart if necessary.
**/
void ofApp::draw() {
	ofSetColor(255, 255, 255);

	if (current_state_ == BEGIN) {
		DrawBeginningStage();
		gui_.draw();

	} else if (current_state_ == PLAY) {
		// If the player has not used up their life, draw a heart graphic.
		if (is_life_available_) {
			heart_.draw(ofGetWindowWidth() - 150, 2, 125, 125);
		}
		DrawBoard();
		DrawScore();
		DrawTiles();
		DrawReplayMessage();

	} else if (current_state_ == WIN) {
		DrawBoard();
		DrawTiles();
		DrawWin();

	} else if (current_state_ == LOSS) {
		DrawBoard();
		DrawTiles();
		DrawLoss(); 
	}
}

/**
 * Draw the board.
 * Populate the positions map so the positions correspond to the x and y coordinates of the tiles.
**/
void ofApp::DrawBoard() {
	float height = ofGetWindowHeight();
	float width = ofGetWindowWidth();

	// Calculate the position to begin drawing the backboard so that it is centered.
	float starting_point_x = (width / 2) - (2 * kTileDimension) - kSpacing;
	float starting_point_y = (height / 2) - (2 * kTileDimension) - kSpacing;

	// Initialize the starting points for drawing the tiles.
	int position_x = starting_point_x;
	int position_y = starting_point_y;

	// Draw a pale blue-gray backboard.
	ofSetColor(214, 229, 255);
	ofDrawRectangle(starting_point_x - kSpacing, starting_point_y - kSpacing, kBackBoardDimension, kBackBoardDimension);
	
	// Draw tiles in white.
	ofSetColor(255, 255, 255);

	// Number the tiles.
	int position_counter = 1;
	for (int i = 0; i < board.kBoardDimension; i++) {
		for (int j = 0; j < board.kBoardDimension; j++) {
			// Draw a tile.
			ofDrawRectangle(position_x, position_y, kTileDimension, kTileDimension);
			// Add each tile position and corresponding x and y coordinates to positions map.
			positions_[position_counter] = make_pair(position_x, position_y);
			// Maintain spacing between tiles horizonatlly.
			position_x = position_x + kTileDimension + kSpacing;
			position_counter++;
		}
		// Move back to the beginning of the row.
		position_x = starting_point_x;
		// Maintain spacing between each tile vertically.
		position_y = position_y + kTileDimension + kSpacing;
	}
}
/**
 * Display a message showing the score.
**/
void ofApp::DrawScore() {
	pixel_font_large_.drawString(kScore + std::to_string(board.score_), 50, 75);
}

/**
 * Display a message showing that the player has won.
 * Display a message prompting the player to replay.
**/
void ofApp::DrawWin() {
	pixel_font_large_.drawString(kWonMessage, 50, 75);
	DrawReplayMessage();
}

/**
 * Display a message showing that the player has lost.
 * Display a message prompting the player to replay.
 * Display a message prompting the player to resurrect if they have not already done so.
**/
void ofApp::DrawLoss() {
	pixel_font_large_.drawString(kLostMessage, 50, 75);
	DrawReplayMessage();
	if (is_life_available_) {
		pixel_font_small_.drawString(kResurrectMessage, 50, ofGetHeight() - 75);
	}
}

/**
 * Display a message prompting the player to replay.
**/
void ofApp::DrawReplayMessage() {
	pixel_font_small_.drawString(kReplayMessage, 50, ofGetHeight() - 35);
}

/**
 * Read the position of each tile in the board, find the corresponding x and y coordinates in the positions map.
 * Read the value of each tile in the map, find the corresponding image in the theme.tiles map.
 * Draw that tile image at the coordinates.
**/
void ofApp::DrawTiles() {
	int counter = 1;
	for (int i = 0; i < board.kBoardDimension; i++) {
		for (int j = 0; j < board.kBoardDimension; j++) {
			theme.tiles[board.board_[i][j].value].draw(positions_[counter].first, positions_[counter].second);
			counter++;
		}
	}
}

/** 
 * Draw a message prompting the player to begin the game and provide instructions
**/
void ofApp::DrawBeginningStage() {
	pixel_font_large_.drawString(kBeginGame, 50, 150);
	pixel_font_large_.drawString(kInstructions, 50, 225);
}

/** 
 * This method was adapted from Elizabeth Wang's Final Project:
 * https://github.com/ElizWang/Enhanced_Pacman.
 * If the state is WIN, LOSS, OR PLAY, and the player presses 'N', a new game begins.
 * If the state is BEGIN, the player can press 'B' to setup the game.
 * During play:
 * If the player presses 'W', the board shifts up.
 * If the player presses 'A', the board shifts left.
 * If the player presses 'S', the board shifts down.
 * If the player pressed 'D', the board shifts right.
 * If the state is LOSS and the player hasn't used up their life, they may press 'R' to resurrect. 
**/
void ofApp::keyPressed(int key) {
	int input = toupper(key);

	if (current_state_ == WIN || current_state_ == PLAY || current_state_ == LOSS) {
		if (input == kNewGame) {
			winning_tune_.stop();
			losing_tune_.stop();
			beginning_tune_.play();
			ReturnToDefaults();
		}	
	}

	if (current_state_ == BEGIN) {
		if (input == kBegin) {
			current_state_ = SETUP;
			beginning_tune_.stop();
		}

	} else if (current_state_ == PLAY) {
		if (input == kLeft) {
			board.CompressLeft();
			board.MergeLeft();
			should_move_board_ = true;
		}
		if (input == kUp) {
			board.CompressUp();
			board.MergeUp();
			should_move_board_ = true;
		}
		if (input == kRight) {
			board.CompressRight();
			board.MergeRight();
			should_move_board_ = true;
		}
		if (input == kDown) {
			board.CompressDown();
			board.MergeDown();
			should_move_board_ = true;
		}

	} else if (current_state_ == LOSS && is_life_available_ && input == kResurrect) {
		board.ResurrectPlayer();
		is_life_available_ = false;
		should_update_ = true;
		winning_tune_.stop();
		losing_tune_.stop();
		current_state_ = PLAY;
	}
}

/**
 * If the player has won, stop updating, change state to WIN, and play winning music.
 * If the player has lost, stop updating, change state to LOSS, and play losing music.
**/
void ofApp::CheckGameOver() {
	if (board.has_won_) {
		should_update_ = false;
		current_state_ = WIN;
		winning_tune_.play();
	} 
	if (board.HasLost()) {
		should_update_ = false;
		current_state_ = LOSS;
		losing_tune_.play();
	}
}

/**
 * If the player selects the candy theme, poplate the tile map with candy tiles.
 * If the player selects both themes or no theme, default to populating the tile map with candy tiles.
 * Otherwise (in the case that the earth theme is selected) populate the theme map with earthy tiles.
**/
void ofApp::InitTileTheme() {
	if (is_theme_candy_ && !is_theme_earthy_ || is_theme_candy_ && is_theme_earthy_ || !is_theme_candy_ && !is_theme_earthy_) {
		theme.SetUpCandyTileMap();
	} else {
		theme.SetUpEarthyTileMap();
	}
}

/**
 * Return global variables to their default states to reset a game.
**/
void ofApp::ReturnToDefaults() {
	should_update_ = true;
	is_life_available_ = true;
	board.has_won_ = false;
	is_theme_candy_ = false;
	is_theme_earthy_ = false;
	current_state_ = BEGIN;
}

/**
 * When the candy button is pressed, flip the state of the is_theme_candy_ variable.
**/
void ofApp::CandyButtonPressed() {
	if (is_theme_candy_) {
		is_theme_candy_ = false;
	} else {
		is_theme_candy_ = true;
	}
}

/**
 * When the earthy button is pressed, flip the state of the is_theme_earthy_ variable.
**/
void ofApp::EarthyButtonPressed() {
	if (is_theme_earthy_) {
		is_theme_earthy_ = false;
	} else {
		is_theme_earthy_ = true;
	}
}