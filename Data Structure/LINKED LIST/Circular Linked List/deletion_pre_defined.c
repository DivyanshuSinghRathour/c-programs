#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node * next;
};
struct node * start=NULL;
struct node * delete_beginning(struct node * start)
{
    struct node * ptr;
    ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=start->next;
    free(start);
        start=ptr->next;
    return start;
}
struct node * delete_end(struct node * start)
{
    struct node * ptr;
    struct node * p;
    p=start;
    while(p->next!=start)
    {
        ptr=p;
        p=p->next;
    }
    p->next=ptr->next;
    ptr->next=start;
    free(p);
    return start;
}
struct node * delete_after(struct node * start,int data)
{
    struct node * ptr;
    struct node * p;
    p=start;
    ptr=p;
    while(ptr->data!=data)
    {
        ptr=p;
        p=p->next;
    }
    ptr->next=p->next;
    free(p);
    return start;
}
struct node * delete_node(struct node * start,int data)
{
    struct node * ptr;
    struct node *p;
    p=start;
    if(p->data==data)
    {
        start=delete_end(start);
        return start;
    }
    else
    {
        while(p->data!=data)
        {
            ptr=p;
            p=p->next;
        }
        ptr->next=p->next;
        p->next=start;
        free(p);
        return start;
    }
}
struct node * delete_list(struct node * start)
{
    struct node * ptr;
    ptr=start;
    if(start!=NULL)
    {
        while(ptr->next!=start)
        {
            start=delete_end(start);
            free(start);
        }
    }
    free(start);
    return start;
}
struct node * display(struct node * start)
{
    struct node * ptr;
    ptr=start;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    } while (ptr!=start);
    
}
int main()
{
    struct node * start=NULL;
    struct node * second=NULL;
    struct node * third=NULL;
    struct node * fourth=NULL;
    struct node * fiveth=NULL;
    struct node * sixth=NULL;

    start=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    fiveth=(struct node *)malloc(sizeof(struct node));
    sixth=(struct node *)malloc(sizeof(struct node));

    start->data=1;
    start->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=4;
    fourth->next=fiveth;

    fiveth->data=5;
    fiveth->next=sixth;

    sixth->data=6;
    sixth->next=start;

    start=delete_beginning(start);
    start=delete_end(start);
    start=delete_after(start,4);
    start=delete_node(start,4);
    start=display(start);
    printf("\n");
    start=delete_list(start);
    start=display(start);
    return 0;
}