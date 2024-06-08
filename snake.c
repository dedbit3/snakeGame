/* INCLUDES */
#include "game.h"

/* DOUBLY LINKED LIST */
/* This is being used to keep track of the body of the snake */

/* CREATE NODE */
Node* create_node(int pos_x, int pos_y) {
  Node *node = (Node*)malloc(sizeof(Node));
  // err handling
  if(node == NULL) {
    perror("[*] ERROR, Error (create_node) failed to allocate memory for new node");
    exit(1);
  };
  node->pos_x = pos_x;
  node->pos_y = pos_y;
  node->prevNode = NULL;
  node->nextNode = NULL;
  return node;
}

/* INSERT NODE */
void insert_node(Node **head, int pos_x, int pos_y) {
  // get first node
  Node *node = *head;
  // snake is not initilized
  if(node == NULL) {
    perror("[*] ERROR, Error (insert_node), head node is NULL");
    exit(1);
  }
  // snake is initialized
  while(node->nextNode != NULL) {
    node = node->nextNode;
  }
  // create and link node
  Node *newNode = create_node(pos_x, pos_y);
  newNode->prevNode = node;
  node->nextNode = newNode;
  // return
  return;
}

/* DELETE LAST NODE */
void delete_last_node(Node **head) {
  // err handling
  if(*head == NULL) {
    perror("[*] ERROR, Error (delete_last_node) the head node is null");
    exit(1);
  }
  // get first node
  Node *node = *head;
  // loop to end of list
  while(node->nextNode != NULL) {
    node = node->nextNode;
  }
  // err handling
  if(node->prevNode == NULL) {
    perror("[*] ERROR, Error (delete_last_node) the prev node is null");
    exit(1);
  }
  // free last node
  node->prevNode->nextNode = NULL;
  free(node);
  // return
  return;
}

/* GET LAST NODE */
Node* getLast_node(Node **head) {
  // err handling
  if(*head == NULL) {
    perror("[*] ERROR, Error (getLast_node) the first node is null");
    exit(1);
  }
  // first node
  Node *node = *head;
  // loop until end of list
  while(node->nextNode != NULL) {
    node = node->nextNode;
  }
  // return last node
  return node;
}
