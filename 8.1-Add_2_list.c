// Add 2 linked lists, the value on the ith node should be added together in the ith node in list1 shouldb be set to the result
// If length of lists are diferent, sum until the sortest os the 2 lists legth

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

Node *add_list(Node *list1, Node *list2)
{
    Node *current1 = list1;  // Pointer to traverse the first list
    Node *current2 = list2;  // Pointer to traverse the second list

    // Check if either list is empty
    if (list1 == NULL || list2 == NULL)
        return NULL;  // If either list is empty, return NULL

    // Traverse both lists and add values from list2 to list1
    while (current1 != NULL && current2 != NULL)
    {
        // Add the value from the second list to the corresponding node in the first list
        current1->value += current2->value;

        // Move to the next node in both lists
        current1 = current1->next;
        current2 = current2->next;
    }

    return list1;  // Return the updated first list
}


int main()
{
    Node *list1 = NULL;

    list1 = insert_head(list1, 1);
    list1 = insert_head(list1, 3);
    list1 = insert_head(list1, 9);

    Node *list2 = NULL;

    list2 = insert_head(list2, 1);
    list2 = insert_head(list2, 3);
    list2 = insert_head(list2, 9);

    print_list(list1);

    list1 = add_list(list1, list2);

    print_list(list1);

}