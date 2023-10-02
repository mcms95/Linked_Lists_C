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

// Delete all matches
Node *delete_all_matches(Node *head, int delete_value) {
    Node *current = head;  // Initialize a pointer to traverse the list starting from the head
    Node *prev = NULL;     // Initialize a pointer to keep track of the previous node

    // Traverse the list
    while(current != NULL)
    {
        // Check if the current node's value matches the value to be deleted
        if (current->value == delete_value) // Node value match
        {
            Node *tmp = current;  // Store a temporary pointer to the node to be deleted

            if (current == head) // If the head matches
            {
                head = current->next;  // Update the head to point to the next node
                current = head;  // Move to the new head
            }
            else // Match found in a node other than the head
            {
                prev->next = current->next; // Set prev->next to point to node after current
                current = current->next;     // Move forward current
            }
            free(tmp);  // Free the memory for the node to be deleted
        }
        else // No match, move to the next node
        {
            prev = current;  // Update the previous node pointer
            current = current->next;  // Move one node ahead
        }
    }

    return head;  // Return the updated head of the list after deletion
}


int main()
{
    Node *list = NULL;

    list = insert_head(list, 9);
    list = insert_head(list, 9);
    list = insert_head(list, 9);
    list = insert_head(list, 1);
    list = insert_head(list, 9);
    list = insert_head(list, 3);
    list = insert_head(list, 9);
    list = insert_head(list, 9);
    print_list(list);

    printf("\nAfter:\n");
    list = delete_all_matches(list, 9);
    print_list(list);

}