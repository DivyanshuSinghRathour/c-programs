#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node * next;
    struct node * prev;
};

void display(struct node * ptr)
{
    struct node * node;
    printf("Traversing in forward direction:\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        node= ptr;
        ptr=ptr->next;
    }
    printf("\n");
    printf("Traversing in reverse direction: \n");
    while(node!=NULL)
    {
        printf("%d\t",node->data);
        node=node->prev;
    }
}
int main()
{
    struct node * start=NULL;
    struct node * second=NULL;
    struct node * third=NULL;
    struct node * fourth=NULL;

    start=(struct node * )malloc(sizeof(struct node));
    second=(struct node * )malloc(sizeof(struct node));
    third=(struct node * )malloc(sizeof(struct node));
    fourth=(struct node * )malloc(sizeof(struct node));

    start->data=1;
    start->next=second;
    start->prev=NULL;

    second->data=2;
    second->next=third;
    second->prev=start;

    third->data=3;
    third->next=fourth;
    third->prev=second;

    fourth->data=4;
    fourth->next=NULL;
    fourth->prev=third;

    display(start);

}