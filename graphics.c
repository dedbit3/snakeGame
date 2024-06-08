/* INCLUDES */
#include "game.h"

/* DRAW BLACK TILE */
void draw_black_tile(sfRenderWindow *window, int board[BOARD_ROWS][BOARD_COLUMNS], int posX, int posY) {
  sfRectangleShape *tile = sfRectangleShape_create();
  sfVector2f size = {TILE_SIZE, TILE_SIZE};
  sfRectangleShape_setSize(tile, size);
  sfVector2f pos = {posX * TILE_SIZE, posY * TILE_SIZE};
  sfRectangleShape_setPosition(tile, pos);
  sfRectangleShape_setFillColor(tile, sfBlack);
  /* DRAW SHAPE (third parameter is rendering state) */
  sfRenderWindow_drawRectangleShape(window, tile, NULL);
  return;
}

/* DRAW WHITE TILE */
void draw_white_tile(sfRenderWindow *window, int board[BOARD_ROWS][BOARD_COLUMNS], int posX, int posY) {
  sfRectangleShape *tile = sfRectangleShape_create();
  sfVector2f size = {TILE_SIZE, TILE_SIZE};
  sfRectangleShape_setSize(tile, size);
  sfVector2f pos = {posX * TILE_SIZE, posY * TILE_SIZE};
  sfRectangleShape_setPosition(tile, pos);
  sfRectangleShape_setFillColor(tile, sfWhite);
  /* DRAW SHAPE (third parameter is rendering state) */
  sfRenderWindow_drawRectangleShape(window, tile, NULL);
  return;
}

/* DRAW RED CIRCLE TILE */
void draw_red_circle(sfRenderWindow *window, int board[BOARD_ROWS][BOARD_COLUMNS], int posX, int posY) {
  sfCircleShape *circle = sfCircleShape_create();
  sfCircleShape_setRadius(circle, CIRCLE_RADIUS);
  sfVector2f pos = {posX * TILE_SIZE, posY * TILE_SIZE};
  sfCircleShape_setPosition(circle, pos);
  sfCircleShape_setFillColor(circle, sfRed);
  /* DRAW SHAPE (third parameter is rendering state) */
  sfRenderWindow_drawCircleShape(window, circle, NULL);
  return;
}

/* DRAW BOARD */
void draw_board(sfRenderWindow *window, int board[BOARD_ROWS][BOARD_COLUMNS]) {
  // loop through board positions
  for(int x = 0; x < BOARD_ROWS; x++) {
    for(int y = 0; y < BOARD_COLUMNS; y++) {
      int tile_value = board[x][y];
      switch(tile_value) {
        // tile empty
        case 1: {
          draw_black_tile(window, board, x, y);
          break;
        }
        // tile snake
        case 2: {
          draw_white_tile(window, board, x, y);
          break;
        }
        // tile food
        case 3: {
          draw_red_circle(window, board, x, y);
          break;
        }
      }
    }
  }
  return;
}
