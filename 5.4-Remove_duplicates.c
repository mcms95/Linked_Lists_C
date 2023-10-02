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

void remove_duplicates(Node *head) {
    // Check if the list is empty or has only one node
    if (head == NULL || head->next == NULL)
        return;

    Node *current1, *current2, *duplicate;
    current1 = head;

    // Traverse the list with the first pointer
    while (current1 != NULL && current1->next != NULL) {
        current2 = current1;

        // Traverse the list with the second pointer
        while (current2->next != NULL) {
            // Check if the value of the current node is equal to the value of the next node
            if (current1->value == current2->next->value) {
                // If a duplicate is found, remove the duplicate node
                duplicate = current2->next;
                current2->next = current2->next->next;
                free(duplicate);  // Free the memory of the duplicate node
            } else
                current2 = current2->next;  // Move the second pointer to the next node
        }
        current1 = current1->next;  // Move the first pointer to the next node
    }
}

int main()
{
    Node *list = NULL;

    list = insert_head(list, 1);
    list = insert_head(list, 3);
    list = insert_head(list, 9);
    list = insert_head(list, 1);
    list = insert_head(list, 3);
    list = insert_head(list, 9);
    list = insert_head(list, 1);
    list = insert_head(list, 3);
    list = insert_head(list, 9);
    remove_duplicates(list);
    print_list(list);

}