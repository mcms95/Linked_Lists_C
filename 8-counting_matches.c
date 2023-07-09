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

int count_matches(Node *head, int num)
{
    Node *current = head;
    int i = 0; 
    while(current != NULL)
    {
        if (current->data == num) // If match i++
            i++;
        current = current->next;
    }
    return i;
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
    node = insert(node, 4);
    node = insert(node, 5);
    node = insert(node, 5);
    node = insert(node, 5);
    node = insert(node, 6);
    node = insert(node, 5);
    print_list(node);
    
    int number = 5;
    int count = count_matches(node, number);
    printf("\nWe found the number %d, %d, times\n", number, count);
}