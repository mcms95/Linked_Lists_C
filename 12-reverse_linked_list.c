#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}Node;

Node *insert(Node *head, int new_value)
{
    Node *new_node = calloc(1, sizeof(Node));
    new_node->value = new_value;
    if (head == NULL) // list is empty
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
Node *reverse_list(Node *head) 
{
    if (head == NULL) 
        return NULL;
    if (head->next == NULL)
        return head;

    Node *current = head; 
    Node *next_node = head->next; 
    current->next = NULL; //Set new "tail" to NULL
    while (next_node != NULL)
    {
        Node *tmp = next_node->next; //store next next_node to tmp to use it later
        next_node->next = current; //Set pointer to node before
        current = next_node; //current advances to next node
        next_node = tmp; //next node advances to next node
    }
    return current; // New head
}

void *print_list(Node *head)
{
    Node *current = head;
    int i = 0;
    while (current != NULL)
    {
        printf("Node: %d, Value: %d\n", i++, current->value);
        current = current->next;
    }
}

int main()
{   
    printf("\nList 1:\n");
    Node *list1  = NULL;
    for (int i = 0; i < 3; i++)
        list1 = insert(list1, i);
    printf("Original list:\n");
    print_list(list1);
    list1 = reverse_list(list1);
    printf("\nReversed list:\n");
    print_list(list1);

}