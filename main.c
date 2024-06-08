/*
 * @author: Eduardo Nascimento
 * @brief: Snake Game Implementation Using SMFL graphics library
 * @date: May 07, 2024
*/

/* INCLUDES */
#include "game.h"

/* TAKE PLAYER INPUT */
void take_player_input(int *snake_direction) {
  /* UP */
  if (sfKeyboard_isKeyPressed(sfKeyUp)) {
    if (*snake_direction == 2) {
      return;
    }
    *snake_direction = 1;
  }
  /* DOWN */
  if (sfKeyboard_isKeyPressed(sfKeyDown)) {
    if (*snake_direction == 1) {
      return;
    }
    *snake_direction = 2;
  }
  /* RIGHT */
  if (sfKeyboard_isKeyPressed(sfKeyRight)) {
    if (*snake_direction == 4) {
      return;
    }
    *snake_direction = 3;
  }
  /* LEFT */
  if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
    if (*snake_direction == 3) {
      return;
    }
    *snake_direction = 4;
  }
}

/* MAIN */
int main() {
  /* INIT/DECLARE */
  int snake_direction = 1;

  /* INIT BOARD */
  int board[100][100];
  // init tiles
  for (int i = 0; i < BOARD_ROWS; i++) {
    for (int j = 0; j < BOARD_COLUMNS; j++) {
      board[i][j] = 1;
    }
  }

  /* INIT SNAKE ON BOARD */
  Node *head = NULL;

  // alloc head node
  head = (Node *)malloc(sizeof(Node));
  if (head == NULL) {
    perror("[*] Error, (main.c) could not alloc head node");
    exit(1);
  }
  // set vals
  head->pos_x = 50;
  head->pos_y = 50;
  head->prevNode = NULL;
  head->nextNode = NULL;

  // alloc 2nd body node
  head->nextNode = (Node *)malloc(sizeof(Node));
  if (head->nextNode == NULL) {
    perror("[*] Error, (main.c) could not alloc 2nd body node");
    exit(1);
  }
  // set vals
  head->nextNode->pos_x = 50;
  head->nextNode->pos_y = 51;
  head->nextNode->prevNode = head;
  head->nextNode->nextNode = NULL;

  // map board position to first 2 nodes
  board[50][50] = 2;
  board[50][51] = 2;

  /* INIT SDL */
  sfVideoMode mode = {BOARD_COLUMNS * TILE_SIZE, BOARD_ROWS * TILE_SIZE, 32};
  sfRenderWindow *window =
      sfRenderWindow_create(mode, "HUNGRY SNAKE", sfClose, NULL);
  sfRenderWindow_setFramerateLimit(window, 60);

  // check window creation
  if (window == NULL) {
    perror("\n[*] ERROR: Error Game Window Could Not Be Created\n");
    exit(EXIT_FAILURE);
  }

  // clear window
  sfRenderWindow_clear(window, sfBlack);

  /* MAIN GAME LOOP */
  while (sfRenderWindow_isOpen(window)) {

    /* HANDLE WINDOW EVENTS */
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
      /* ESC / WINDOW CLOSE */
      if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
      if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);

      /* PLAYER KEYBOARD INPUT */
      take_player_input(&snake_direction);
    }

    // spawn food
    spawn_food(board);

    // update board game // if false game is over
    if (!update_board(board, &snake_direction, &head)) {
      break;
    }

    // draw board game
    draw_board(window, board);

    // display
    sfRenderWindow_display(window);

    // sleep delay
    // usleep(300000 );

    // last speed
    usleep(50000);

  }

  /* EXIT GAME LOOP */
  // TODO: exit screen here

  /* EXIT */
  return 0;
}

/* THE PLAN */
/*
 * 1. Create a board as an array
 * 2. paint the whole board black and put edges on it
 * 3. Create the logic to paint the snake to the board
 * 4. Move the snake
 *
 * Functions needed:
 * gameInit()
 * gameRender()
 * updateGame()
 * userInput()
 *
 * TODO:
 * -Clean UP resources
 * -Add game music
 * -Add menu screen
 * -Add score board
 * -Add textures and make game look nice
 */
