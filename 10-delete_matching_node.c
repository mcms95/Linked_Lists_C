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
    else 
    {
        Node *current = head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
        return head;
    }
}

Node    *delete_matching_node(Node *head, int value)
{
    Node *current = head;
    Node *prev = NULL;

    if (current != NULL && current->data == value)
    {
        head = current->next;
        free(current);
        return head;
    }

    while (current != NULL && current->data != value)
    {
        prev = current;
        current = current->next; 
    }
    if(current != NULL)
    {
        prev->next = current->next;
        free(current);
    }
    return head;
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
    printf("\n\n");

    delete_matching_node(node, 6);
    print_list(node);

}