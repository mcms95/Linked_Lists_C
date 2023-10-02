// Duplicate a linked list, returning a pointer to the new one

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
} Node;

// Insert a node at the head of the linked list
Node *insert_head(Node *head, int new_value) {
    Node *new_node = calloc(1, sizeof(Node)); // Allocate memory for the new node
    new_node->value = new_value;               // Set the value for the new node

    // If the list is empty, the new node becomes the head
    if (head == NULL)
        return new_node;
    else {
        new_node->next = head;  // Point the new node to the current head
        return new_node;        // The new node becomes the new head
    }
}


// Print the linked list
void print_list(Node *head) {
    Node *current;  // Pointer to traverse the list
    current = head; // Start from the head of the list
    int i = 0;      // Counter for node numbering

    // Traverse the list and print node values
    while (current != NULL) {
        printf("Node %d : %d\n", i, current->value);
        i++;
        current = current->next;
    }
}

Node *duplicate(Node *list) {
    if (list == NULL)
        return NULL;

    Node *current = list;
    Node *new_list = NULL;
    Node *tail = NULL;

    while (current != NULL) {
        Node *new_node = calloc(1, sizeof(Node));
        if (new_node == NULL) {
            // Handle memory allocation failure
            return NULL;
        }

        // Copy value and set next pointer
        new_node->value = current->value;
        new_node->next = NULL;

        if (new_list == NULL) {
            // Set the new node as the head of the new list
            new_list = new_node;
            tail = new_node;
        } else {
            // Append the new node to the new list
            tail->next = new_node;
            tail = new_node;
        }

        current = current->next;
    }

    return new_list;
}


int main()
{
    Node *list = NULL;

    list = insert_head(list, 1);
    list = insert_head(list, 3);
    list = insert_head(list, 9);

    print_list(list);

    Node *new_list = duplicate(list);
    print_list(new_list);
}