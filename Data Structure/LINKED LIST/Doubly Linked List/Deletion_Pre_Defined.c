#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node * deletion_beginning(struct node * start)
{
    struct node * ptr;
    ptr=start;
    start=start->next;
    start->prev=NULL;
    free(ptr);
    return start;
}
struct node * delete_end(struct node * start)
{
    struct node * ptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
    return start;
}
struct node * delete_after(struct node * start,int after)
{
    struct node * ptr;
    struct node * p;
    ptr=start;
    while(ptr->data!=after)
    {
        ptr=ptr->next;
    }
    p=ptr->next;
    ptr->next=p->next;
    p->next->prev=ptr;
    free(p);
    return start;
}
struct node * delete_list(struct node * start)
{
    struct node * ptr;
    ptr=start;
    if(start!=NULL)
    {
        while(ptr!=NULL)
        {
            start=deletion_beginning(start);
        }
    }
    return start;
}
struct node * delete_before(struct node * start,int before)
{
    struct node * ptr;
    struct node * p;
    ptr=start;
    while(ptr->data!=before)
    {
        ptr=ptr->next;
    }
    p=ptr->prev;
    if(p==start)
    {
        start=deletion_beginning(start);
    }
    else
    {
        ptr->prev=p->prev;
        p->prev->next=ptr;
    }
    free(p);
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    struct node *node;
    ptr = start;
    printf("Traversing in Forward Direction\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        node = ptr;
        ptr = ptr->next;
    }
    printf("\n");
    printf("Traversing in Backward Direction\n");
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->prev;
    }
    return start;
}
int main()
{
    struct node *start = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    struct node *fourth = NULL;
    struct node *fifth = NULL;
    struct node *sixth = NULL;

    start = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));

    start->data = 2;
    start->next = second;
    start->prev = NULL;

    second->data = 4;
    second->next = third;
    second->prev = start;

    third->data = 6;
    third->next = fourth;
    third->prev = second;

    fourth->data = 7;
    fourth->next = fifth;
    fourth->prev = third;

    fifth->data = 8;
    fifth->next = sixth;
    fifth->prev = fourth;

    sixth->data = 9;
    sixth->next = NULL;
    sixth->prev = fifth;

    start = deletion_beginning(start);
    start = delete_end(start);
    start = delete_after(start, 4);
    start=delete_before(start,7);
    start=delete_list(start);
    start = display(start);
    return 0;
}