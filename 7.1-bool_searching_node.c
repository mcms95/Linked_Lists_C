#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} Node; //Name of struct, when creating a node this is what we refer

bool is_member(Node *node, int find_value)
{
    if (node == NULL) 
        return false;       
    else if (node->data == find_value) // We find a match 
        return true;
    else // Check if next noe match
        is_member(node->next, find_value);
}

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

void print_list(Node *head)
{
    Node *current = head;
    int i = 0;

    while (current != NULL)
    {
        printf("Node: %d value: %d\n", i, current->data);
        i++;
        current = current->next; // Same as (*current).next
    }
}

int main()
{
    Node *list_head = NULL;   
    int number = 10;
    
    list_head = insert_at_head(list_head, 4);
    list_head = insert_at_head(list_head, 5);
    list_head = insert_at_head(list_head, 6);
    print_list(list_head);

    if (is_member(list_head, number))
        printf("\n\n%d is in the list!\n", number);
    else
        printf("\n\n%d is not the list!\n", number);
    
}