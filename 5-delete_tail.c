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

Node *delete_tail(Node *head)
{
    if (head == NULL) // List is Empty
        return NULL; 
    if (head->next == NULL) //List only have one node
    {
        free(head);
        return NULL;
    }
    else // List has more than one node
    {
        Node *current = head;  
        Node *prev = NULL;

        while(current->next != NULL) // While we are not at the tail
        {
            prev = current; // Node behind current
            current = current->next; // Will iterate through list 
        }    
        prev->next = NULL; // Set prev to tail
        free(current); // Free current node
        return head;
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
    list_head = insert_at_head(list_head, 9);
    list_head = insert_at_head(list_head, 6);
    list_head = insert_at_head(list_head, 3);
    printf("Before:\n");
    print_list(list_head);
    printf("\nAfter:\n");
    list_head = delete_tail(list_head);
    print_list(list_head);
    
}