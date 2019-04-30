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

	ofTrueTypeFont pixel_font;
	ofSoundPlayer winning_tune;
	ofSoundPlayer click;
	ofSoundPlayer losing_tune;
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

	void drawBeginningStage();

	void drawTiles();

	void keyPressed(int key);

	void keyReleased(int key);

	void mouseMoved(int x, int y );

	void mouseDragged(int x, int y, int button);

	void mousePressed(int x, int y, int button);

	void mouseReleased(int x, int y, int button);
	
	void mouseEntered(int x, int y);
	
	void mouseExited(int x, int y);
	
	void windowResized(int w, int h);
	
	void dragEvent(ofDragInfo dragInfo);
	
	void gotMessage(ofMessage msg);
	
	void CheckGameOver();

	void initializeTileTheme();
		
	const int kTileDimension = 100;
	const int kBackBoardDimension = 450;
	const int kSpacing = 10;

	bool should_update = true;
	bool should_move_board = false;
	GameState current_state = BEGIN;

	const std::string kBeginGame = "Press 'B' to begin 2048";
	const std::string kScore = "Score: ";
	const std::string kWonMessage = "You WON!";
	const std::string kLostMessage = "You lost";

	map<int, pair<float, float>> positions;
	float x = (ofGetWindowWidth() / 2) - (2 * kTileDimension) - kSpacing;
	float y = (ofGetWindowHeight() / 2) - (2 * kTileDimension) - kSpacing;

};