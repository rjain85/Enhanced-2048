#include "ofApp.h"
#include "board.h"


//--------------------------------------------------------------
Board board;

void ofApp::setup() {
	ofSetWindowTitle("2048");
	ofBackground(11, 182, 205);
	trench_font.load("trench100free.ttf", 35);

	winning_tune.load("CodyKoOutroSong.mp3");
	click.load("Stapler.mp3");
}

//--------------------------------------------------------------
void ofApp::update(){
	if (should_update == true) {
		if (current_state == SETUP) {
			board.SetUpGame();
			current_state = PLAY;
		}
		if (current_state == PLAY && should_move_board) {
			if (!board.BoardsAreEqual(board.board_, board.board_copy_)) {
				board.SpawnNewTwo(board.FindEmptyPositions());
			}
			board.CopyBoard(board.board_, board.board_copy_);
			cout << endl << "score: " << board.score_ << endl;

			board.RudimentaryPrint();
			click.play();
			cout << endl;
			check_game_over();
			if (game_won) {
				winning_tune.play();
			}
			should_move_board = false;
		}	
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255, 255, 255);
	if (current_state == BEGIN) {
		drawBeginningStage();
	} else if (current_state == PLAY) {
		drawBoard();
		drawScore();
	}
}

void ofApp::drawBoard() {
	float height = ofGetWindowHeight();
	float width = ofGetWindowWidth();
	float starting_point_x = (width / 2) - (2 * tile_dimension) - spacing;
	float starting_point_y = (height / 2) - (2 * tile_dimension) - spacing;
	int position_x = starting_point_x;
	int position_y = starting_point_y;

	for (int i = 0; i < board.kBoardDimension; i++) {
		for (int j = 0; j < board.kBoardDimension; j++) {
			ofDrawRectangle(position_x, position_y, tile_dimension, tile_dimension);
			position_x = position_x + tile_dimension + spacing;
		}
		position_x = starting_point_x;
		position_y = position_y + tile_dimension + spacing;
	}
}

void ofApp::drawScore() {
	trench_font.drawString(kScore + std::to_string(board.score_), 50, 50);
}

void ofApp::drawBeginningStage() {
	trench_font.drawString(kBeginGame, 50, 50);
}

// shout out to Elizabeth
void ofApp::keyPressed(int key){
	int input = toupper(key);
	if (current_state == BEGIN) {
		if (input == 'B') {
			cout << endl << 'b' << endl;
			current_state = SETUP;
			update();
		}
	} else if (current_state == PLAY) {
		if (input == 'A') {
			board.CompressLeft();
			board.MergeLeft();
			cout << endl << 'a';
			should_move_board = true;
			update();
		}
		if (input == 'W') {
			board.CompressUp();
			board.MergeUp();
			cout << endl << 'w';
			should_move_board = true;
			update();
		}
		if (input == 'D') {
			board.CompressRight();
			board.MergeRight();
			cout << endl << 'd';
			should_move_board = true;
			update();
		}
		if (input == 'S') {
			board.CompressDown();
			board.MergeDown();
			cout << endl << 's';
			should_move_board = true;
			update();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

void ofApp::check_game_over() {
	if (board.has_won) {
		should_update = false;
		game_won = true;
	} 
	if (board.HasLost()) {
		should_update = false;
		game_lost = true;
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
