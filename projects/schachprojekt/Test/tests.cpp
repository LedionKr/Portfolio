#include <gtest/gtest.h>

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../board.h"

TEST(AtomicLegalMove, Move) {
  // fatal
  // file with the data
  std::ifstream epd_file("/Users/ledionkrasniqi/CLionProjects/PK1/project/Test/TestData/atomicData.txt");
  ASSERT_TRUE(epd_file.good()) << "Der Pfad ist falsch";

  // Read data per line
  std::string line;
  while (std::getline(epd_file, line)) {
    std::istringstream ss(line);
    std::string setting;
    std::vector<std::string> settings;

    // Split line in sections
    while (std::getline(ss, setting, ';')) {
      settings.push_back(setting);
    }

    Board board;
    // Read in the board.
    board.readBoard(settings[0].substr(1));

    std::string& input = settings[1];

    // Build the move
    if (input[0] == 'M') {
      bool isCapture = false;
      char promotionFigure = ' ';
      const char figure = input[1];
      const int x = input[2] - 97;
      const int y = input[3] - 49;
      int movex = input[4] - 97;
      int movey = input[5] - 49;
      if (input[4] == 'x') {
        isCapture = true;
        movex = input[5] - 97;
        movey = input[6] - 49;
      }
      // Check for PawnPromotion
      if (input.length() > 6) {
        if (input[6] == '=') {
          promotionFigure = input[7];
        }
      }
      if (input.length() == 9 && isCapture) {
        if (input[7] == '=') {
          promotionFigure = input[8];
        }
      }
      bool atomicBoard = board.makeAtomicMove(figure, x, y, movex, movey, isCapture, promotionFigure);
      if (!atomicBoard) {
        std::cout << line << std::endl;
      }
      ASSERT_TRUE(atomicBoard);
    }
  }
}

TEST(LegalMove, Move) {
  // fatal
  // file with the data
  std::ifstream epd_file("/Users/ledionkrasniqi/CLionProjects/PK1/project/Test/TestData/standardData.txt");
  ASSERT_TRUE(epd_file.good()) << "Der Pfad ist falsch";

  // Read data per line
  std::string line;
  while (std::getline(epd_file, line)) {
    std::istringstream ss(line);
    std::string setting;
    std::vector<std::string> settings;

    // Split line in sections
    while (std::getline(ss, setting, ';')) {
      settings.push_back(setting);
    }

    Board board;
    // Read in the board.
    board.readBoard(settings[0].substr(1));

    std::string& input = settings[1];

    // Build the move
    if (input[0] == 'M') {
      bool isCapture = false;
      char promotionFigure = ' ';
      const char figure = input[1];
      const int x = input[2] - 97;
      const int y = input[3] - 49;
      int movex = input[4] - 97;
      int movey = input[5] - 49;
      if (input[4] == 'x') {
        isCapture = true;
        movex = input[5] - 97;
        movey = input[6] - 49;
      }
      // Check for PawnPromotion
      if (input.length() > 6) {
        if (input[6] == '=') {
          promotionFigure = input[7];
        }
      }
      if (input.length() == 9 && isCapture) {
        if (input[7] == '=') {
          promotionFigure = input[8];
        }
      }
      bool standardBoard = board.makeMove(figure, x, y, movex, movey, isCapture, promotionFigure);
      if (!standardBoard) {
        std::cout << line << std::endl;
      }
      ASSERT_TRUE(standardBoard);
    }
  }
}

/* Vorlage aus den Folien
TEST(TestSuiteName, TestName) {
  // fatal
  ASSERT_TRUE(condition);
  ASSERT_FALSE(condition);
  ASSERT_EQ(val1, val2);
  ASSERT_NE(val1, val2);
  // non-fatal
  EXPECT_EQ(val1, val2);
}
*/

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
