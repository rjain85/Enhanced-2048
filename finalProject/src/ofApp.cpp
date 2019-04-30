#include "ofApp.h"
#include "board.h"
#include "theme.h"


//--------------------------------------------------------------
Board board;
Theme theme;

void ofApp::setup() {
	ofSetWindowTitle(kName);
	ofBackground(171, 197, 245);

	pixel_font_large_.load(kPixelFont, kLargeFontSize);
	pixel_font_small_.load(kPixelFont, kSmallFontSize);

	gui_.setup(kThemeLabel);
	candy_.addListener(this, &ofApp::CandyButtonPressed);
	earthy_.addListener(this, &ofApp::EarthyButtonPressed);
	gui_.add(candy_.setup(kCandyLabel));
	gui_.add(earthy_.setup(kEarthyLabel));

	heart_.load(kHeartImage);
	theme.LoadCandyTiles();
	theme.LoadEarthyTiles();

	winning_tune_.load(kWinningTune);
	losing_tune_.load(kLosingTune);
	beginning_tune_.load(kBeginningTune);
	click_.load(kClick);

	beginning_tune_.play();
}

//--------------------------------------------------------------
void ofApp::update() {
	if (should_update_ == true) {
		if (current_state_ == SETUP) {
			InitTileTheme();
			board.SetUpGame();
			current_state_ = PLAY;
		}
		if (current_state_ == PLAY && should_move_board_) {
			if (!board.AreBoardsEqual(board.board_, board.board_copy_)) {
				board.SpawnNewTwo(board.FindEmptyPositions());
			}
			board.CopyBoard(board.board_, board.board_copy_);	
			click_.play();
			cout << endl;
			CheckGameOver();
			should_move_board_ = false;
		}	
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255, 255, 255);
	if (current_state_ == BEGIN) {
		DrawBeginningStage();
		gui_.draw();

	} else if (current_state_ == PLAY) {
		if (is_life_available) {
			heart_.draw(ofGetWindowWidth() - 150, 2, 125, 125);
		}
		DrawBoard();
		DrawScore();
		DrawTiles();
		DrawReplayMessage();

	} else if (current_state_ == WIN) {
		DrawBoard();
		DrawTiles();
		DrawWin();

	} else if (current_state_ == LOSS) {
		DrawBoard();
		DrawTiles();
		DrawLoss(); 
	}
}

void ofApp::DrawBoard() {
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
			positions_[counter] = make_pair(position_x, position_y);

			position_x = position_x + kTileDimension + kSpacing;
			counter++;
		}
		position_x = starting_point_x;
		position_y = position_y + kTileDimension + kSpacing;
	}
}

void ofApp::DrawScore() {
	pixel_font_large_.drawString(kScore + std::to_string(board.score_), 50, 75);
}

void ofApp::DrawWin() {
	pixel_font_large_.drawString(kWonMessage, 50, 75);
	DrawReplayMessage();
}

void ofApp::DrawLoss() {
	pixel_font_large_.drawString(kLostMessage, 50, 75);
	DrawReplayMessage();
	if (is_life_available) {
		pixel_font_small_.drawString(kResurrectMessage, 50, ofGetHeight() - 75);
	}
}

void ofApp::DrawReplayMessage() {
	pixel_font_small_.drawString(kReplayMessage, 50, ofGetHeight() - 35);
}

void ofApp::DrawTiles() {
	int counter = 1;
	for (int i = 0; i < board.kBoardDimension; i++) {
		for (int j = 0; j < board.kBoardDimension; j++) {
			theme.tiles[board.board_[i][j].value].draw(positions_[counter].first, positions_[counter].second);
			counter++;
		}
	}
}

void ofApp::DrawBeginningStage() {
	pixel_font_large_.drawString(kBeginGame, 50, 150);
	pixel_font_large_.drawString(kInstructions, 50, 225);
}

// shout out to Elizabeth
void ofApp::keyPressed(int key) {
	int input = toupper(key);

	if (current_state_ == WIN || current_state_ == PLAY || current_state_ == LOSS) {
		if (input == 'N') {
			winning_tune_.stop();
			losing_tune_.stop();
			beginning_tune_.play();
			ReturnToDefaults();
		}	
	}
	if (current_state_ == BEGIN) {
		if (input == 'B') {
			current_state_ = SETUP;
			beginning_tune_.stop();
		}
	} else if (current_state_ == PLAY) {
		if (input == 'A') {
			board.CompressLeft();
			board.MergeLeft();
			should_move_board_ = true;
		}
		if (input == 'W') {
			board.CompressUp();
			board.MergeUp();
			should_move_board_ = true;
		}
		if (input == 'D') {
			board.CompressRight();
			board.MergeRight();
			should_move_board_ = true;
		}
		if (input == 'S') {
			board.CompressDown();
			board.MergeDown();
			should_move_board_ = true;
		}
	} else if (current_state_ == LOSS && is_life_available && input == 'R') {
		board.ResurrectPlayer();
		is_life_available = false;
		should_update_ = true;
		winning_tune_.stop();
		losing_tune_.stop();
		current_state_ = PLAY;
	}
}


void ofApp::CheckGameOver() {
	if (board.has_won_) {
		should_update_ = false;
		current_state_ = WIN;
		winning_tune_.play();
	} 
	if (board.HasLost()) {
		should_update_ = false;
		current_state_ = LOSS;
		losing_tune_.play();
	}
}

void ofApp::InitTileTheme() {
	if (is_theme_candy_ && !is_theme_earthy_ || is_theme_candy_ && is_theme_earthy_ || !is_theme_candy_ && !is_theme_earthy_) {
		theme.SetUpCandyTileMap();
	} else {
		theme.SetUpEarthyTileMap();
	}
}

void ofApp::ReturnToDefaults() {
	should_update_ = true;
	is_life_available = true;
	board.has_won_ = false;
	is_theme_candy_ = false;
	is_theme_earthy_ = false;
	current_state_ = BEGIN;
}

void ofApp::CandyButtonPressed() {
	if (is_theme_candy_) {
		is_theme_candy_ = false;
	} else {
		is_theme_candy_ = true;
	}
}

void ofApp::EarthyButtonPressed() {
	if (is_theme_earthy_) {
		is_theme_earthy_ = false;
	} else {
		is_theme_earthy_ = true;
	}
}