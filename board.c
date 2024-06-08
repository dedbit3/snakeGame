/* INCLUDES */
#include "game.h"

/* CHECK HIT */
int check_hit(int board[BOARD_ROWS][BOARD_COLUMNS], Node **head) {
  // hit edge of the board
  if ((*head)->pos_x > 100 || (*head)->pos_x < 0 || (*head)->pos_y > 100 || (*head)->pos_y < 0) {
    return 1;
  }
  // hit snake body
  if (board[(*head)->pos_x][(*head)->pos_y] == 2) {
    return 1;
  }
  // hit food
  if (board[(*head)->pos_x][(*head)->pos_y] == 3) {
    return 2;
  }
  // no hit
  return 0;
}

/* UPDATE GAME BOARD */
bool update_board(int board[BOARD_ROWS][BOARD_COLUMNS], int *snake_direction, Node **head) {
  /* INIT/DECLARE */
  int hit_result = 0;

  /* MOVE SNAKE */
  switch (*snake_direction) {
    /* UP */
    case 1: {
      /* CREATE NEW HEAD NODE */
      Node *newHead = create_node(((*head)->pos_x), ((*head)->pos_y - 1));
      /* CHECK HIT */
      hit_result = check_hit(board, &newHead);
      // hit snake or wall, end game
      if (hit_result == 1) {
        return false;
      }
      // hit food
      if (hit_result == 2) {
        // update board from food to snake
        board[newHead->pos_x][newHead->pos_y] = 2;
        // grow snake / link new head
        newHead->nextNode = *head;
        (*head)->prevNode = newHead;
        *head = newHead;
        // return
        return true;
      }
      // no hit just move snake
      board[(newHead)->pos_x][newHead->pos_y] = 2;
      // link new head
      newHead->nextNode = *head;
      (*head)->prevNode = newHead;
      *head = newHead;
      // remove last node from board
      Node *lastNode = getLast_node(head);
      board[(lastNode)->pos_x][(lastNode)->pos_y] = 1;
      // delete last node
      delete_last_node(head);
      // return
      return true;
      break;
    }
    /* DOWN */
    case 2: {
      /* CREATE NEW HEAD NODE */
      Node *newHead = create_node((*head)->pos_x, (*head)->pos_y + 1);
      /* CHECK HIT */
      hit_result = check_hit(board, &newHead);
      // hit snake or wall, end game
      if (hit_result == 1) {
        return false;
      }
      // hit food
      if (hit_result == 2) {
        // update board from food to snake
        board[newHead->pos_x][newHead->pos_y] = 2;
        // grow snake / link new head
        //
        newHead->nextNode = *head;
        (*head)->prevNode = newHead;
        *head = newHead;
        // return
        return true;
      }
      // no hit just move snake
      board[(newHead)->pos_x][newHead->pos_y] = 2;
      // link new head
      newHead->nextNode = *head;
      (*head)->prevNode = newHead;
      *head = newHead;
      // remove last node from board
      Node *lastNode = getLast_node(head);
      board[(lastNode)->pos_x][(lastNode)->pos_y] = 1;
      // delete last node
      delete_last_node(head);
      // return
      return true;
      break;
    }
    /* RIGHT */
    case 3: {
      /* CREATE NEW HEAD NODE */
      Node *newHead = create_node((*head)->pos_x + 1, (*head)->pos_y);
      /* CHECK HIT */
      hit_result = check_hit(board, &newHead);
      // hit snake or wall, end game
      if (hit_result == 1) {
        return false;
      }
      // hit food
      if (hit_result == 2) {
        // update board from food to snake
        board[newHead->pos_x][newHead->pos_y] = 2;
        // grow snake / link new head
        newHead->nextNode = *head;
        (*head)->prevNode = newHead;
        *head = newHead;
        // return
        return true;
      }
      // no hit just move snake
      board[(newHead)->pos_x][newHead->pos_y] = 2;
      // link new head
      newHead->nextNode = *head;
      (*head)->prevNode = newHead;
      *head = newHead;
      // remove last node from board
      Node *lastNode = getLast_node(head);
      board[(lastNode)->pos_x][(lastNode)->pos_y] = 1;
      // delete last node
      delete_last_node(head);
      // return
      return true;
      break;
    }
    /* LEFT */
    case 4: {
      /* CREATE NEW HEAD NODE */
      Node *newHead = create_node((*head)->pos_x - 1, (*head)->pos_y);
      /* CHECK HIT */
      hit_result = check_hit(board, &newHead);
      // hit snake or wall, end game
      if (hit_result == 1) {
        return false;
      }
      // hit food
      if (hit_result == 2) {
        // update board from food to snake
        board[newHead->pos_x][newHead->pos_y] = 2;
        // grow snake / link new head
        newHead->nextNode = *head;
        (*head)->prevNode = newHead;
        *head = newHead;
        // return
        return true;
      }
      // no hit just move snake
      board[(newHead)->pos_x][newHead->pos_y] = 2;
      // link new head
      newHead->nextNode = *head;
      (*head)->prevNode = newHead;
      *head = newHead;
      // remove last node from board
      Node *lastNode = getLast_node(head);
      board[(lastNode)->pos_x][(lastNode)->pos_y] = 1;
      // delete last node
      delete_last_node(head);
      // return
      return true;
      break;
    }
  }
  // ERROR
  perror("[*] ERROR, (update_board) invalid snake_direction!!!");
  exit(1);
}
