/* INCLUDES */
#include "game.h"

/* SPAWN FOOD */
void spawn_food(int board[BOARD_ROWS][BOARD_COLUMNS]) {
  // check if there is food on the board
  for(int i = 0; i < BOARD_ROWS; i++) {
    for(int j = 0; j < BOARD_COLUMNS; j++) {
      // return if there is
      if(board[i][j] == 3) {
        return;
      }
    }
  }
  // seed rand`
  srand(time(0));
  // x and y random values between 0 and 100
  int x = rand() % 101;
  int y = rand() % 101;
  // add food to board
  board[x][y] = 3;
  // return
  return;
}
