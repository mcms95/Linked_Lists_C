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

Node *inser_after_value(Node *head, int new_value, int after_value)
{
    Node *new_node = calloc(1, sizeof(Node));  // Allocate memory for the new node
    new_node->value = new_value;                // Set the value for the new node

    if (head == NULL) 
        return new_node;  // If the list is empty, the new node becomes the head
    else
    {
        Node *current = head;

        // Traverse the list to find the node with the specified value
        while(current->next != NULL)
        {
            // If the specified value is found, insert the new node after it
            if (current->value == after_value)
            {
                new_node->next = current->next;  // Set the new node's next to the current node's next
                current->next = new_node;  // Set the current node's next to the new node
                return head;
            }
            else
                current = current->next;  // Move to the next node
        }

        // If the specified value was not found, insert the new node at the end of the list
        new_node->next = current->next;  // Set the new node's next to NULL (end of the list)
        current->next = new_node;  // Set the current node's next to the new node
        return head;
    }
}


int main()
{
    Node *list = NULL;

    list = insert_head(list, 1);
    list = insert_head(list, 3);
    list = insert_head(list, 9);
    list = inser_after_value(list, 5, 3);

    print_list(list);

}