#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node; //Name of struct, when creating a node this is what we refer


Node *insert(Node *head, int new_value)
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

void    replace_value(Node *head, int find_value, int replace_value)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == find_value)
            current->data = replace_value; //If match replace value
        current = current->next;
    }
}

void print_list(Node *head)
{
    Node *current = head;
    int i = 1;

    while (current != NULL)
    {
        printf("Node: %d value: %d\n", i, current->data);
        i++;
        current = current->next; // Same as (*current).next
    }
}

int main()
{
    Node *node = NULL;   
    printf("\nBefore replace:\n");
    node = insert(node, 4);
    node = insert(node, 5);
    node = insert(node, 5);
    node = insert(node, 6);
    node = insert(node, 5);
    print_list(node);

    printf("\nAfter replace:\n");
    replace_value(node, 5, 8);
    print_list(node);
}