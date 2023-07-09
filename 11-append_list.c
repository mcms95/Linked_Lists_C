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
Node *append(Node *head, Node *head2) //Append lists
{
    Node *append = head;
    if (head == NULL)// If first list is empty return second list
        return head2;
    while(append->next != NULL) // Iterate firts list
        append = append->next;
    append->next = head2; //Point tail pointer to head of new list
    return head;

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
    print_list(list1);

    printf("\nList 2:\n");
    Node *list2  = NULL;
    for (int i = 3; i < 7; i++)
        list1 = insert(list1, i);
    print_list(list1);

    printf("\nList 1 & 2:\n");
    Node *sum = append(list1, list2);
    print_list(sum);
}

