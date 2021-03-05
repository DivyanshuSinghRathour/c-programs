#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node * start = NULL;
struct node * second = NULL;
struct node * third = NULL;
struct node * fourth = NULL;

struct node * insert_at_first(struct node * start,int data)
{
    struct node * ptr;
    ptr=(struct node *)malloc(sizeof(struct node *));
    ptr->data=data;
    ptr->next=start;
    return ptr;
}
struct node * insert_beween_node(struct node * start,int data,int index)
{
    struct node * ptr,*p=start;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    int i=0;
    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return start;
}
struct node * insert_after_node(struct node * start,struct node * prevnode,int data)
{
    struct node * ptr;
    ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return start;
}
struct node * insert_at_end(struct node * start,int data)
{
    struct node * ptr;
    struct node * p=start;
    ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->data=data;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return start;
}
struct node * insert_after_node_two(struct node * start,int data,int after)
{
    struct node * ptr;
    struct node * p=start;
    while(p!=NULL)
    {
        if(p->data==after)
        {
            ptr=(struct node *)malloc(sizeof(struct node) );
            ptr->data=data;
            ptr->next=p->next;
            p->next=ptr;
            return 0;
        }
        p=p->next;
    }
}
struct node * insert_before_node(struct node ** start,int data,int before)
{
    struct node * ptr;
    struct node * p = *start;
    ptr=(struct node *)malloc(sizeof(struct node ));
    if((*start)->data==before)
    {
        p->next=(*start);
        (*start)=ptr;
    }
    while(p && p->next)
    {
        if(p->next->data==before)
        {
            ptr=(struct node * )malloc(sizeof(struct node ));
            ptr->data=data;
            ptr->next=p->next;
            p->next=ptr;
            return 0;
        }
        p=p->next;
    }
    free(ptr);
}
void display(struct node * ptr)
{
    do
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }while(ptr!=start);
}
int main()
{


    start=(struct node *)malloc(sizeof(struct node ));
    second=(struct node *)malloc(sizeof(struct node ));
    third=(struct node *)malloc(sizeof(struct node ));
    fourth=(struct node *)malloc(sizeof(struct node ));

    start->data=2;
    start->next=second;

    second->data=4;
    second->next=third;

    third->data=6;
    third->next=fourth;

    fourth->data=9;
    fourth->next=NULL;

    start=insert_at_first(start,1);
    start=insert_beween_node(start,3,2);
    start=insert_after_node(start,second,5);
    insert_after_node_two(start,7,6);
    insert_before_node(&start,8,9);
    start=insert_at_end(start,10);
    display(start);
}