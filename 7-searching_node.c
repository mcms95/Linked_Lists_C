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

int search(Node *head, int num)
{
    Node *current = head;
    int i = 1; 
    while(current != NULL)
    {
        if (current->data == num)
            return i;
        i++;
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
    Node *list_head = NULL;   
    list_head = insert_at_head(list_head, 4);
    list_head = insert_at_head(list_head, 5);
    list_head = insert_at_head(list_head, 6);
    
    print_list(list_head);
    int index = search(list_head, 4);
    if (index == 0)
        printf("Value found not found");
    else
        printf("Value found on node number: %d\n", index);
}