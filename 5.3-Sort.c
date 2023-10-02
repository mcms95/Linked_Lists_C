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

void bubble_sort(Node* head) {
    // Base case: if the list is empty or has only one element
    if (head == NULL || head->next == NULL)
        return;

    int swapped;
    Node* current;
    Node* last = NULL;

    while (1) {
        swapped = 0;  // Flag to check if any elements were swapped in this pass
        current = head;

        // Traverse the list and compare adjacent nodes
        while (current->next != last) {
            if (current->value > current->next->value) {
                // Swap the values
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                swapped = 1;  // Set swapped flag if a swap occurred
            }
            current = current->next;
        }

        last = current;  // Mark the last node as sorted

        // If no two elements were swapped, the list is sorted
        if (!swapped)
            break;  // Exit the loop if no elements were swapped
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
    bubble_sort(list);
    print_list(list);

}