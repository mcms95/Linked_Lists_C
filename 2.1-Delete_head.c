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

// Delete the node at the head of the linked list
Node *delete_head(Node *head) {
    if (head == NULL)  // If the list is empty
        return NULL;
    else {
        Node *to_return = head->next;  // Point to the new head
        free(head);  // Free the memory allocated for the previous head
        return to_return;  // Return the new head
    }
}


int main()
{
    Node *list = NULL;
    printf("Before:\n");
    list = insert_head(list, 1);
    list = insert_head(list, 2);
    list = insert_head(list, 3);
    print_list(list);
    printf("\nAfter:\n");

    list = delete_head(list);
    print_list(list);

}