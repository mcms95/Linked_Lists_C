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

int recursive_list_length(Node *head)
{
    if (head == NULL) 
        return 0;
    else    
        return 1 + recursive_list_length(head->next); 
}

int list_length(Node *head)
{
    Node *current = head;
    int i = 0; // If list is empty, we return 0
    while(current != NULL)
    {
        i++;
        current = current->next;
    }
    return i;
}

int main()
{
    Node *list_head = NULL;   
    list_head = insert_at_head(list_head, 4);
    list_head = insert_at_head(list_head, 5);
    list_head = insert_at_head(list_head, 6);
    
    int length = list_length(list_head);
    printf("Length: %d\n", length);
    int recursive_length = recursive_list_length(list_head);
    printf("Recursive length: %d\n", recursive_length);
}