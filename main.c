#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>


#define TAPE_SIZE 1025
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define CELL_SIZE 40



typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;


Node* create_node(char data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    return node;
}


void move_right(Node **ptr, int *mid_ptr_index) {
    *ptr = (*ptr)->next;
    (*mid_ptr_index)++;
}

void move_left(Node **ptr, int *mid_ptr_index) {
    *ptr = (*ptr)->prev;
    (*mid_ptr_index)--;
}

void write(Node **ptr, char data) {
    (*ptr)->data = data;
}

int main(int argc, char *argv[]) {
    Node *head = create_node('_');

    Node *prev = head;
    Node *current = head;

    Node *mid_ptr = NULL;
    int mid_ptr_index = TAPE_SIZE / 2;

    for (int i = 0; i < TAPE_SIZE; i++) {
        Node *node = create_node('_');
        current->next = node;
        current = node;
        current->prev = prev;
        prev = current;

        if (i == TAPE_SIZE / 2) {
            mid_ptr = current;
        }
    }

    current->next = NULL;

    write(&mid_ptr, '1');
    move_right(&mid_ptr, &mid_ptr_index);
    write(&mid_ptr, '1');
    move_left(&mid_ptr, &mid_ptr_index);
    move_left(&mid_ptr, &mid_ptr_index);
    write(&mid_ptr, '0');
    move_left(&mid_ptr, &mid_ptr_index);
    move_left(&mid_ptr, &mid_ptr_index);
    move_left(&mid_ptr, &mid_ptr_index);
    move_left(&mid_ptr, &mid_ptr_index);
    move_left(&mid_ptr, &mid_ptr_index);


    Node *start = head;
    int counter = 0;

    while (start->next != NULL) {
        counter++;
        if (counter == mid_ptr_index) {
            printf("v");
        } else {
            printf("%c", start->data);
        }
        start = start->next;
    }

    return 0;
}