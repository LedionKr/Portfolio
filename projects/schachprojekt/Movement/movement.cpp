//
// Created by Ledion Krasniqi on 27.03.24.
//

#include "movement.h"

#include <cctype>
#include <cmath>
// Can the pawn even move? Boolean to check status
// Pawn movement validation, two squares at first move
// no backwards, capture in a diagonal
bool PawnMovement(int x, int y, int movex, int movey, bool isCapture, char piece) {
  if ((std::isupper(piece) && movey < y) || (std::islower(piece) && movey > y)) {
    return false;
  }
  if (std::abs(y - movey) == 1 && x == movex && !isCapture) {
    return true;
  }
  if (std::abs(y - movey) == 2 && x == movex && (y == 1 || y == 6) && !isCapture) {
    return true;
  }
  if (std::abs(y - movey) == 1 && std::abs(x - movex) == 1 && isCapture) {
    return true;
  }

  return false;
}

// Can the Rook even move? Boolean to check status
bool RookMovement(int x, int y, int movex, int movey) {
  if ((y == movey && x != movex) || (x == movex && y != movey)) {
    return true;
  }
  return false;
}

// Can the Bishop even move? Boolean to check status
bool BishopMovement(int x, int y, int movex, int movey) {
  if (std::abs(y - movey) == std::abs(x - movex)) {
    return true;
  }
  return false;
}

// Can the Queen even move? Boolean to check status
bool QueenMovement(int x, int y, int movex, int movey) {
  if ((y == movey && x != movex) || (x == movex && y != movey) || std::abs(y - movey) == std::abs(x - movex)) {
    return true;
  }
  return false;
}

// Can the King even move? Boolean to check status
bool KingMovement(int x, int y, int movex, int movey) {
  if ((y == movey && std::abs(x - movex) == 1)) return true;
  if ((x == movex && std::abs(y - movey) == 1)) return true;
  if (std::abs(y - movey) == std::abs(x - movex) && std::abs(y - movey) == 1) return true;

  return false;
}

// Can the Knight even move? Therefore, boolean to check status
bool KnightMovement(int x, int y, int movex, int movey) {
  if (((std::abs(x - movex) == 2) && (std::abs(y - movey) == 1)) ||
      ((std::abs(x - movex) == 1) && (std::abs(y - movey) == 2))) {
    return true;
  }
  return false;
}
// algorithm to check if path is clear
bool isPathClear(const int startX, const int startY, const int endX, const int endY,
                 const std::vector<std::vector<char>> &chessboard) {
  const int dx = std::abs(endX - startX);
  const int dy = std::abs(endY - startY);
  int x = startX;
  int y = startY;
  const int xInc = (endX > startX) ? 1 : -1;
  const int yInc = (endY > startY) ? 1 : -1;

  if (dx > dy) {
    int p = 2 * dy - dx;
    while (x != endX) {
      if (p >= 0) {
        y += yInc;
        p -= 2 * dx;
      }
      x += xInc;
      p += 2 * dy;

      if (x != endX || y != endY) {
        if (chessboard[y][x] != ' ') {
          return false;
        }
      }
    }
  } else {
    int p = 2 * dx - dy;
    while (y != endY) {
      if (p >= 0) {
        x += xInc;
        p -= 2 * dy;
      }
      y += yInc;
      p += 2 * dx;

      if (x != endX || y != endY) {
        if (chessboard[y][x] != ' ') {
          return false;
        }
      }
    }
  }

  return true;  // Path = clear
}
// Promotion, if pawn reaches end
// To initialize promotion, signal "="
// Only Pawn can promote, but not into King and Pawn
bool CanPromote(bool PlayerW, char PromotionFigure, int movey, char figure) {
  if (movey == 7 || movey == 0) {
    if ((isupper(PromotionFigure) && PlayerW) || (islower(PromotionFigure) && !PlayerW)) {
      if (tolower(figure) == 'p') {
        if (tolower(PromotionFigure) != 'k' && tolower(PromotionFigure) != 'p') {
          if (tolower(PromotionFigure) == 'b' || tolower(PromotionFigure) == 'q' || tolower(PromotionFigure) == 'r' ||
              tolower(PromotionFigure) == 'n') {
            return true;
          }
        }
      }
    }
  }
  return false;
}

// Assigns the chars to the pieces and their movements
bool ValidMovement(char figure, int x, int y, int movex, int movey, const std::vector<std::vector<char>> &chessboard,
                   bool isCapture) {
  if (chessboard[movey][movex] == ' ' && isCapture) {
    return false;
  }
  switch (std::tolower(figure)) {
    case 'b':
      if (isPathClear(x, y, movex, movey, chessboard)) {
        return BishopMovement(x, y, movex, movey);
      }
      return false;
    case 'k':
      if (!isPathClear(x, y, movex, movey, chessboard)) {
        return false;
      }
      if ((!KingMovement(x, y, movex, movey)) || std::tolower(chessboard[movey][movex]) == 'k') {
        return false;
      }
      break;
    case 'n':
      if (!KnightMovement(x, y, movex, movey)) {
        return false;
      }
      break;
    case 'r':
      if (!isPathClear(x, y, movex, movey, chessboard)) {
        return false;
      }
      if (!RookMovement(x, y, movex, movey)) {
        return false;
      }
      break;
    case 'p':
      if (!isPathClear(x, y, movex, movey, chessboard)) {
        return false;
      }
      if (!PawnMovement(x, y, movex, movey, isCapture, figure)) {
        return false;
      }
      break;
    case 'q':
      if (!isPathClear(x, y, movex, movey, chessboard)) {
        return false;
      }
      if (!QueenMovement(x, y, movex, movey)) {
        return false;
      }
      break;
    default:
      return false;
  }
  return true;
}
