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

Node *delete_first_match(Node *head, int delete_value)
{
    if (head == NULL) 
        return NULL;  // Return NULL if the list is empty
    
    if (head->value == delete_value)
    {
        // If the first node matches the value to be deleted
        Node *temp = head->next;
        free(head);  // Free the memory for the first node
        return temp;  // Return the updated head (second node becomes the new head)
    }
    
    Node *current = head->next;  // Pointer to traverse the list starting from the second node
    Node *prev = head;  // Pointer to keep track of the previous node

    // Traverse the list
    while(current != NULL)
    {
        // Check if the current node's value matches the value to be deleted
        if (current->value == delete_value)
        {
            // Update pointers to remove the node with the specified value
            prev->next = current->next;
            free(current);  // Free the memory for the node to be deleted
            return head;  // Return the head (no change if the first node wasn't the match)
        }

        // Move to the next node
        prev = current;
        current = current->next;
    }

    return head;  // Return the head (no match found)
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
    list = delete_first_match(list, 9);
    list = delete_first_match(list, 9);
    print_list(list);

}