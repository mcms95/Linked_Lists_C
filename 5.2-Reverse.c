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

// Reverse Linked list
Node *reverse(Node *head)
{
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    
    Node *current = head;  // Pointer to the current node
    Node *next_node = head->next;  // Pointer to the next node

    current->next = NULL;  // Make the first node the new tail of the list

    while (next_node != NULL) {
        Node *tmp = next_node->next;  // Save the next node to avoid losing it
        next_node->next = current;   // Reverse the link to the previous node
        current = next_node;   // Move forward in the list
        next_node = tmp;   // Move forward in the list
    }

    return current;
}

int main()
{
    Node *list = NULL;

    list = insert_head(list, 1);
    list = insert_head(list, 3);
    list = insert_head(list, 9);

    print_list(list);

    list = reverse(list);
    printf("\nAfter:\n");
    print_list(list);

}