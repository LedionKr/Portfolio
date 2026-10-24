//
// Created by Ledion Krasniqi on 27.03.24.
//

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "./Movement/movement.h"

class Board {
 public:
  Board() { BoardHistory.push_back(ChessBoard); }

  /**
   * @brief Checks if the king of the given player is in check.
   * @param player The player whose king to check.
   * @return true if the king is in check, false otherwise.
   */
  bool isKingCheck(bool player);

  /**
   * @brief Reads the FEN-Code
   * @param input string FEN-Code
   */
  void readBoard(const std::string &input);

  /**
   * @brief Prints the possible moves for a given piece at a given position.
   * @param figure The piece to check.
   * @param x The current x position of the piece.
   * @param y The current y position of the piece.
   */
  void printPossibleMoves(char figure, int x, int y);

  /**
   * @brief Checks if there are possible moves for a given piece at a given position.
   * @param figure The piece to check.
   * @param x The current x position of the piece.
   * @param y The current y position of the piece.
   * @param player The player to check.
   * @return true if there are possible moves, false otherwise.
   */
  bool arePossibleMoves(char figure, int x, int y, bool player);

  /**
   * @brief Checks if the king of the given player is in checkmate.
   * @param player The player whose king to check.
   * @return true if the king is in checkmate, false otherwise.
   */
  bool isKingCheckmate(bool player);

  /**
   * @brief Undoes the last move.
   * @return true if the move was undone, false otherwise.
   */
  bool undo();
  bool PlayerW = true;

  /**
   * @brief Makes a move with a given piece from a given position to a given position.
   * @param figure The piece to move.
   * @param x The current x position of the piece.
   * @param y The current y position of the piece.
   * @param movex The x position to move to.
   * @param movey The y position to move to.
   * @param isCapture Indicates if the move is a capture.
   * @param promotionFigure The figure to promote to.
   * @return true if the move was made, false otherwise.
   */
  bool makeMove(char figure, int x, int y, int movex, int movey, bool isCapture, char promotionFigure);

  /**
   * @brief Checks if both kings are alive.
   * @return true if both kings are alive, false otherwise.
   */
  bool areKingsAlive();

  /**
   * @brief Counts the number of kings in the surroundings of a given position.
   * @param movex The x position to check.
   * @param movey The y position to check.
   * @return The number of kings in the surroundings.
   */
  int kingCounter(int movex, int movey);

  /**
   * @brief Explodes the surroundings of a given position.
   * @param movex The x position to explode.
   * @param movey The y position to explode.
   */
  void explodeSurroundings(int movex, int movey);

  /**
   * @brief Makes an atomic move with a given piece from a given position to a given position.
   * @param figure The piece to move.
   * @param x The current x position of the piece.
   * @param y The current y position of the piece.
   * @param movex The x position to move to.
   * @param movey The y position to move to.
   * @param isCapture Indicates if the move is a capture.
   * @param promotionFigure The figure to promote to.
   * @return true if the move was made, false otherwise.
   */
  bool makeAtomicMove(char figure, int x, int y, int movex, int movey, bool isCapture, char promotionFigure);

  /**
   * @brief Prints the current state of the board.
   */
  void printBoard();

 private:
  std::vector<std::vector<char>> ChessBoard = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},   // row 1
                                               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},   // row 2
                                               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},   // row 3
                                               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},   // row 4
                                               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},   // row 5
                                               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},   // row 6
                                               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},   // row 7
                                               {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};  // row 8
  // Safe the game history, the history of the chessboard
  std::vector<std::vector<std::vector<char>>> BoardHistory;
};
