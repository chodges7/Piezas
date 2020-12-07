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
