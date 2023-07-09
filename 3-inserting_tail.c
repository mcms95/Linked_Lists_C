#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node; //Name of struct, when creating a node this is what we refer


Node *insert_at_tail(Node *head, int new_value)
{
    Node *new_node = calloc( 1, sizeof(Node));
    new_node->data = new_value;
    if(head == NULL) // List is Empty
        return new_node; 
    else // Add node to head
    {
        Node *current = head;
        while(current->next != NULL) //Looking for tail
            current = current->next;
        current->next = new_node; //Set tail to new node
        return head; 
    }
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
    list_head = insert_at_head(list_head, 4);
    list_head = insert_at_head(list_head, 5);
    list_head = insert_at_head(list_head, 6);
    list_head = insert_at_tail(list_head, 12);
    list_head = insert_at_tail(list_head,66);
    printf("Printing out inserted node:\n");
    print_list(list_head);
}