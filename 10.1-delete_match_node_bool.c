#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

Node    *delete_matching_node(Node *head, int value, bool *match)
{
    Node *current = head;
    Node *prev = NULL;

    if (head == NULL) //If head is NULL
    {
        *match = false;
        return NULL;
    }
    if (head->data == value) // If head Match value
    {
        head = head->next; 
        free(current);
        *match = true;
        return head; 
    }
    while (current != NULL)
    {
        if(current->data == value)
        {
            prev->next = current->next; 
            free(current);
            *match = true;
            return head;
        }
        prev = current;
        current = current->next;
    }
    *match = false;
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
    node = insert(node, 4);
    node = insert(node, 5);
    node = insert(node, 5);
    node = insert(node, 6);
    node = insert(node, 5);
    bool match;
    node = delete_matching_node(node, 4, &match); //pass by reference
    if (match)
        printf("\nYou deleted a match\n");
    else
        printf("No match");
    print_list(node);

}