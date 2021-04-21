#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node * next;
};
void new_node(struct node ** start,int data)
{
    struct node * ptr;
    ptr=(struct node *)malloc(sizeof(struct node *));
    ptr->data=data;
    ptr->next=(*start);
    (*start)=ptr;
}
void delete_ndoe(struct node ** start,int data)
{
    struct node * ptr;
    struct node * p=*start;
    if(p!=NULL && p->data==data)
    {
        (*start)=p->next;
        free(p);
        return;
    }
    while(p!=NULL && p->data!=data)
    {
        ptr=p;
        p=p->next;
    }
    if(p==NULL)
    return;
    ptr->next=p->next;
    free(p);
}
void display(struct node * ptr)
{
    while(ptr)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct node * start=NULL;
    new_node(&start,1);
    new_node(&start,2);
    new_node(&start,3);
    new_node(&start,4);
    new_node(&start,5);
    printf("The initial linked list is: \n");
    display(start);
    delete_ndoe(&start,2);
    delete_ndoe(&start,4);
    delete_ndoe(&start,5);
    printf("\nAfter deletion the node the lined list is: \n");
    display(start);
}

