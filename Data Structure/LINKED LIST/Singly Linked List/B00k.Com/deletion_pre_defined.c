#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node *insert_at_first(struct node *start, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = start;
    start = ptr;
    return start;
}
struct node * delete_beginning(struct node * start)
{
    struct node * ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
}
struct node * delete_end(struct node * start)
{
    struct node * ptr;
    struct node * p;
    p=start;
    while(p->next!=NULL)
    {
        ptr=p;
        p=p->next;
    }
    ptr->next=NULL;
    free(p);
    return start;
}
struct node * delete_after(struct node *start,int after)
{
    struct node * ptr;
    struct node * p;
    p=start;
    ptr=p;
    while(ptr->data!=after)
    {
        ptr=p;
        p=p->next;
    }
    ptr->next=p->next;
    free(p);
    return start;
}
struct node * delete_list(struct node * start)
{
    struct node * ptr;
    if(start!=NULL)
    {
        ptr=start;
        while(ptr!=NULL)
        {
            start=delete_beginning(ptr);
            ptr=start;
        }
    }
    return start;
}
void display(struct node * ptr)
{
    while(ptr!=NULL)
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
    struct node * fourth=NULL;

    start=(struct node *)malloc(sizeof(struct node ));
    second=(struct node *)malloc(sizeof(struct node ));
    third=(struct node *)malloc(sizeof(struct node ));
    fourth=(struct node *)malloc(sizeof(struct node ));

    start->data=56;
    start->next=second;

    second->data=4;
    second->next=third;

    third->data=5;
    third->next=fourth;

    fourth->data=6;
    fourth->next=NULL;

    start=insert_at_first(start,1);
    start=insert_at_first(start,46);
    start=insert_at_first(start,89);
    start=delete_beginning(start);
    start=delete_end(start);
    start=delete_after(start,4);     
    //start=delete_list(start);
    display(start);
}