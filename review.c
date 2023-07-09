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
        new_node->next = head;
        return new_node;
}

Node *insert_tail(Node *head, int new_value)
{
    Node *new_node = calloc(1, sizeof(Node));
    new_node->value = new_value;
    if (head == NULL)
        return new_node;
    else
    {
        Node *current = head;
        while(current->next != NULL)
            current = current->next;
        current->next = new_node;
        return head;

    }

}

Node *delete_head(Node *head)
{
    Node *current = head;
    if (head == NULL)
        return NULL;
    else if (current->next == NULL)
    {    free(head);
        return NULL;
    }
    else
    {
        current = current->next;
        free(head);
        return current;
    }
}

Node *delete_tail(Node* head)
{
    
    if (head == NULL)
        return NULL;
    else if (head->next == NULL)
    {    free(head);
        return NULL;
    }
    else
    {
        Node *current = head;
        Node *prev = NULL;
        while(current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        free(current);
        return head;
        }
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
    Node *node  = NULL;
    node = insert(node, 2);
    node = insert(node, 3);
    node = insert(node, 4);
    node = insert_tail(node, 9);
    node = delete_head(node);
    node = delete_tail(node);
    print_list(node);
}

