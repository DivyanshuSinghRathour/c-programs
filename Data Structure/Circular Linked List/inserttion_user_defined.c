#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node * start=NULL;
struct node * create_circular_linked_list(struct node * start,int data)
{
    struct node * ptr;
    struct node * p;
    int i,n;
    printf("Enter the number of node: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the node %d: ",i);
        scanf("%d",&data);
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->data=data;
        if(start==NULL)
        {
            ptr->next=ptr;
            start=ptr;
        }
        else
        {
            p=start;
            while(p->next!=start)
            {
                p=p->next;
            }
            p->next=ptr;
            ptr->next=start;
        }
    }
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
    start=ptr;
    return start;
}
struct node * insert_at_end(struct node * start,int data)
{
    struct node * ptr;
    struct node * p;
    ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->data=data;
    p=start;
    while(p->next!=start)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=start;
    return start;
}
struct node * insert_after_node(struct node * start,int data,int after)
{
    struct node * ptr;
    struct node * p;
    struct node * preptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    p=start;
    preptr=p;
    while(preptr->data!=after)
    {
        preptr=p;
        p=p->next;
    }
    preptr->next=ptr;
    ptr->next=p;
    return start;
}
struct node * insert_before_node(struct node * start,int data,int before)
{
    struct node * ptr;
    struct node * p;
    struct node * preptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    p=start;
    while(p->data!=before)
    {
        preptr=p;   
        p=p->next;
    }
    preptr->next=ptr;
    ptr->next=p;
    return start;
}
int main()
{
    int data,i,n,after,before;
    printf("circular linked list is\n");
    start=create_circular_linked_list(start,data);
    printf("The initial linked list is\n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to insert at first: ");
    scanf("%d",&data);
    start=insert_at_first(start,data);
    printf("After insert at first the new linked list is\n");
    start=display(start);

    printf("\n");
    printf("Enter the node which you want to insert after the node: ");
    scanf("%d",&data);
    printf("AFTER: ");
    scanf("%d",&after);
    start=insert_after_node(start,data,after);
    printf("After insertion after the node the new linked linked list is\n");
    start=display(start);

    printf("\n");
    printf("Enter the node which you want to insert before the node: ");
    scanf("%d",&data);
    printf("BEFORE: ");
    scanf("%d",&before);
    start=insert_before_node(start,data,before);
    printf("After insertion before the node the new linked list is\n");
    start=display(start);

    printf("\n");
    printf("Enter the node which you want to insert at the end of the node: ");
    scanf("%d",&data);
    start=insert_at_end(start,data);
    printf("After insertion at end the new and final linked list is\n");
    start=display(start);

    return 0;
}