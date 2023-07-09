#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node; //Name of struct, when creating a node this is what we refer


Node *insert_at_head(Node *head, int new_value)
{
    Node *new_node = calloc( 1, sizeof(Node));
    new_node->data = new_value;
    if(head == NULL) // List is Empty
        return new_node; 
    else // Add node to head
    {
        new_node->next = head;
        return new_node;
    }
}

Node *delete_head(Node *head)
{
    if (head == NULL) // List is Empty
        return NULL; 
    else
    {
        Node *to_return = head->next; // Point to where head points to
        free(head); // Free head of the list
        return to_return; // Return the new head
    }
}

void print_list(Node *head)
{
    Node *current = head;
    int i = 0;
    while(current != NULL)
    {
        printf("Node: %d, value: %d\n", i, current->data);
        i++;
        current = current->next;
    }
}

int main()
{
    Node *list_head = NULL;   
    list_head = insert_at_head(list_head, 9);
    list_head = insert_at_head(list_head, 6);
    list_head = insert_at_head(list_head, 3);
    printf("Before:\n");
    print_list(list_head);
    printf("\nAfter:\n");
    list_head = delete_head(list_head);
    print_list(list_head);
    
}