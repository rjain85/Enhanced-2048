#pragma once

#include "board.h"
#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

private:

	enum GameState {
		BEGIN,
		SETUP,
		PLAY,
		WIN,
		LOSS
	};

	ofTrueTypeFont pixel_font_;
	ofTrueTypeFont pixel_font_small_;

	ofSoundPlayer winning_tune;
	ofSoundPlayer click;
	ofSoundPlayer losing_tune;
	ofSoundPlayer beginning_tune_;
	ofxPanel gui_;
	ofxButton candy_;
	ofxButton earthy_;
	ofImage heart_;

	void candyButtonPressed();
	void earthyButtonPressed();
	bool is_theme_candy_ = false;
	bool is_theme_earthy_ = false;

	bool is_life_available = true;
		
	void setup();

	void update();

	void draw();

	void drawBoard();

	void drawScore();

	void drawWin();

	void drawLoss();

	void drawReplayMessage();

	void drawBeginningStage();

	void drawTiles();

	void keyPressed(int key);
			
	void CheckGameOver();

	void initializeTileTheme();

	void ReturnToDefaults();
		
	const int kTileDimension = 100;
	const int kBackBoardDimension = 450;
	const int kSpacing = 10;

	bool should_update = true;
	bool should_move_board = false;
	GameState current_state = BEGIN;

	const std::string kBeginGame = "Press 'B' to begin 2048";
	const std::string kWonMessage = "You WON!";
	const std::string kLostMessage = "You lost";
	const std::string kReplayMessage = "Press 'N' to begin a new game";
	const std::string kResurrectMessage = "Press 'R' to resurrect";
	const std::string kInstructions = "Use keys 'W', 'A', 'S', 'D' to play";
	const std::string kScore = "SCORE: ";
	
	map<int, pair<float, float>> positions;
};