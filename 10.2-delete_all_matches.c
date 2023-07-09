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

Node    *delete_all_matching_node(Node *head, int value, int *count)
{
    Node *current = head;
    Node *temp = NULL;
    if (head == NULL)
        return NULL;
    while (head->data == value) //While value match at head, move forward and free them
    {
        temp = head;
        head = head->next;
        free(temp);
        *count += 1;// How many node were deleted

        if (head == NULL) //
            return NULL;
    }
    current = head; // Set current to start in new head

    while(current->next != NULL)
    {
        if (current->next->data == value) // If the value in next node match
        {
        temp = current->next; //Set tmp to next node
        current->next = current->next->next; // Set current to 2 node forward
        free(temp); //Free the node that matches
        *count += 1; // How many node were deleted
        }
        else
            current = current->next; // Iterate
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
    node = insert(node, 5);
    node = insert(node, 3);
    node = insert(node, 5);
    node = insert(node, 5);
    node = insert(node, 5);
    node = insert(node, 9);
    node = insert(node, 5);
    node = insert(node, 2);
    node = insert(node, 5);
    printf("\nBefore\n");
    print_list(node);
    int count;
    node = delete_all_matching_node(node, 5, &count);
    printf("\nAfter\n");
    print_list(node);
    printf("\nWe deleted %d's nodes\n", count);

}