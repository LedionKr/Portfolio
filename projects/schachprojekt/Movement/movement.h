//
// Created by Ledion Krasniqi on 27.03.24.
//

#pragma once
#include <vector>

/**
 * @brief Checks if a pawn can move to a given position.
 * @param x The current x position of the pawn.
 * @param y The current y position of the pawn.
 * @param movex The x position to move to.
 * @param movey The y position to move to.
 * @param isCapture Indicates if the move is a capture.
 * @param piece The piece to move.
 * @return true if the pawn can move to the given position, false otherwise.
 */
bool PawnMovement(int x, int y, int movex, int movey, bool isCapture, char piece);

/**
 * @brief Checks if a rook can move to a given position.
 * @param x The current x position of the rook.
 * @param y The current y position of the rook.
 * @param movex The x position to move to.
 * @param movey The y position to move to.
 * @return true if the rook can move to the given position, false otherwise.
 */
bool RookMovement(int x, int y, int movex, int movey);

/**
 * @brief Checks if a bishop can move to a given position.
 * @param x The current x position of the bishop.
 * @param y The current y position of the bishop.
 * @param movex The x position to move to.
 * @param movey The y position to move to.
 * @return true if the bishop can move to the given position, false otherwise.
 */
bool BishopMovement(int x, int y, int movex, int movey);

/**
 * @brief Checks if a queen can move to a given position.
 * @param x The current x position of the queen.
 * @param y The current y position of the queen.
 * @param movex The x position to move to.
 * @param movey The y position to move to.
 * @return true if the queen can move to the given position, false otherwise.
 */
bool QueenMovement(int x, int y, int movex, int movey);

/**
 * @brief Checks if a king can move to a given position.
 * @param x The current x position of the king.
 * @param y The current y position of the king.
 * @param movex The x position to move to.
 * @param movey The y position to move to.
 * @return true if the king can move to the given position, false otherwise.
 */
bool KingMovement(int x, int y, int movex, int movey);

/**
 * @brief Checks if a knight can move to a given position.
 * @param x The current x position of the knight.
 * @param y The current y position of the knight.
 * @param movex The x position to move to.
 * @param movey The y position to move to.
 * @return true if the knight can move to the given position, false otherwise.
 */
bool KnightMovement(int x, int y, int movex, int movey);

/**
 * @brief Checks if the path from a start position to an end position is clear.
 * @param startX The x position to start from.
 * @param startY The y position to start from.
 * @param endX The x position to end at.
 * @param endY The y position to end at.
 * @param chessboard The current state of the chessboard.
 * @return true if the path is clear, false otherwise.
 */
bool isPathClear(const int startX, const int startY, const int endX, const int endY,
                 const std::vector<std::vector<char>> &chessboard);

/**
 * @brief Checks if a pawn can be promoted.
 * @param PlayerW Indicates if the player is white.
 * @param PromotionFigure The figure to promote to.
 * @param movey The y position to move to.
 * @param figure The figure to promote.
 * @return true if the pawn can be promoted, false otherwise.
 */
bool CanPromote(bool PlayerW, char PromotionFigure, int movey, char figure);

/**
 * @brief Checks if a move is valid.
 * @param figure The figure to move.
 * @param x The current x position of the figure.
 * @param y The current y position of the figure.
 * @param movex The x position to move to.
 * @param movey The y position to move to.
 * @param chessboard The current state of the chessboard.
 * @param isCapture Indicates if the move is a capture.
 * @return true if the move is valid, false otherwise.
 */
bool ValidMovement(char figure, int x, int y, int movex, int movey, const std::vector<std::vector<char>> &chessboard,
                   bool isCapture);
