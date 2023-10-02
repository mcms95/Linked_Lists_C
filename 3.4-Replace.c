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

// Replace value in linked list
void replace_matches(Node *head, int find_value, int replace_value)
{
    Node *current = head;  // Initialize a pointer to traverse the list starting from the head

    // Traverse the list
    while (current != NULL)
    {
        // Check if the current node's value matches the value to be replaced
        if (current->value == find_value)
        {
            current->value = replace_value;  // Replace the value with the specified replacement value
        }

        // Move to the next node in the list
        current = current->next;
    }
}


int main()
{
    Node *list = NULL;

    list = insert_head(list, 9);
    list = insert_head(list, 1);
    list = insert_head(list, 3);
    list = insert_head(list, 9);
    print_list(list);

    printf("\nAfter:\n");
    replace_matches(list, 9, 6);
    print_list(list);

}