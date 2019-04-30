#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

private:
	// Enum representing the current state of the game.
	// Adapted from Elizabeth Wang's final project:
	// https://github.com/ElizWang/Enhanced_Pacman.
	enum GameState {
		BEGIN,
		SETUP,
		PLAY,
		WIN,
		LOSS
	};

	void update();

	void keyPressed(int key);

	void CheckGameOver();

	void InitTileTheme();

	void ReturnToDefaults();

	// Setup and load files for game:

	void setup();

	void SetupGui();

	void LoadFonts();

	void LoadSound();

	void LoadImages();

	// Drawing Methods for UI design:

	void draw();

	void DrawBoard();

	void DrawScore();

	void DrawWin();

	void DrawLoss();

	void DrawReplayMessage();

	void DrawBeginningStage();

	void DrawTiles();

	// Methods to Control Buttons:

	void CandyButtonPressed();

	void EarthyButtonPressed();

	// Fonts:
	ofTrueTypeFont pixel_font_large_;
	ofTrueTypeFont pixel_font_small_;

	// Font filenames and constant sizes:
	const std::string kPixelFont = "pixelmix.ttf";
	const int kLargeFontSize = 35;
	const int kSmallFontSize = 18;

	// Messages displayed on the UI:
	const std::string kName = "Enhanced 2048";
	const std::string kBeginGame = "Press 'B' to begin 2048";
	const std::string kWonMessage = "You WON!";
	const std::string kLostMessage = "You lost";
	const std::string kReplayMessage = "Press 'N' to begin a new game";
	const std::string kResurrectMessage = "Press 'R' to resurrect";
	const std::string kInstructions = "Use keys 'W', 'A', 'S', 'D' to play";
	const std::string kScore = "SCORE: ";

	// Music Players:
	ofSoundPlayer winning_tune_;
	ofSoundPlayer click_;
	ofSoundPlayer losing_tune_;
	ofSoundPlayer beginning_tune_;

	// Music Filenames:
	const std::string kBeginningTune = "ilomilo.mp3";
	const std::string kClick = "Stapler.mp3";
	const std::string kLosingTune = "AllStar.mp3";
	const std::string kWinningTune = "CodyKoOutroSong.mp3";

	// ofxGui objects:
	ofxPanel gui_;
	ofxButton candy_;
	ofxButton earthy_;

	// ofxGui button labels:
	const std::string kThemeLabel = "Select Theme";
	const std::string kCandyLabel = "CANDY";
	const std::string kEarthyLabel = "EARTHY";

	// Image:
	ofImage heart_;

	// Image filename:
	const std::string kHeartImage = "pixelheart.gif";

	// Map that corresponds tile position number with x and y coordinates:
	map<int, pair<float, float>> positions_;

	// Global Variables initialized to default states:
	GameState current_state_ = BEGIN;

	bool is_theme_candy_ = false;
	bool is_theme_earthy_ = false;

	bool is_life_available_ = true;

	bool should_update_ = true;
	bool should_move_board_ = false;
		
	// Constant Dimensions for UI elements:
	const int kTileDimension = 100;
	const int kBackBoardDimension = 450;
	const int kSpacing = 10;

	// Constant characters for key presses:
	const char kBegin = 'B';
	const char kNewGame = 'N';
	const char kResurrect = 'R';
	const char kUp = 'W';
	const char kLeft = 'A';
	const char kDown = 'S';
	const char kRight = 'D';
};