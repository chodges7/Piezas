/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test {
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck) {
	ASSERT_TRUE(true);
}

TEST(PiezasTest, pieceAt_invalid_row_low) {
  Piezas myPiezas;
  Piece out;
  int row = -5;
  int col = 0;

  out = myPiezas.pieceAt(row, col);

	ASSERT_EQ(out, Invalid);
}

TEST(PiezasTest, pieceAt_invalid_row_high) {
  Piezas myPiezas;
  Piece out;
  int row = 17;
  int col = 0;

  out = myPiezas.pieceAt(row, col);

	ASSERT_EQ(out, Invalid);
}

TEST(PiezasTest, pieceAt_invalid_col_low) {
  Piezas myPiezas;
  Piece out;
  int row = 0;
  int col = -26;

  out = myPiezas.pieceAt(row, col);

	ASSERT_EQ(out, Invalid);
}

TEST(PiezasTest, pieceAt_invalid_col_high) {
  Piezas myPiezas;
  Piece out;
  int row = 0;
  int col = 9;

  out = myPiezas.pieceAt(row, col);

	ASSERT_EQ(out, Invalid);
}

TEST(PiezasTest, pieceAt_invalid_both_low) {
  Piezas myPiezas;
  Piece out;
  int row = -8;
  int col = -8;

  out = myPiezas.pieceAt(row, col);

	ASSERT_EQ(out, Invalid);
}

TEST(PiezasTest, pieceAt_invalid_both_high) {
  Piezas myPiezas;
  Piece out;
  int row = 88;
  int col = 88;

  out = myPiezas.pieceAt(row, col);

	ASSERT_EQ(out, Invalid);
}

TEST(PiezasTest, pieceAt_valid_blank) {
  Piezas myPiezas;
  Piece out;
  int row = 0;
  int col = 0;

  out = myPiezas.pieceAt(row, col);

	ASSERT_EQ(out, Blank);
}

TEST(PiezasTest, pieceAt_valid_X) {
  Piezas myPiezas;
  Piece out;
  int row = 2;
  int col = 0;

  myPiezas.dropPiece(col);
  out = myPiezas.pieceAt(row, col);

	ASSERT_EQ(out, X);
}

TEST(PiezasTest, pieceAt_valid_O) {
  Piezas myPiezas;
  Piece out;
  int row = 2;
  int col = 1;

  myPiezas.dropPiece(col * -1); // get it to be O's turn
  myPiezas.dropPiece(col);
  out = myPiezas.pieceAt(row, col);

	ASSERT_EQ(out, O);
}

TEST(PiezasTest, reset_test) {
  Piezas myPiezas;
  Piece out;
  int row = 2;
  int col = 0;

  myPiezas.dropPiece(col); // first place a piece
	myPiezas.reset(); // then reset the board
  out = myPiezas.pieceAt(row, col); // then double check if the piece is there

	ASSERT_EQ(out, Blank);
}

TEST(PiezasTest, dropPiece_valid_col_0) {
  Piezas myPiezas;
  Piece out;
  int row = 2;
  int col = 0;

  myPiezas.dropPiece(col);
  out = myPiezas.pieceAt(row, col);

	ASSERT_EQ(out, X);
}

TEST(PiezasTest, dropPiece_valid_col_1) {
  Piezas myPiezas;
  Piece out;
  int row = 2;
  int col = 1;

  myPiezas.dropPiece(col);
  out = myPiezas.pieceAt(row, col);

	ASSERT_EQ(out, X);
}

TEST(PiezasTest, dropPiece_valid_col_2) {
  Piezas myPiezas;
  Piece out;
  int row = 2;
  int col = 2;

  myPiezas.dropPiece(col);
  out = myPiezas.pieceAt(row, col);

	ASSERT_EQ(out, X);
}

TEST(PiezasTest, dropPiece_valid_col_3) {
  Piezas myPiezas;
  Piece out;
  int row = 2;
  int col = 3;

  myPiezas.dropPiece(col);
  out = myPiezas.pieceAt(row, col);

	ASSERT_EQ(out, X);
}

TEST(PiezasTest, dropPiece_invalid_col) {
  Piezas myPiezas;
  Piece out;
  int row = 2;
  int col = 10;

  myPiezas.dropPiece(col);
  out = myPiezas.pieceAt(row, col);

	ASSERT_EQ(out, Invalid);
}

TEST(PiezasTest, gameState_test_Invalid) {
  Piezas myPiezas;
  Piece out;
  int col = 0;

  myPiezas.dropPiece(col);
  out = myPiezas.gameState();

	ASSERT_EQ(out, Invalid);
}

TEST(PiezasTest, gameState_test_valid_Blank) {
  Piezas myPiezas;
  Piece out;
	int col_0 = 0;
  int col_1 = 1;
	int col_2 = 2;
	int col_3 = 3;

  myPiezas.dropPiece(col_0); // fill up board
	myPiezas.dropPiece(col_2);
	myPiezas.dropPiece(col_1);
	myPiezas.dropPiece(col_3);

	myPiezas.dropPiece(col_0); // copy paste 1
	myPiezas.dropPiece(col_2);
	myPiezas.dropPiece(col_1);
	myPiezas.dropPiece(col_3);

	myPiezas.dropPiece(col_0); // copy paste 2
	myPiezas.dropPiece(col_2);
	myPiezas.dropPiece(col_1);
	myPiezas.dropPiece(col_3);

  out = myPiezas.gameState();

	ASSERT_EQ(out, Blank);
}

TEST(PiezasTest, gameState_test_valid_X) {
  Piezas myPiezas;
  Piece out;
	int col_0 = 0;
  int col_1 = 1;
	int col_2 = 2;
	int col_3 = 3;

  myPiezas.dropPiece(col_0); // fill up board
	myPiezas.dropPiece(col_1);
	myPiezas.dropPiece(col_3);
	myPiezas.dropPiece(col_2);

	myPiezas.dropPiece(col_0);
	myPiezas.dropPiece(col_1);
	myPiezas.dropPiece(col_2);
	myPiezas.dropPiece(col_3);

	myPiezas.dropPiece(col_0);
	myPiezas.dropPiece(col_2);
	myPiezas.dropPiece(col_1);
	myPiezas.dropPiece(col_3);

  out = myPiezas.gameState();

	ASSERT_EQ(out, O);
}

TEST(PiezasTest, gameState_test_valid_O) {
  Piezas myPiezas;
  Piece out;
	int col_0 = 0;
  int col_1 = 1;
	int col_2 = 2;
	int col_3 = 3;

  myPiezas.dropPiece(col_2); // fill up board
	myPiezas.dropPiece(col_0);
	myPiezas.dropPiece(col_3);
	myPiezas.dropPiece(col_1);

	myPiezas.dropPiece(col_3);
	myPiezas.dropPiece(col_2);
	myPiezas.dropPiece(col_1);
	myPiezas.dropPiece(col_0);

	myPiezas.dropPiece(col_1);
	myPiezas.dropPiece(col_0);
	myPiezas.dropPiece(col_2);
	myPiezas.dropPiece(col_3);

  out = myPiezas.gameState();

	ASSERT_EQ(out, X);
}
