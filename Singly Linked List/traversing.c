#include<stdio.h>
#include<stdlib.h>
void display();
struct node 
{
    int data;
    struct node * next;
};
void display(struct node * ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    
}
int main()
{
    struct node * start=NULL;
    struct node * second=NULL;
    struct node * third=NULL;
    struct node * fourth=NULL;

    start=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));

    start->data=2;
    start->next=second;

    second->data=3;
    second->next=third;

    third->data=5;
    third->next=fourth;

    fourth->data=7;
    fourth->next=NULL;
    display(start);
    return 0;
}