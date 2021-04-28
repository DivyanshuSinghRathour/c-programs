#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node * next;
    struct node * prev;
};
struct node * star=NULL;
struct node * insert_at_first(struct node * start,int data)
{
    struct node * ptr;
    struct node * p;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    p=start;
    while(p->next!=start)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=start;
    ptr->prev=p;
    start->prev=ptr;
    start=ptr;
    return start;
}
struct node * delete_beginning(struct node * start)
{
    struct node * ptr;
    struct node * p;
    ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=start->next;
    p=start;
    start=start->next;
    start->prev=ptr;
    free(p);
    return start;
}
struct node * delete_end(struct node * start)
{
    struct node * ptr;
    struct node * p;
    p=start;
    while(p->next!=start)
    {
        p=p->next;
    }
    p->prev->next=start;
    start->prev=p->prev;
    free(p);
    return start;
}
struct node * delete_after(struct node * start,int data)
{
    struct node * ptr;
    struct node * p;
    ptr=start;
    while(ptr->data!=data)
    {
        ptr=ptr->next;
    }
    p=ptr->next;
    ptr->next=p->next;
    p->next->prev=ptr;
    free(p);
    return start;
}
struct node * delete_before(struct node * start,int data)
{
    struct node * ptr;
    struct node * p;
    ptr=start;
    while(ptr->data!=data)
    {
        ptr=ptr->next;
    }
    p=ptr->prev;
    if(p==start)
    {
        start=delete_beginning(start);
        return start;
    }
    ptr->prev=p->prev;
    p->prev->next=ptr;
    free(p);
    return start;
}
struct node * delete_node(struct node * start,int data)
{
    struct node * ptr;
    struct node * p;
    p=start;
    if(p->data==data)
    {
        start=delete_beginning(start);
        return start;
    }
    else
    {
        while(p->data!=data)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        p->next->prev=p->prev;
        free(p);
        return start;
    }
}
struct node * display(struct node * start)
{
    struct node * ptr;
    struct node * node;
    ptr=start;
    printf("\nTraversing in Forward Direction\n");
    do
    {
        printf("%d ",ptr->data);
        node=ptr;
        ptr=ptr->next;
    }while(ptr!=start);
    printf("\n");
    printf("Traverersing in Backward Direction\n");
    do
    {
        printf("%d ",node->data);
        node=node->prev;
    }while(node->next!=start);
    return start;
}
int main()
{
    struct node * start=NULL;
    struct node * second=NULL;
    struct node * third=NULL;

    start=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));

    start->data=5;
    start->next=second;
    start->prev=third;

    second->data=6;
    second->next=third;
    second->prev=start;

    third->data=7;
    third->next=start;
    third->prev=second;

    start=insert_at_first(start,4);
    start=insert_at_first(start,3);
    start=insert_at_first(start,2);
    start=insert_at_first(start,1);
    start=delete_beginning(start);
    start=delete_end(start);
    start=delete_after(start,3);
    start=delete_before(start,5);
    start=delete_node(start,6);
    start=display(start);
    return 0;
}