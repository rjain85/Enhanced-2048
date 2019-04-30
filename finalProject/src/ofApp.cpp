#include "ofApp.h"
#include "board.h"
#include "theme.h"


//--------------------------------------------------------------
Board board;
Theme theme;

void ofApp::setup() {
	ofSetWindowTitle("2048");
	ofBackground(171, 197, 245);
	pixel_font_.load("pixelmix.ttf", 35);
	pixel_font_small_.load("pixelmix.ttf", 18);
	gui_.setup("Select Theme");
	candy_.addListener(this, &ofApp::candyButtonPressed);
	earthy_.addListener(this, &ofApp::earthyButtonPressed);
	heart_.load("pixelheart.gif");
	theme.LoadCandyTiles();
	theme.LoadEarthyTiles();

	winning_tune.load("CodyKoOutroSong.mp3");
	losing_tune.load("AllStar.mp3");
	click.load("Stapler.mp3");

	gui_.add(candy_.setup("CANDY"));
	gui_.add(earthy_.setup("EARTHY"));

}

//--------------------------------------------------------------
void ofApp::update() {
	if (should_update == true) {
		if (current_state == SETUP) {
			initializeTileTheme();
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
		gui_.draw();

	} else if (current_state == PLAY) {
		if (is_life_available) {
			heart_.draw(ofGetWindowWidth() - 150, 2, 125, 125);
		}
		drawBoard();
		drawScore();
		drawTiles();
		drawReplayMessage();

	} else if (current_state == WIN) {
		drawBoard();
		drawTiles();
		drawWin();

	} else if (current_state == LOSS) {
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
	pixel_font_.drawString(kScore + std::to_string(board.score_), 50, 75);
}

void ofApp::drawWin() {
	pixel_font_.drawString(kWonMessage, 50, 75);
	drawReplayMessage();
}

void ofApp::drawLoss() {
	pixel_font_.drawString(kLostMessage, 50, 75);
	drawReplayMessage();
	if (is_life_available) {
		pixel_font_small_.drawString(kResurrectMessage, 50, ofGetHeight() - 75);
	}
}

void ofApp::drawReplayMessage() {
	pixel_font_small_.drawString(kReplayMessage, 50, ofGetHeight() - 35);
}

void ofApp::drawTiles() {
	int counter = 1;
	for (int i = 0; i < board.kBoardDimension; i++) {
		for (int j = 0; j < board.kBoardDimension; j++) {
			theme.tiles[board.board_[i][j].value].draw(positions[counter].first, positions[counter].second);
			counter++;
		}
	}
}

void ofApp::drawBeginningStage() {
	pixel_font_.drawString(kBeginGame, 50, 150);
	pixel_font_.drawString(kInstructions, 50, 225);
}

// shout out to Elizabeth
void ofApp::keyPressed(int key) {
	int input = toupper(key);

	if (current_state == WIN || current_state == PLAY || current_state == LOSS) {
		if (input == 'N') {
			winning_tune.stop();
			losing_tune.stop();
			should_update = true;
			board.has_won_ = false;
			is_theme_candy_ = false;
			is_theme_earthy_ = false;
			current_state = BEGIN;
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
	} else if (current_state == LOSS && is_life_available && input == 'R') {
		board.ResurrectPlayer();
		is_life_available = false;
		should_update = true;
		winning_tune.stop();
		losing_tune.stop();
		current_state = PLAY;
	}
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
		losing_tune.play();
	}
}

void ofApp::initializeTileTheme() {
	if (is_theme_candy_ && !is_theme_earthy_ || is_theme_candy_ && is_theme_earthy_ || !is_theme_candy_ && !is_theme_earthy_) {
		theme.SetUpCandyTileMap();
	} else {
		theme.SetUpEarthyTileMap();
	}
}

void ofApp::candyButtonPressed() {
	if (is_theme_candy_) {
		is_theme_candy_ = false;
	} else {
		is_theme_candy_ = true;
	}
}

void ofApp::earthyButtonPressed() {
	if (is_theme_earthy_) {
		is_theme_earthy_ = false;
	} else {
		is_theme_earthy_ = true;
	}
}