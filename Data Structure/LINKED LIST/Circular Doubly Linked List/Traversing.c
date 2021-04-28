#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node * next;
    struct node * prev;
};
struct node * display(struct node * start)
{
    struct node * ptr;
    struct node * node;
    ptr=start;
    printf("Traversing in Forward Direction\n");
    do
    {
        printf("%d ",ptr->data);
        node=ptr;
        ptr=ptr->next;
    }while(ptr!=start);
    printf("\n");
    printf("Traversing in Backward Direction\n");
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

    start->data=1;
    start->next=second;
    start->prev=third;

    second->data=2;
    second->next=third;
    second->prev=start;

    third->data=3;
    third->next=start;
    third->prev=second;

    start=display(start);
    return 0;
}