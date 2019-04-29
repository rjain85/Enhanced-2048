#include "ofApp.h"
#include "board.h"


//--------------------------------------------------------------
Board board;

void ofApp::setup() {
	ofSetWindowTitle("2048");
	ofBackground(171, 197, 245);
	trench_font.load("trench100free.ttf", 35);
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
			if (!board.BoardsAreEqual(board.board_, board.board_copy_)) {
				board.SpawnNewTwo(board.FindEmptyPositions());
			}
			board.CopyBoard(board.board_, board.board_copy_);
			cout << endl << "score: " << board.score_ << endl;

			board.RudimentaryPrint();
			/*for (int i = 0; i < 330; i++) {
				x = x + 1;
			}	*/		
			click.play();
			cout << endl;
			CheckGameOver();
			should_move_board = false;
		}	
		/*if (current_state == SLIDE) {

		}*/
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
		//tile_two.draw(x, y);
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
	float starting_point_x = (width / 2) - (2 * kTileDimension) - spacing;
	float starting_point_y = (height / 2) - (2 * kTileDimension) - spacing;
	int position_x = starting_point_x;
	int position_y = starting_point_y;
	ofSetColor(214, 229, 255);
	ofDrawRectangle(starting_point_x - spacing, starting_point_y - spacing, kBackBoardDimension, kBackBoardDimension);
	ofSetColor(255, 255, 255);
	int counter = 1;
	for (int i = 0; i < board.kBoardDimension; i++) {
		for (int j = 0; j < board.kBoardDimension; j++) {
			ofDrawRectangle(position_x, position_y, kTileDimension, kTileDimension);
			//update positions map before continuing to draw board
			positions[counter] = make_pair(position_x, position_y);

			position_x = position_x + kTileDimension + spacing;
			counter++;
		}
		position_x = starting_point_x;
		position_y = position_y + kTileDimension + spacing;
	}
}

void ofApp::drawScore() {
	trench_font.drawString(kScore + std::to_string(board.score_), 50, 50);
}

void ofApp::drawWin() {
	trench_font.drawString(kWonMessage, 50, 50);

}

void ofApp::drawLoss() {
	trench_font.drawString(kLostMessage, 50, 50);
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
	trench_font.drawString(kBeginGame, 50, 50);
}

// shout out to Elizabeth
void ofApp::keyPressed(int key) {
	int input = toupper(key);
	if (current_state == BEGIN) {
		if (input == 'B') {
			cout << endl << 'b' << endl;
			current_state = SETUP;
			//update();
		}
	} else if (current_state == PLAY) {
		if (input == 'A') {
			board.CompressLeft();
			board.MergeLeft();
			cout << endl << 'a';
			should_move_board = true;
			//update();
		}
		if (input == 'W') {
			board.CompressUp();
			board.MergeUp();
			cout << endl << 'w';
			should_move_board = true;
			//update();
		}
		if (input == 'D') {
			board.CompressRight();
			board.MergeRight();
			cout << endl << 'd';
			should_move_board = true;
			//update();
		}
		if (input == 'S') {
			board.CompressDown();
			board.MergeDown();
			cout << endl << 's';
			should_move_board = true;
			//update();
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
	if (board.has_won) {
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
	tile_two.load("2tile.png");
	tile_four.load("4tile.png");
	tile_eight.load("8tile.png");
	tile_sixteen.load("16tile.png");
	tile_thirty_two.load("32tile.png");
	tile_sixty_four.load("64tile.png");
	tile_one_twenty_eight.load("128tile.png");
	tile_two_fifty_six.load("256tile.png");
	tile_five_twelve.load("512tile.png");
	tile_ten_twenty_four.load("1024tile.png");
	tile_twenty_forty_eight.load("2048tile.png");

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

/** ofApp::Slide() {
	for (int i = 0; i < board.kBoardDimension; i++) {
		for (int j = 0; j < board.kBoardDimension; j++) {
			if (board.board_[i][j].value >= board.board_copy_[i][j].value && board.board_[i][j].contributors.size() > 0) {
				//tiles[board.board_copy_[i][j].value].draw(positions[counter].first, positions[counter].second);
				counter++;
			}
		}
	}
}**/

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
