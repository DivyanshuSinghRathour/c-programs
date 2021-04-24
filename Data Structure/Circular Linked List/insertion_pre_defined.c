#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
}
struct node *insert_at_first(struct node *start, int data)
{
    struct node *ptr;
    struct node *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    p = start;
    while (p->next != start)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = start;
    start = ptr;
    return start;
}
struct node *insert_at_end(struct node *start, int data)
{
    struct node *ptr;
    struct node *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    p = start;
    while (p->next != start)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = start;
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
    ptr->data = data;
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
int main()
{
    struct node *start = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    start = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    start->data = 1;
    start->next = second;

    second->data = 4;
    second->next = third;

    third->data = 5;
    third->next = start;

    start = insert_at_first(start, 6);
    start = insert_at_end(start, 8);
    start = insert_after_node(start, 89, 4);
    start = insert_before_node(start, 67, 4);

    start = display(start);
    return 0;
}