#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
struct node * insert_at_first(struct node * start,int data)
{
    struct node * ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=start;
    ptr->prev=NULL;
    if(start!=NULL)
    {
        start->prev=ptr;
    }
    start=ptr;
    return start;
}
struct node * insert_between_node(struct node * start,int data,int index)
{
    struct node * ptr;
    struct node * p;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    p=start;
    int i=1;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    ptr->prev=p;
    if(p!=NULL)
    {
        p->next->prev=ptr;
    }
    p->next=ptr;
    return start;
}
struct node * insert_after_node(struct node * start,struct node *prevnode,int data )
{
    struct node * ptr;
    ptr=start;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevnode->next;
    ptr->prev=prevnode;
    if(ptr->next!=NULL)
    {
        ptr->next->prev=ptr;
    }
    prevnode->next=ptr;
    return start;
}
struct node * insert_after(struct node ** start,int data,int after)
{
    struct node * ptr;
    struct node * p;
    p=(*start);
    if(p!=NULL)
    {
        while(p->data==after)
        {
            ptr=(struct node * )malloc(sizeof(struct node));
            ptr->data=data;
            ptr->next=p->next;
            ptr->prev=p;
            if(p!=NULL)
            {
                p->next->prev=ptr;
            }
            p->next=ptr;
            return 0;
        }
        p=p->next;
        return 0;
    }
    p=p->next;
}
struct node * insert_before(struct node ** start,int data,int before)
{
    struct node * ptr;
    struct node * p;
    p=(*start);
    ptr=(struct node *)malloc(sizeof(struct node ));;
    if((*start)->data==before)
    {
        p->next=(*start);
        (*start)=ptr;
    }
    while(p && p->next)
    {
        if(p->next->data==before)
        {
            ptr->data=data;
            ptr->next=p->next;
            ptr->prev=p;
            if(p!=NULL)
            {
                p->next->prev=ptr;
            }
            p->next=ptr;
            return 0;
        }
        p=p->next;
    }
    free(ptr);
}
struct node * display(struct node * start)
{
    struct node * ptr;
    struct node * node;
    ptr=start;
    printf("Traversing in Forward Direction\n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        node=ptr;
        ptr=ptr->next;
    }
    printf("\n");
    printf("Traversing in Backward Direction\n");
    while(node!=NULL)
    {
        printf("%d ",node->data);
        node=node->prev;
    }
    return start;
}
struct node * insert_at_end(struct node * start,int data)
{
    struct node * ptr;
    struct node * p;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    ptr->prev=p;
    return start;
}
int main()
{
    struct node *start = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    struct node *fourth = NULL;

    start = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

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
    fourth->next = NULL;

    fourth->prev = third;

    start=insert_at_first(start,1);
    start=insert_at_first(start,0);
    start=insert_between_node(start,56,3);
    start=insert_after_node(start,third,89);
    start=insert_at_end(start,100);
    insert_after(&start,123,4);
    insert_before(&start,321,123);
    start=display(start);
    return 0;
}