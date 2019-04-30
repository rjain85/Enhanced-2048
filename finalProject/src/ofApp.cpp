#include "ofApp.h"
#include "board.h"


//--------------------------------------------------------------
Board board;

void ofApp::setup() {
	ofSetWindowTitle("2048");
	ofBackground(171, 197, 245);
	pixel_font.load("pixelmix.ttf", 35);
	SetUpTileMap();

	winning_tune.load("CodyKoOutroSong.mp3");
	click.load("Stapler.mp3");
	tile_two.load("2tile.png");
}

//--------------------------------------------------------------
void ofApp::update() {
	if (should_update == true) {
		if (current_state == SETUP) {
			board.SetUpGame();
			current_state = PLAY;
		}
		if (current_state == PLAY && should_move_board) {
			if (!board.AreBoardsEqual(board.board_, board.board_copy_)) {
				board.SpawnNewTwo(board.FindEmptyPositions());
			}
			board.CopyBoard(board.board_, board.board_copy_);
			cout << endl << "score: " << board.score_ << endl;

			board.RudimentaryPrint();		
			click.play();
			cout << endl;
			CheckGameOver();
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
		drawTiles();
	} else if (current_state == WIN) {
		drawBoard();
		drawTiles();
		drawWin();
	} else if (current_state == LOSS){
		drawBoard();
		drawTiles();
		drawLoss(); 
	}
}

void ofApp::drawBoard() {
	float height = ofGetWindowHeight();
	float width = ofGetWindowWidth();
	float starting_point_x = (width / 2) - (2 * kTileDimension) - kSpacing;
	float starting_point_y = (height / 2) - (2 * kTileDimension) - kSpacing;
	int position_x = starting_point_x;
	int position_y = starting_point_y;
	ofSetColor(214, 229, 255);
	ofDrawRectangle(starting_point_x - kSpacing, starting_point_y - kSpacing, kBackBoardDimension, kBackBoardDimension);
	ofSetColor(255, 255, 255);
	int counter = 1;
	for (int i = 0; i < board.kBoardDimension; i++) {
		for (int j = 0; j < board.kBoardDimension; j++) {
			ofDrawRectangle(position_x, position_y, kTileDimension, kTileDimension);
			positions[counter] = make_pair(position_x, position_y);

			position_x = position_x + kTileDimension + kSpacing;
			counter++;
		}
		position_x = starting_point_x;
		position_y = position_y + kTileDimension + kSpacing;
	}
}

void ofApp::drawScore() {
	pixel_font.drawString(kScore + std::to_string(board.score_), 50, 75);
}

void ofApp::drawWin() {
	pixel_font.drawString(kWonMessage, 50, 75);

}

void ofApp::drawLoss() {
	pixel_font.drawString(kLostMessage, 50, 75);
}

void ofApp::drawTiles() {
	int counter = 1;
	for (int i = 0; i < board.kBoardDimension; i++) {
		for (int j = 0; j < board.kBoardDimension; j++) {
			tiles[board.board_[i][j].value].draw(positions[counter].first, positions[counter].second);
			counter++;
		}
	}
}

void ofApp::drawBeginningStage() {
	pixel_font.drawString(kBeginGame, 50, 75);
}

// shout out to Elizabeth
void ofApp::keyPressed(int key) {
	int input = toupper(key);

	if (current_state == WIN || current_state == PLAY || current_state == LOSS) {
		if (input == 'N') {
			current_state = SETUP;
			should_update = true;
			cout << "new game plz";
		}	
	}
	if (current_state == BEGIN) {
		if (input == 'B') {
			cout << endl << 'b' << endl;
			current_state = SETUP;
		}
	} else if (current_state == PLAY) {
		if (input == 'A') {
			board.CompressLeft();
			board.MergeLeft();
			cout << endl << 'a';
			should_move_board = true;
		}
		if (input == 'W') {
			board.CompressUp();
			board.MergeUp();
			cout << endl << 'w';
			should_move_board = true;
		}
		if (input == 'D') {
			board.CompressRight();
			board.MergeRight();
			cout << endl << 'd';
			should_move_board = true;
		}
		if (input == 'S') {
			board.CompressDown();
			board.MergeDown();
			cout << endl << 's';
			should_move_board = true;
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

void ofApp::CheckGameOver() {
	if (board.has_won_) {
		should_update = false;
		current_state = WIN;
		winning_tune.play();
	} 
	if (board.HasLost()) {
		should_update = false;
		current_state = LOSS;
	}
}

void ofApp::SetUpTileMap() {
	tile_two.load("2f.png");
	tile_four.load("4f.png");
	tile_eight.load("8f.png");
	tile_sixteen.load("16f.png");
	tile_thirty_two.load("32f.png");
	tile_sixty_four.load("64f.png");
	tile_one_twenty_eight.load("128f.png");
	tile_two_fifty_six.load("256f.png");
	tile_five_twelve.load("512f.png");
	tile_ten_twenty_four.load("1024f.png");
	tile_twenty_forty_eight.load("2048f.png");

	tiles[2] = tile_two;
	tiles[4] = tile_four;
	tiles[8] = tile_eight;
	tiles[16] = tile_sixteen;
	tiles[32] = tile_thirty_two;
	tiles[64] = tile_sixty_four;
	tiles[128] = tile_one_twenty_eight;
	tiles[256] = tile_two_fifty_six;
	tiles[512] = tile_five_twelve;
	tiles[1024] = tile_ten_twenty_four;
	tiles[2048] = tile_twenty_forty_eight;
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
