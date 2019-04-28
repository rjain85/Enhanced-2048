#pragma once

#include "ofMain.h"
#include "board.h"

class ofApp : public ofBaseApp {

	ofTrueTypeFont trench_font;
	ofSoundPlayer winning_tune;
	ofSoundPlayer click;
	ofImage tile_two;
	ofImage tile_four;
	ofImage tile_eight;
	ofImage tile_sixteen;
	ofImage tile_thirty_two;
	ofImage tile_sixty_four;
	ofImage tile_one_twenty_eight;
	ofImage tile_two_fifty_six;
	ofImage tile_five_twelve;
	ofImage tile_ten_twenty_four;
	ofImage tile_twenty_forty_eight;

	private:
		enum GameState {
			BEGIN,
			SETUP,
			PLAY,
			WIN,
			LOSS
		};

	public:
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
		void SetUpTileMap();
		
		const int kTileDimension = 100;
		const int kBackBoardDimension = 450;
		int spacing = 10;
		bool should_update = true;
		bool should_move_board = false;
		GameState current_state = BEGIN;

		const std::string kBeginGame = "Press 'B' to begin 2048";
		const std::string kScore = "Score: ";
		const std::string kWonMessage = "You WON!";
		const std::string kLostMessage = "You lost";

		map<int, ofImage> tiles;
		map<int, ofImage>::iterator tile_to_draw;
		map<int, pair<float, float>> positions;
		float x = (ofGetWindowWidth() / 2) - (2 * kTileDimension) - spacing;
		float y = (ofGetWindowHeight() / 2) - (2 * kTileDimension) - spacing;

};