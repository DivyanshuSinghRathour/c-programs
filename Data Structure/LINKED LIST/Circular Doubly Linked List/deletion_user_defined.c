#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node * next;
    struct node * prev;
};
struct node * start=NULL;
struct node * insertion(struct node * start,int n)
{
    struct node * ptr;
    struct node * p;
    int data,i;
    printf("Enter the number of node: ");
    scanf("%d",&n);
    start=(struct node *)malloc(sizeof(struct node ));
    if(start==NULL)
    {
        printf("Enabe to insert the elements\n");
    }
    else
    {
        printf("Enter the node 1: ");
        scanf("%d",&data);
        start->data=data;
        start->next=start;
        start->prev=NULL;
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
                ptr->next=start;
                ptr->prev=p;
                start->prev=ptr;
                p->next=ptr;
                p=p->next;
            }
        }
    }
    return start;
}
struct node * delete_beginning(struct node * start)
{
    struct node * ptr;
    struct node * p;
    ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=start->next;
    p=start;
    start=start->next;
    start->prev=ptr;
    free(p);
    return start;
}
struct node * delete_end(struct node * start)
{
    struct node * ptr;
    struct node * p;
    p=start;
    while(p->next!=start)
    {
        p=p->next;
    }
    p->prev->next=start;
    start->prev=p->prev;
    free(p);
    return start;
}
struct node * delete_after(struct node * start,int data)
{
    struct node * ptr;
    struct node * p;
    ptr=start;
    while(ptr->data!=data)
    {
        ptr=ptr->next;
    }
    p=ptr->next;
    ptr->next=p->next;
    p->next->prev=ptr;
    free(p);
    return start;
}
struct node * delete_before(struct node * start,int data)
{
    struct node * ptr;
    struct node * p;
    ptr=start;
    while(ptr->data!=data)
    {
        ptr=ptr->next;
    }
    p=ptr->prev;
    if(p==start)
    {
        start=delete_beginning(start);
        return start;
    }
    ptr->prev=p->prev;
    p->prev->next=ptr;
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
            p=p->next;
        }
        p->prev->next=p->next;
        p->next->prev=p->prev;
        free(p);
        return start;
    }
}
struct node * display(struct node * start)
{
    struct node * ptr;
    struct node * node;
    ptr=start;
    printf("\nTraversing in Forward Direction\n");
    do
    {
        printf("%d ",ptr->data);
        node=ptr;
        ptr=ptr->next;
    }while(ptr!=start);
    printf("\n");
    printf("Traverersing in Backward Direction\n");
    do
    {
        printf("%d ",node->data);
        node=node->prev;
    }while(node->next!=start);
    return start;
}
int main()
{
    int data,n;
    printf("The Circular Doubly Linked list\n");
    start=insertion(start,n);
    printf("The initial linked list is\n");
    start=display(start);

    printf("\n\n");
    printf("Deletion at beginning: ");
    start=delete_beginning(start);
    printf("After deletion at beginning the linked list is\n");
    start=display(start);

    printf("\n\n");
    printf("Deletion at end\n");
    start=delete_end(start);
    printf("After deletion at end the linked list is\n");
    start=display(start);

    printf("\n");
    printf("Enter the node which you want to delete after the node: ");
    scanf("%d",&data);
    start=delete_after(start,data);
    printf("After deletion after the node the linked list is\n");
    start=display(start);

    printf("\n");
    printf("Enter the node which you want to delete before the node: ");
    scanf("%d",&data);
    start=delete_before(start,data);
    printf("After deletion before the node the linked list is\n");
    start=display(start);

    printf("\n");
    printf("Enter the node which you want to delete: ");
    scanf("%d",&data);
    start=delete_node(start,data);
    printf("After deletion the node the linked list is\n");
    start=display(start);

    return 0;
}