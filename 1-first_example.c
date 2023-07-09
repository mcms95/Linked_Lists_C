#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} Node; //Name of struct, when creating a node this is what we refer

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
    Node a, b, c;
    a.data = 5;
    b.data = 6;
    c.data = 7;
    
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    print_list(&a); //Point to adress of head of struct
}