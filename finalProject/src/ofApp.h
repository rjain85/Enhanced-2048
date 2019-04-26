#pragma once

#include "ofMain.h"
#include "game_math.h"

class ofApp : public ofBaseApp{

	ofTrueTypeFont trench_font;
	ofSoundPlayer sound_player;

	public:
		void setup();
		void update();
		void draw();

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

		int x = 0;
		int y = 0;
		bool should_update = false;

};