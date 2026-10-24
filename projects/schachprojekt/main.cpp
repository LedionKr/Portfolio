//
// Created by Ledion Krasniqi on 11.01.24.
//

#include <fstream>
#include <iostream>
#include <vector>

#include "./board.h"

/**
 * @brief Handles the end of the game based on the state of the king.
 * @param chessboard The current state of the chessboard.
 * @param player The player whose king to check.
 */
void handleGameEnd(Board chessboard, bool player) {
  if (chessboard.isKingCheck(player)) {
    if (chessboard.isKingCheckmate(player)) {
      std::cout << "king is in check mate" << std::endl;
      std::exit(0);
    } else {
      std::cout << "king is in check" << std::endl;
    }
  }
}

/**
 * @brief The main function of the program.
 * @return 0 if the program executed successfully.
 */
int main() {
  bool atomChess = false;
  std::cout << "Chosse your gamemode between \"Default\" and \"Atomchess\"" << std::endl;
  std::string input;
  std::cin >> input;
  if (input == "Atomchess") {
    atomChess = true;
  }

  Board chessboard;
  chessboard.printBoard();
  // std::cout << chessboard.arePossibleMoves('p', 6, 6, false);
  while (getline(std::cin, input)) {
    // The board will reset the former checkpoint and delete the newest one
    if (input == "undo") {
      chessboard.undo();
      chessboard.printBoard();
    }
    // ReadBoard, allows to upload a board
    if (input[0] == 'B') {
      chessboard.readBoard(input.substr(1));
      if (atomChess) {
        if (!chessboard.areKingsAlive()) {
          std::cout << "Game is over" << std::endl;
          std::exit(0);
        }
      } else {
        handleGameEnd(chessboard, false);
        handleGameEnd(chessboard, true);
      }
      continue;
    }

    // Print the valid moves of the <Piece> on the field <File><Row> to the standard out.
    if (input[0] == 'F') {
      const char figure = input[1];
      const int x = input[2] - 97;
      const int y = input[3] - 49;
      chessboard.printPossibleMoves(figure, x, y);
    }

    // For one move
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
      if (atomChess) {
        chessboard.makeAtomicMove(figure, x, y, movex, movey, isCapture, promotionFigure);
        if (!chessboard.areKingsAlive()) {
          std::cout << "Game is over" << std::endl;
          std::exit(0);
        }
      } else {
        if (!chessboard.makeMove(figure, x, y, movex, movey, isCapture, promotionFigure)) {
          std::cout << "invalid" << std::endl;
          handleGameEnd(chessboard, false);
          handleGameEnd(chessboard, true);
        }
      }
    }
  }
  return 0;
}
