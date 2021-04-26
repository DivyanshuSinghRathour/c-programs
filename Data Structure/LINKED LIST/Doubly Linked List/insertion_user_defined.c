#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;
struct node *insertion(struct node *start, int n)
{
    struct node *ptr;
    struct node *p;
    int data, i;
    printf("Enter the number of node: ");
    scanf("%d", &n);
    start = (struct node *)malloc(sizeof(struct node));
    if (start == NULL)
    {
        printf("Enable to insert the elements\n");
    }
    else
    {
        printf("Enter the node 1: ");
        scanf("%d", &data);
        start->data = data;
        start->next = NULL;
        start->prev = NULL;
        p = start;
        for (i = 2; i <= n; i++)
        {
            ptr = (struct node *)malloc(sizeof(struct node));
            if (ptr == NULL)
            {
                printf("Enable to insert the elements\n");
            }
            else
            {
                printf("Enter the node %d: ", i);
                scanf("%d", &data);
                ptr->data = data;
                ptr->next = NULL;
                ptr->prev = p;
                p->next = ptr;
                p = p->next;
            }
        }
    }
    return start;
}
struct node *insert_at_first(struct node *start, int data)
{
    struct node *ptr;
    ptr = start;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = start;
    ptr->prev = NULL;
    if (start != NULL)
    {
        start->prev = ptr;
    }
    start = ptr;
    return start;
}
struct node *insert_between_node(struct node *start, int data, int index)
{
    struct node *ptr;
    struct node *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    p = start;
    int i = 1;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->prev = p;
    if (p != NULL)
    {
        p->next->prev = ptr;
    }
    p->next = ptr;
    return start;
}
struct node *insert_after(struct node **start, int data, int after)
{
    struct node *ptr;
    struct node *p;
    p = (*start);
    while (p != NULL)
    {
        if (p->data == after)
        {
            ptr = (struct node *)malloc(sizeof(struct node));
            ptr->data = data;
            ptr->next = p->next;
            ptr->prev = p;
            if (p != NULL)
            {
                p->next->prev = ptr;
            }
            p->next = ptr;
            return 0;
        }
        p = p->next;
    }
}
struct node *insert_before(struct node **start, int data, int before)
{
    struct node *ptr;
    struct node *p;
    p = (*start);
    ptr = (struct node *)malloc(sizeof(struct node));
    if ((*start)->data == before)
    {
        p->next = (*start);
        (*start) = ptr;
    }
    while (p && p->next)
    {
        if (p->next->data == before)
        {
            ptr->data = data;
            ptr->next = p->next;
            ptr->prev = p;
            if (p != NULL)
            {
                p->next->prev = ptr;
            }
            p->next = ptr;
            return 0;
        }
        p = p->next;
    }
    free(ptr);
}
struct node *insert_at_end(struct node *start, int data)
{
    struct node *ptr;
    struct node *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    p = start;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->prev = p;
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    struct node *node;
    if (start == NULL)
    {
        printf("EMPTY");
    }
    else
    {
        printf("Traversing in Forward Direction\n");
        ptr = start;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            node = ptr;
            ptr = ptr->next;
        }
    }
    printf("\n");
    if (start == NULL)
    {
        printf("EMPTY");
    }
    else
    {
        printf("Traversing in Backward Direction\n");
        while (node != NULL)
        {
            printf("%d ", node->data);
            node = node->prev;
        }
    }
    return start;
}
int main()
{
    int data, i, n = 0, after, before, index;
    printf("\n\nCreate Doubly Linked List\n");
    start = insertion(start, n);
    printf("The initial linked list\n");
    start = display(start);

    printf("\n\n");
    printf("Enter the node which you want to insert at first: ");
    scanf("%d", &data);
    start = insert_at_first(start, data);
    printf("After insrtion at first the linked list is\n");
    start = display(start);

    printf("\n\n");
    printf("Enter the node which you want to insert between the node: ");
    scanf("%d", &data);
    printf("INDEX: ");
    scanf("%d", &index);
    start = insert_between_node(start, data, index);
    printf("After insertion between the node the linked list is\n");
    start = display(start);

    printf("\n\n");
    printf("Enter the node which you want to insert after the node: ");
    scanf("%d", &data);
    printf("AFTER: ");
    scanf("%d", &after);
    insert_after(&start, data, after);
    printf("After insertion after the node the linked list is\n");
    start = display(start);

    printf("\n\n");
    printf("Enter the node which you want to inesrt before the node:  ");
    scanf("%d", &data);
    printf("BEFORE: ");
    scanf("%d", &before);
    insert_before(&start, data, before);
    printf("After insertion before the node the linked list is\n");
    start = display(start);

    printf("\n\n");
    printf("Enter the node which you want to insert at the node of the node: ");
    scanf("%d", &data);
    start = insert_at_end(start, data);
    printf("After insertion at the end of the node the linked is\n");
    start = display(start);

    return 0;
}