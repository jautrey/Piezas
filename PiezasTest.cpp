/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, colHigh)
{
  Piezas p;
	ASSERT_EQ(p.dropPiece(-1), Invalid);
}

TEST(PiezasTest, colLow)
{
  Piezas p;
	ASSERT_EQ(p.dropPiece(4), Invalid);
}

TEST(PiezasTest, dropPieceFirstCol)
{
  Piezas p;
	ASSERT_EQ(p.dropPiece(0), X);
}

TEST(PiezasTest, dropPieceFourthCol)
{
  Piezas p;
	ASSERT_EQ(p.dropPiece(3), X);
}

TEST(PiezasTest, dropPieceSecond)
{
  Piezas p;
  p.dropPiece(2);
	ASSERT_EQ(p.dropPiece(1), O);
}

TEST(PiezasTest, dropPieceThird)
{
  Piezas p;
  p.dropPiece(2);
  p.dropPiece(2);
	ASSERT_EQ(p.dropPiece(2), X);
}

TEST(PiezasTest, rowOverflow)
{
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(0);
	ASSERT_EQ(p.dropPiece(0), Invalid);
}

TEST(PiezasTest, pieceRowOne)
{
  Piezas p;
  p.dropPiece(0);
	ASSERT_EQ(p.pieceAt(0,0), X);
}

TEST(PiezasTest, dropThreeRowOne)
{
  Piezas p;
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(1);
	ASSERT_EQ(p.pieceAt(0,1), X);
}

TEST(PiezasTest, pieceRowTwo)
{
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(0);
	ASSERT_EQ(p.pieceAt(1,0), O);
}

TEST(PiezasTest, pieceRowThree)
{
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(0);
	ASSERT_EQ(p.pieceAt(2,0), X);
}

TEST(PiezasTest, dropPieces1)
{
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
	ASSERT_EQ(p.pieceAt(1,0), O);
}

TEST(PiezasTest, checkBlankPiece)
{
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
	ASSERT_EQ(p.pieceAt(2,0), Blank);
}

TEST(PiezasTest, resetBoard)
{
  Piezas p;
  p.reset();
	ASSERT_EQ(p.pieceAt(0,0), Blank);
}

TEST(PiezasTest, resetFullBoard)
{
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(3);
  p.reset();
	ASSERT_EQ(p.pieceAt(2,2), Blank);
}

TEST(PiezasTest, gameNotOver)
{
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(3);
	ASSERT_EQ(p.gameState(), Invalid);
}

TEST(PiezasTest, TieGame)
{
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(2);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(3);
  p.dropPiece(3);
	ASSERT_EQ(p.gameState(), Blank);
}

TEST(PiezasTest, Xwins)
{
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(0);
  p.dropPiece(2);
  p.dropPiece(0);
  p.dropPiece(3);
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(3);
	ASSERT_EQ(p.gameState(), X);
}

TEST(PiezasTest, Owins)
{
  Piezas p;
  p.dropPiece(1);
  p.dropPiece(0);
  p.dropPiece(2);
  p.dropPiece(0);
  p.dropPiece(3);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(2);
  p.dropPiece(2);
  p.dropPiece(3);
  p.dropPiece(3);
	ASSERT_EQ(p.gameState(), O);
}
