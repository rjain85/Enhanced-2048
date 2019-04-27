#pragma once

#include "ofMain.h"
#include "board.h"

class ofApp : public ofBaseApp {

	ofTrueTypeFont trench_font;
	ofSoundPlayer winning_tune;
	ofSoundPlayer click;

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
		void check_game_over();

		
		int tile_dimension = 100;
		int spacing = 10;
		bool should_update = true;
		bool game_won = false;
		bool game_lost = false;
		bool should_move_board = false;
		GameState current_state = BEGIN;

		const std::string kBeginGame = "Press 'B' to begin 2048";
		const std::string kScore = "Score: ";
		const std::string kWonMessage = "You WON!";
		const std::string kLostMessage = "You lost";
};