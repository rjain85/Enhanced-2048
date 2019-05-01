/*  #pragma once
#define CATCH_CONFIG_MAIN

#include "catch.hpp";
#include "board.h";

Board tester;

TEST_CASE("Check if CompressLeft and MergeLeft operate correctly") {
	tester.InitBoard();
	tester.board_[0][0].value = 0;
	tester.board_[0][1].value = 0;
	tester.board_[0][2].value = 0;
	tester.board_[0][3].value = 0;
	tester.board_[1][0].value = 0;
	tester.board_[1][1].value = 0;
	tester.board_[1][2].value = 2;
	tester.board_[1][3].value = 0;
	tester.board_[2][0].value = 0;
	tester.board_[2][1].value = 0;
	tester.board_[2][2].value = 0;
	tester.board_[2][3].value = 4;
	tester.board_[3][0].value = 2;
	tester.board_[3][1].value = 0;
	tester.board_[3][2].value = 8;
	tester.board_[3][3].value = 2;

	tester.CompressLeft();
	tester.MergeLeft();

	REQUIRE (tester.board_[0][0].value == 0);
	REQUIRE (tester.board_[0][1].value == 0);
	REQUIRE (tester.board_[0][2].value == 0);
	REQUIRE (tester.board_[0][3].value == 0);
	REQUIRE (tester.board_[1][0].value == 2);
	REQUIRE (tester.board_[1][1].value == 0);
	REQUIRE (tester.board_[1][2].value == 0);
	REQUIRE (tester.board_[1][3].value == 0);
	REQUIRE (tester.board_[2][0].value == 4);
	REQUIRE (tester.board_[2][1].value == 0);
	REQUIRE (tester.board_[2][2].value == 0);
	REQUIRE (tester.board_[2][3].value == 0);
	REQUIRE (tester.board_[3][0].value == 2);
	REQUIRE (tester.board_[3][1].value == 8);
	REQUIRE (tester.board_[3][2].value == 2);
	REQUIRE (tester.board_[3][3].value == 0);

}*/