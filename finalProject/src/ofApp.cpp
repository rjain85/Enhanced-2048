#include "ofApp.h"
#include "board.h"


//--------------------------------------------------------------
Board board;

void ofApp::setup() {
	ofSetWindowTitle("2048");
	ofBackground(11, 182, 205);
	trench_font.load("trench100free.ttf", 35);

	sound_player.load("CodyKoOutroSong.mp3");
	sound_player.play();
	board.SetUpGame();

	//Board board;
	//boardy.LoopThroughGame();
}

//--------------------------------------------------------------
void ofApp::update(){
	//Board board;
	//boardy.LoopThroughGame();
	x++;
	y++;
	if (!should_update) {
		char input;
		cin >> input;
		keyPressed(input);
		if (!board.BoardsAreEqual(board.board_, board.board_copy_)) {
			board.SpawnNewTwo(board.FindEmptyPositions());
		}
		board.CopyBoard(board.board_, board.board_copy_);
		cout << endl << "score: " << board.score_ << endl;

		board.RudimentaryPrint();
		cout << endl;
		check_game_over();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);
	trench_font.drawString("Begin 2048", 50, 50);
	drawBoard();
	ofDrawRectangle(x, y, 100, 100);
}

void ofApp::drawBoard() {
	float height = ofGetWindowHeight();
	float width = ofGetWindowWidth();
	float starting_point_x = (width / 2) - (2 * tile_dimension) - spacing;
	float starting_point_y = (height / 2) - (2 * tile_dimension) - spacing;
	//ofDrawRectangle(width/2, height/2, 100, 100);
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

// shout out to Elizabeth
void ofApp::keyPressed(int key){
	int input = toupper(key);
	if (input == 'A') {
		board.CompressLeft();
		board.MergeLeft();
	}
	if (input == 'W') {
		board.CompressUp();
		board.MergeUp();
	}
	if (input == 'D') {
		board.CompressRight();
		board.MergeRight();
	}
	if (input == 'S') {
		board.CompressDown();
		board.MergeDown();
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
		should_update = true;
	} 
	if (board.HasLost()) {
		should_update = true;
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
