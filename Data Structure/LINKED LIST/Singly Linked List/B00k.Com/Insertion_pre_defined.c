#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node * insert_at_first(struct node * start,int data)
{
    struct node * ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=start;
    start=ptr;
    return start;
}
struct node * insert_after_node(struct node * start,int data, int after)
{
    struct node * ptr;
    struct node * p;
    struct node * preptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    p=start;
    preptr=p;
    while(preptr->data!=after)
    {
        preptr=p;
        p=p->next;
    }
    preptr->next=ptr;
    ptr->next=p;
    return start;
}
struct node * insert_before_node(struct node * start,int data,int before)
{
    struct node * ptr;
    struct node * p;
    struct node * preptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    p=start;
    while(p->data!=before)
    {
        preptr=p;
        p=p->next;
    }
    preptr->next=ptr;
    ptr->next=p;
    return start;
}
struct node * insert_at_end(struct node * start,int data)
{
    struct node * ptr;
    struct node * p = start;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return start;
}
void display(struct node * ptr)
{
    while(ptr)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct node * start=NULL;
    struct node * second=NULL;
    struct node * third=NULL;

    start=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));

    start->data=2;
    start->next=second;

    second->data=4;
    second->next=third;

    third->data=6;
    third->next=NULL;

    start=insert_at_first(start,1);
    start=insert_after_node(start,3,2);
    start=insert_before_node(start,5,6);
    start=insert_at_end(start,7);
    start=insert_at_end(start,8);
    display(start);
}