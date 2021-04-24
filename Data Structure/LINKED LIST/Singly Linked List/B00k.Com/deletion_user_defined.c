#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node * next;
};
struct node * start=NULL;
struct node * insertion(int n)
{
    int data,i;
    struct node * ptr;
    struct node * p;
    start=(struct node *)malloc(sizeof(struct node ));
    if(start==NULL)
    {
        printf("Enable to insert the elements\n");
    }
    else
    {
        printf("Enter the node 1: ");
        scanf("%d",&data);
        start->data=data;
        start->next=NULL;
        p=start;
        for(i=2;i<=n;i++)
        {
            ptr=(struct node *)malloc(sizeof(struct node));
            if(ptr==NULL)
            {
                printf("Enable to insert the elements\n");
            }
            else
            {
                printf("Enter the node %d: ",i);
                scanf("%d",&data);
                ptr->data=data;
                ptr->next=NULL;
                p->next=ptr;
                p=p->next;
            }
        }
    }
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
    ptr->next=p->next;
    free(p);
    return start;
}
struct node * delete_after(struct node * start,int after)
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
struct node * delete_node(struct node * start,int data)
{
    struct node * ptr;
    struct node * p;
    p=start;
    if(p->data==data)
    {
        start=delete_beginning(start);
    }
    else
    {
        while(p->data!=data)
        {
            ptr=p;
            p=p->next;
        }
        ptr->next=p->next;
        free(p);
        return start;
    }
}
struct node * delete_list(struct node * start)
{
    struct node * ptr;
    if(start!=NULL)
    {
        while(ptr!=NULL)
        {
            start=delete_beginning(start);
        }
    }
    return start;
}
void display(struct node * ptr)
{
    while(ptr)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    int i,n=0,after,data;
    printf("Enter the number of node: ");
    scanf("%d",&n);
    insertion(n);
    printf("After insertion the linked list is\n");
    display(start);

    printf("\n");
    printf("Deleting  from Beginnning\n");
    start=delete_beginning(start);
    printf("After deleting form Beginning the linked list is\n");
    display(start);

    printf("\n");
    printf("Deleting from the End\n");
    start=delete_end(start);
    printf("After deleting from End the linked list is\n");
    display(start);

    printf("\n");
    printf("Enter the node after which you want to delete: ");
    scanf("%d",&after);
    start=delete_after(start,after);
    printf("After delteting the node after the node the linked list is: \n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to delete: ");
    scanf("%d",&data);
    start=delete_node(start,data);
    printf("After deleting the node the linked list is\n");
    display(start);

    printf("\n");
    printf("NOW deleting the whole list\n");
    start=delete_list(start);
    printf("After delete the whole list the linked list is\n");
    display(start);
}