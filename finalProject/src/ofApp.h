#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

private:
	/** 
	 * Enum representing the current state of the game.
	 * Adapted from Elizabeth Wang's final project:
	 * https://github.com/ElizWang/Enhanced_Pacman.
	 */
	enum GameState {
		BEGIN,
		SETUP,
		PLAY,
		WIN,
		LOSS
	};

	/**
	 * Take into account changes in state and update the board and state accordingly.
	 */
	void update();

	/**
	 * Do calculations on the board and modify the state based off of key presses from the user.
	 * @param - a key inputted by the user.
	 */
	void keyPressed(int key);

	/**
	 * Check methods and variables from the Board class to see if the game is over.
	 */
	void CheckGameOver();

	/**
	 * Set up the game theme based off of input from the user.
	 */
	void InitTileTheme();

	/**
	 * Return global variables to their default settings.
	 */
	void ReturnToDefaults();

	/** 
	 * Setup and load files for game:
	 */
	void setup();

	/**
	 * Set up theme panel using ofxGui.
	 * Set up button to select Candy and Earthy themes.
	 * Label panel and buttons.
	 */
	void SetupGui();

	/**
	 * Load a large and small pixel font.
	 */
	void LoadFonts();

	/**
	 * Load music and sound effects to be played throughout game.
	**/
	void LoadSound();

	/**
	 * Load heart image and candy and earthy tile images.
	**/
	void LoadImages();

	/**
	 * Drawing Methods for UI design:
	 */
	void draw();

	/**
	 * Draw the board.
	 * Populate the positions map so the positions correspond to the x and y coordinates of the tiles.
	 */
	void DrawBoard();

	/**
	 * Display a message showing the score.
	 */
	void DrawScore();

	/**
	 * Display a message showing that the player has won.
	 * Display a message prompting the player to replay.
	 */
	void DrawWin();

	/**
	 * Display a message showing that the player has lost.
	 * Display a message prompting the player to replay.
	 * Display a message prompting the player to resurrect if they have not already done so.
	 */
	void DrawLoss();

	/**
	 * Display a message prompting the player to replay.
	 */
	void DrawReplayMessage();

	/**
	 * Draw a message prompting the player to begin the game and provide instructions
	 */
	void DrawBeginningStage();

	/**
	 * Read the position of each tile in the board, find the corresponding x and y coordinates in the positions map.
	 * Read the value of each tile in the map, find the corresponding image in the theme.tiles map.
	 * Draw that tile image at the coordinates.
	 */
	void DrawTiles();

	/**
	 * When the candy button is pressed, flip the state of the is_theme_candy_ variable.
	 */
	void CandyButtonPressed();

	/**
	 * When the earthy button is pressed, flip the state of the is_theme_earthy_ variable.
	 */
	void EarthyButtonPressed();

	/**
	 * Fonts:
	 */
	ofTrueTypeFont pixel_font_large_;
	ofTrueTypeFont pixel_font_small_;

	/**
	 * Font filenames and constant sizes:
	 */
	const std::string kPixelFont = "pixelmix.ttf";
	const int kLargeFontSize = 35;
	const int kSmallFontSize = 18;

	/** 
	 * Messages displayed on the UI:
	 */
	const std::string kName = "Enhanced 2048";
	const std::string kBeginGame = "Press 'B' to begin 2048";
	const std::string kWonMessage = "You WON!";
	const std::string kLostMessage = "You lost";
	const std::string kReplayMessage = "Press 'N' to begin a new game";
	const std::string kResurrectMessage = "Press 'R' to resurrect";
	const std::string kInstructions = "Use keys 'W', 'A', 'S', 'D' to play";
	const std::string kScore = "SCORE: ";

	/**
	 * Music Players:
	 */
	ofSoundPlayer winning_tune_;
	ofSoundPlayer click_;
	ofSoundPlayer losing_tune_;
	ofSoundPlayer beginning_tune_;

	/** 
	 * Music Filenames:
	 */
	const std::string kBeginningTune = "ilomilo.mp3";
	const std::string kClick = "Stapler.mp3";
	const std::string kLosingTune = "AllStar.mp3";
	const std::string kWinningTune = "CodyKoOutroSong.mp3";

	/** 
	 * ofxGui objects:
	 */
	ofxPanel gui_;
	ofxButton candy_;
	ofxButton earthy_;

	/** 
	 * ofxGui button labels:
	 */
	const std::string kThemeLabel = "Select Theme";
	const std::string kCandyLabel = "CANDY";
	const std::string kEarthyLabel = "EARTHY";

	/**
	 * Image:
	 */
	ofImage heart_;

	/**
	 * Image filename:
	 */
	const std::string kHeartImage = "pixelheart.gif";

	/**
	 * Map that corresponds tile position number with x and y coordinates:
	 */
	map<int, pair<float, float>> positions_;

	/**
	 * Initial GameState.
	 */
	GameState current_state_ = BEGIN;

	/**
	 * Initial state of candy theme.
	 */
	bool is_theme_candy_ = false;

	/**
	 * Initial state of earthy theme.
	 */
	bool is_theme_earthy_ = false;

	/**
	 * Bool indicating whether the player has a life to resurrect.
	 */
	bool is_life_available_ = true;

	/**
	 * Bool indicating whether the update method should run.
	 */
	bool should_update_ = true;

	/**
	 * Bool indicating whether the the ui for the board should be updated.
	 */
	bool should_move_board_ = false;
		
	/** 
	 * Constant Dimensions for UI elements:
	 */
	const int kTileDimension = 100;
	const int kBackBoardDimension = 450;
	const int kSpacing = 10;

	/**
	 * Constant characters for key presses:
	 */
	const char kBegin = 'B';
	const char kNewGame = 'N';
	const char kResurrect = 'R';
	const char kUp = 'W';
	const char kLeft = 'A';
	const char kDown = 'S';
	const char kRight = 'D';

	/**
	 * Constant colors for UI elements.
	 */
	const ofColor kBlue = ofColor(171, 197, 245);
	const ofColor kWhite = ofColor(255, 255, 255);
	const ofColor kBlueGray = ofColor(214, 229, 255);
};