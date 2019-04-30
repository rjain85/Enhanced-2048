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

	void setup();

	void update();

	void draw();

	void DrawBoard();

	void DrawScore();

	void DrawWin();

	void DrawLoss();

	void DrawReplayMessage();

	void DrawBeginningStage();

	void DrawTiles();

	void keyPressed(int key);
			
	void CheckGameOver();

	void InitTileTheme();

	void ReturnToDefaults();

	void CandyButtonPressed();

	void EarthyButtonPressed();

	const std::string kName = "Enhanced 2048";

	ofTrueTypeFont pixel_font_large_;
	ofTrueTypeFont pixel_font_small_;

	const std::string kPixelFont = "pixelmix.ttf";
	const int kLargeFontSize = 35;
	const int kSmallFontSize = 18;

	ofSoundPlayer winning_tune_;
	ofSoundPlayer click_;
	ofSoundPlayer losing_tune_;
	ofSoundPlayer beginning_tune_;

	const std::string kBeginningTune = "ilomilo.mp3";
	const std::string kClick = "Stapler.mp3";
	const std::string kLosingTune = "AllStar.mp3";
	const std::string kWinningTune = "CodyKoOutroSong.mp3";

	ofxPanel gui_;
	ofxButton candy_;
	ofxButton earthy_;

	const std::string kThemeLabel = "Select Theme";
	const std::string kCandyLabel = "CANDY";
	const std::string kEarthyLabel = "EARTHY";

	ofImage heart_;

	const std::string kHeartImage = "pixelheart.gif";

	bool is_theme_candy_ = false;
	bool is_theme_earthy_ = false;

	bool is_life_available = true;
		
	const int kTileDimension = 100;
	const int kBackBoardDimension = 450;
	const int kSpacing = 10;

	bool should_update_ = true;
	bool should_move_board_ = false;
	GameState current_state_ = BEGIN;

	const std::string kBeginGame = "Press 'B' to begin 2048";
	const std::string kWonMessage = "You WON!";
	const std::string kLostMessage = "You lost";
	const std::string kReplayMessage = "Press 'N' to begin a new game";
	const std::string kResurrectMessage = "Press 'R' to resurrect";
	const std::string kInstructions = "Use keys 'W', 'A', 'S', 'D' to play";
	const std::string kScore = "SCORE: ";
	
	map<int, pair<float, float>> positions_;
};