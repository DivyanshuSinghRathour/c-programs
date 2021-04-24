#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *second = NULL;
struct node *third = NULL;
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    return start;
}
int main()
{
    start = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    start->data = 3;
    start->next = second;

    second->data = 5;
    second->next = third;

    third->data = 7;
    third->next = start;

    start = display(start);

    return 0;
}