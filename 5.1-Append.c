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

// Append 2 lists
Node *append(Node *head1, Node *head2)
{
    if (head1 == NULL)  return head2; // head1 is empty
    
    Node *currrent = head1;
    while (currrent->next != NULL) currrent = currrent->next; // Transverse untill end of the list1
    currrent->next = head2; // Point last node to the head2
    return head1;
}

int main()
{
    Node *list = NULL;

    list = insert_head(list, 1);
    list = insert_head(list, 2);
    list = insert_head(list, 3);

    Node *list2 = NULL;

    list2 = insert_head(list2, 4);
    list2 = insert_head(list2, 5);
    list2 = insert_head(list2, 6);
    
    list = append(list, list2);
    print_list(list);
    

}