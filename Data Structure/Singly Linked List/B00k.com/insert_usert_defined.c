#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
void insertion(int n)
{
    int data, i;
    struct node *ptr;
    struct node *p;
    start = (struct node *)malloc(sizeof(struct node));
    if (start == NULL)
    {
        printf("Enable to insert the elements\n");
        return;
    }
    else
    {
        printf("Enter the node 1: ");
        scanf("%d", &data);
        start->data = data;
        start->next = NULL;
        p = start;
        for (i = 2; i <= n; i++)
        {
            ptr = (struct node *)malloc(sizeof(struct node));
            if (ptr == NULL)
            {
                printf("Enable to insert the elements\n");
                return;
            }
            else
            {
                printf("Enter the node %d: ", i);
                scanf("%d", &data);
                ptr->data = data;
                ptr->next = NULL;
                p->next = ptr;
                p = p->next;
            }
        }
    }
}
struct node *insert_at_first(struct node *start, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = start;
    start = ptr;
    return start;
}
struct node *insert_after_node(struct node *start, int data, int after)
{
    struct node *ptr;
    struct node *p;
    struct node *preptr;

    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    p = start;
    preptr = p;
    while (preptr->data != after)
    {
        preptr = p;
        p = p->next;
    }
    preptr->next = ptr;
    ptr->next = p;
    return start;
}
struct node *insert_before_node(struct node *start, int data, int before)
{
    struct node *ptr;
    struct node *p;
    struct node *preptr;

    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    p = start;
    while (p->data != before)
    {
        preptr = p;
        p = p->next;
    }
    preptr->next = ptr;
    ptr->next = p;
    return start;
}
struct node *insert_at_end(struct node *start, int data)
{
    struct node *ptr;
    struct node *p = start;
    ptr=(struct node * )malloc(sizeof(struct node));
    ptr->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return start;
}
void display()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("EMPTY\n");
    }
    else
    {
        ptr = start;
        while (ptr!=NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}
int main()
{
    int n = 0, after, before,data;
    printf("Enter the number of node: ");
    scanf("%d", &n);
    insertion(n);
    printf("The initial linked list is: \n");
    display(start);

    printf("\n");
    printf("Enter the node of node which you want to insert at first:  ");
    scanf("%d",&data);
    start=insert_at_first(start,data);
    printf("After insertion the linked list is\n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to insert after the node:  ");
    scanf("%d",&data);
    printf("AFTER: ");
    scanf("%d",&after);
    start=insert_after_node(start,data,after);
    printf("After insertion the linked list is\n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to insert before the node: ");
    scanf("%d",&data);
    printf("BEFORE: ");
    scanf("%d",&before);
    start=insert_before_node(start,data,before);
    printf("After insertion the linked list is\n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to insert in the last: ");
    scanf("%d",&data);
    start=insert_at_end(start,data);
    printf("After insertion the linked list list is\n");
    display(start);
}