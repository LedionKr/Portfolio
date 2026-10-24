//
// Created by Ledion Krasniqi on 27.03.24.
//

#include "board.h"

#include <string>

bool Board::isKingCheck(bool player) {
  int wKingX = 0;
  int wKingY = 0;
  int bKingX = 0;
  int bKingY = 0;
  // search and safe position of king
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      const char figure = ChessBoard[i][j];
      if (figure == 'k') {
        bKingX = j;
        bKingY = i;
      }
      if (figure == 'K') {
        wKingX = j;
        wKingY = i;
      }
    }
  }
  for (int y = 7; y >= 0; y--) {
    for (int x = 0; x < 8; x++) {
      const char figure = ChessBoard[y][x];
      if (islower(figure) && figure != 'k' && player) {
        if (ValidMovement(figure, x, y, wKingX, wKingY, ChessBoard, true)) {
          return true;
        }
      }
      if (isupper(figure) && figure != 'K' && !player) {
        if (ValidMovement(figure, x, y, bKingX, bKingY, ChessBoard, true)) {
          return true;
        }
      }
    }
  }
  return false;
}

// Reads the input and uploads/safes the pieces
void Board::readBoard(const std::string &input) {
  std::vector<std::string> fenSettings;

  // Parse all the input in my vector while I cut it.
  std::istringstream iss(input);
  for (std::string s; iss >> s;) fenSettings.push_back(s);
  int x = 0;
  int y = 7;
  for (char &fenChar : fenSettings[0]) {
    if (x > 7) {
      x = 0;
    }
    if (fenChar == '/') {
      x = 0;
      y--;
      continue;
    }
    if (std::isdigit(fenChar)) {
      for (int i = fenChar - '0'; i > 0; i--) {
        ChessBoard[y][x] = ' ';
        x++;
      }
      continue;
    }
    ChessBoard[y][x] = fenChar;
    x++;
  }
  PlayerW = (fenSettings[1] != "b");
  printBoard();
}

void Board::printPossibleMoves(char figure, int x, int y) {
  bool isCheck = false;
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      if ((ValidMovement(figure, x, y, j, i, ChessBoard, true)) ||
          (ValidMovement(figure, x, y, j, i, ChessBoard, false))) {
        const char tempFigure = ChessBoard[i][j];
        ChessBoard[i][j] = figure;
        ChessBoard[y][x] = ' ';
        isCheck = isKingCheck(PlayerW);
        ChessBoard[i][j] = tempFigure;
        ChessBoard[y][x] = figure;
      }
      if ((ValidMovement(figure, x, y, j, i, ChessBoard, false)) && (ChessBoard[i][j] == ' ') && !isCheck) {
        std::cout << "[" << 'o' << "]";
        // std::cout << 'o';
        continue;
      }
      if (ValidMovement(figure, x, y, j, i, ChessBoard, true) && !isCheck) {
        if ((isupper(figure) && islower(ChessBoard[i][j])) || (islower(figure) && isupper(ChessBoard[i][j]))) {
          std::cout << "[" << 'x' << "]";
          // std::cout << 'x';
          continue;
        }
      }
      std::cout << "[" << ChessBoard[i][j] << "]";
      // std::cout << ChessBoard[i][j];
    }
    std::cout << std::endl;
  }
}

bool Board::arePossibleMoves(char figure, int x, int y, bool player) {
  bool isCheck = false;
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      if ((ValidMovement(figure, x, y, j, i, ChessBoard, true)) ||
          (ValidMovement(figure, x, y, j, i, ChessBoard, false))) {
        const char tempFigure = ChessBoard[i][j];
        ChessBoard[i][j] = figure;
        ChessBoard[y][x] = ' ';
        isCheck = isKingCheck(player);
        ChessBoard[i][j] = tempFigure;
        ChessBoard[y][x] = figure;
      }
      if ((ValidMovement(figure, x, y, j, i, ChessBoard, false)) && (ChessBoard[i][j] == ' ') && !isCheck) {
        return true;
      }
      if (ValidMovement(figure, x, y, j, i, ChessBoard, true) && !isCheck) {
        if ((isupper(figure) && islower(ChessBoard[i][j])) || (islower(figure) && isupper(ChessBoard[i][j]))) {
          return true;
        }
      }
    }
  }
  return false;
}

bool Board::isKingCheckmate(bool player) {
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      if (player && isupper(ChessBoard[i][j])) {
        if (arePossibleMoves(ChessBoard[i][j], j, i, player)) {
          return false;
        }
      }
      if (!player && islower(ChessBoard[i][j])) {
        if (arePossibleMoves(ChessBoard[i][j], j, i, player)) {
          return false;
        }
      }
    }
  }
  return true;
}

bool Board::undo() {
  if (BoardHistory.size() > 1) {
    BoardHistory.pop_back();
    ChessBoard = BoardHistory.back();
    PlayerW = !PlayerW;
    return true;
  }
  return false;
}

bool Board::makeMove(char figure, int x, int y, int movex, int movey, bool isCapture, char promotionFigure) {
  // Board edges
  if (!(x <= 7 && x >= 0 && y >= 0) && !(movex <= 7 && movex >= 0 && movey <= 7 && movey >= 0)) {
    return false;
  }
  // figure there?
  if (ChessBoard[y][x] != figure) {
    return false;
  }
  // which team?
  if ((isupper(figure) && !PlayerW) || (islower(figure) && PlayerW)) {
    return false;
  }
  // same group?
  if (isupper(ChessBoard[movey][movex]) && isupper(figure)) {
    return false;
  }
  // same group - other color?
  if (islower(ChessBoard[movey][movex]) && islower(figure)) {
    return false;
  }
  // no capture or empty field?
  if ((ChessBoard[movey][movex] == ' ' && isCapture) || (ChessBoard[movey][movex] != ' ' && !isCapture)) {
    return false;
  }
  // pawn promotion
  if (ValidMovement(figure, x, y, movex, movey, ChessBoard, isCapture)) {
    if ((promotionFigure != ' ') && !CanPromote(PlayerW, promotionFigure, movey, figure)) {
      return false;
    }
    // move a piece
    ChessBoard[y][x] = ' ';
    ChessBoard[movey][movex] = figure;
    if ((promotionFigure != ' ') && CanPromote(PlayerW, promotionFigure, movey, figure)) {
      ChessBoard[movey][movex] = promotionFigure;
    }
    PlayerW = !PlayerW;
    BoardHistory.push_back(ChessBoard);
    // checked if King is checked
    if (isKingCheck(false)) {
      std::cout << (isKingCheckmate(PlayerW) ? "yes" : "no") << std::endl;
    }
    printBoard();
    return true;
  }
  return false;
}

void Board::printBoard() {
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      std::cout << "[" << ChessBoard[i][j] << "]";
    }
    std::cout << std::endl;
  }
}

bool Board::areKingsAlive() {
  int kingsAliveCount = 0;
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      if ((tolower(ChessBoard[i][j]) == 'k')) {
        kingsAliveCount++;
      }
    }
  }
  if (kingsAliveCount == 2) {
    return true;
  } else {
    return false;
  }
}

int Board::kingCounter(int movex, int movey) {
  int kingAmount = 0;
  for (int x = -1; x <= 1; x++) {
    int explodeX = movex + x;
    if (explodeX < 0 || explodeX > 7) {
      continue;
    }
    for (int y = -1; y <= 1; y++) {
      int explodeY = movey + y;
      if (explodeY < 0 || explodeY > 7) {
        continue;
      }
      if ((tolower(ChessBoard[explodeY][explodeX]) == 'k')) {
        kingAmount++;
      }
    }
  }
  return kingAmount;
}

void Board::explodeSurroundings(int movex, int movey) {
  for (int x = -1; x <= 1; x++) {
    int explodeX = movex + x;
    if (explodeX < 0 || explodeX > 7) {
      continue;
    }
    for (int y = -1; y <= 1; y++) {
      int explodeY = movey + y;
      if (explodeY < 0 || explodeY > 7) {
        continue;
      }
      if (!(ChessBoard[explodeY][explodeX] == ' ') && !(tolower(ChessBoard[explodeY][explodeX]) == 'p')) {
        ChessBoard[explodeY][explodeX] = ' ';
      }
    }
  }
}

bool Board::makeAtomicMove(char figure, int x, int y, int movex, int movey, bool isCapture, char promotionFigure) {
  // Board edges
  if (!(x <= 7 && x >= 0 && y >= 0) && !(movex <= 7 && movex >= 0 && movey <= 7 && movey >= 0)) {
    return false;
  }
  // figure there?
  if (ChessBoard[y][x] != figure) {
    return false;
  }
  // which team?
  if ((isupper(figure) && !PlayerW) || (islower(figure) && PlayerW)) {
    return false;
  }
  // same group?
  if (isupper(ChessBoard[movey][movex]) && isupper(figure)) {
    return false;
  }
  // same group - other color?
  if (islower(ChessBoard[movey][movex]) && islower(figure)) {
    return false;
  }
  // no capture or empty field?
  if ((ChessBoard[movey][movex] == ' ' && isCapture) || (ChessBoard[movey][movex] != ' ' && !isCapture)) {
    return false;
  }
  // Amount of kings
  if (((kingCounter(movex, movey)) == 2) && isCapture) {
    return false;
  }
  // king cant capture
  if (islower(ChessBoard[y][x]) == 'k') {
    if (ChessBoard[movey][movex] != ' ') {
      return false;
    }
  }
  // pawn promotion
  if (ValidMovement(figure, x, y, movex, movey, ChessBoard, isCapture)) {
    if ((promotionFigure != ' ') && !CanPromote(PlayerW, promotionFigure, movey, figure)) {
      return false;
    }
    // move a piece
    ChessBoard[y][x] = ' ';
    ChessBoard[movey][movex] = figure;
    if ((promotionFigure != ' ') && CanPromote(PlayerW, promotionFigure, movey, figure)) {
      ChessBoard[movey][movex] = promotionFigure;
    }
    if (isCapture) {
      explodeSurroundings(movex, movey);
      if (tolower(figure) == 'p') {
        ChessBoard[movey][movex] = ' ';
      }
    }
    PlayerW = !PlayerW;
    BoardHistory.push_back(ChessBoard);
    // checked if King is checked
    if (isKingCheck(false)) {
      std::cout << (isKingCheckmate(PlayerW) ? "yes" : "no") << std::endl;
    }
    printBoard();
    return true;
  }
  return false;
}
