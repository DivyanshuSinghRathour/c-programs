#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};

struct node * start=NULL;
struct node * create_circular_linked_list(struct node * start,int data);
struct node * display(struct node * start);
struct node * insert_at_first(struct node * start,int data);
struct node * insert_after_node(struct node * start,int data,int after);
struct node * insert_before_node(struct node * start,int data,int before);
struct node * insert_at_end(struct node * start,int data);
struct node * delete_beginning(struct node * start);
struct node * delete_end(struct node * start);
struct node * delete_after_node(struct node * start,int data);
struct node * delete_node(struct node * start,int data);
struct node * delete_list(struct node * start);

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
    ptr->next=p->next;
    free(p);
    return start;
}
struct node * delete_after_node(struct node * start,int data)
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
    ptr=start;
    if(start!=NULL)
    {
        while(ptr->next!=start)
        {
            start=delete_end(start);
            free(start);
        }
    }
        return start;
}
int main()
{
    int data,option,i,n,after,before;
    do
    {
        printf("\n___________________MAIN MENU__________________\n");
        printf("\t_____________Circular Linked List______________\n");
        printf("1: create circular linked list\n");
        printf("2: display the linked list\n");
        printf("3: insertion at first\n");
        printf("4: insertion after the node\n");
        printf("5: insertion before the node\n");
        printf("6: insertion at end\n");
        printf("7: deletion at beginning\n");
        printf("8: deletion at end\n");
        printf("9: deletion the node after the node\n");
        printf("10: deletion of the node which you want to delete\n");
        printf("11: delettion of whole linked list\n");
        printf("Please enter your choice: ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            start=create_circular_linked_list(start,data);
            break;
        case 2:
            start=display(start);
            break;
        case 3:
            printf("Enter the node which you want to insert at first: ");
            scanf("%d",&data);
            start=insert_at_first(start,data);
            break;
        case 4:
            printf("Enter the node which you want to insert after the node: ");
            scanf("%d",&data);
            printf("AFTER: ");
            scanf("%d",&after);
            start=insert_after_node(start,data,after);
            break;
        case 5:
            printf("Enter the node which you want insert before the node: ");
            scanf("%d",&data);
            printf("BEFORE: ");
            scanf("%d",&before);
            start=insert_before_node(start,data,before);
            break;
        case 6:
            printf("Enter the node which you want to insert at end: ");
            scanf("%d",&data);
            start=insert_at_end(start,data);
            break;
        case 7:
            start=delete_beginning(start);
            break;
        case 8:
            start=delete_end(start);
            break;
        case 9:
            printf("Enter the node which you want to delete after the node: ");
            scanf("%d",&data);
            start=delete_after_node(start,data);
            break;
        case 10:
            printf("Enter the node which you want to delete: ");
            scanf("%d",&data);
            start=delete_node(start,data);
            break;
        case 11:
            start=delete_list(start);
            break;
        case 12:
        default:
            exit;
        }
    } while (option!=12);
    return 0;
}
