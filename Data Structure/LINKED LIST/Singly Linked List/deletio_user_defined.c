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
    int i,n=0,data;
    printf("Enter the number of Node: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the node %d: ",i+1);
        scanf("%d",&data);
        new_node(&start,data);
    }
    printf("The initial linked list is:\n");
    display(start);

    printf("\n");
    printf("Enter the number of node which you want to delete: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    printf("Enter the node %d: ",i+1);
    scanf("%d",&data);   
    delete_ndoe(&start,data);
    }
    printf("\nAfter deletion the node the linked list is:\n");
    display(start);
}

