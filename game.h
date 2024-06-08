#ifndef GAME_H_
#define GAME_H_

/* INCLUDES */
#include <SFML/Graphics/RenderWindow.h> 
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <SFML/Graphics.h>

/* DEFINES */
#define BOARD_ROWS 100
#define BOARD_COLUMNS 100
#define TILE_SIZE 10
#define CIRCLE_RADIUS 5

/* STRUCTS */
typedef struct Node {
  int pos_x;
  int pos_y;
  struct Node *prevNode;
  struct Node *nextNode;
} Node;

/* PROTOTYPES */
void draw_board(sfRenderWindow *window, int board[BOARD_ROWS][BOARD_COLUMNS]);
bool update_board(int board[BOARD_ROWS][BOARD_COLUMNS], int *snake_direction, Node **head);

/* FOOD */
void spawn_food(int board[BOARD_ROWS][BOARD_COLUMNS]);

/* SNAKE DOUBLY LINKED LIST */
void insert_node(Node **head, int pos_x, int pos_y);
void delete_last_node(Node **head);
Node *getLast_node(Node **head);
Node *create_node(int pos_x, int pos_y);

#endif
