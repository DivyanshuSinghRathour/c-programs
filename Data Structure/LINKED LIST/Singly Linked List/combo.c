#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node * next;
};
struct node * start = NULL;
//Mere man wali linked list
void insertion(int n)
{
    struct node * ptr,*p;
    int i,data;
    start=(struct node *)malloc(sizeof(struct node ));
    if(start==NULL)
    {
        printf("Enable to insert the linked list\n");
        return;
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
            ptr=(struct node *)malloc(sizeof(struct node ));
            if(ptr==NULL)
            {
                printf("Enable to insert the linked list\n");
                return;
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
//Insertion at first
struct node * insert_at_first(struct node * start,int data)
{
    struct node * ptr;
    ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->data=data;
    ptr->next=start;
    return ptr;
}
//insertion between the node
struct node * insert_between_node(struct node * start,int data,int index)
{
    struct node * ptr;
    struct node * p=start;
    ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->data=data;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return start;
}
//insertion at last
struct node * insert_at_end(struct node * start,int data)
{
    struct node * ptr;
    struct node * p=start;
    ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->data=data;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return start;
}
//insertion after the node
struct node * insert_after_node(struct node * start,int data,int after)
{
    struct node * ptr;
    struct node * p=start;
    while(p!=NULL)
    {
        if(p->data==after)
        {
            ptr=(struct node *)malloc(sizeof(struct node ));
            ptr->data=data;
            ptr->next=p->next;
            p->next=ptr;
            return 0;
        }
        p=p->next;
    }

}
//Insertion before the node
struct node * insert_before_node(struct node ** start,int data,int before)
{
    struct node * ptr;
    struct node * p=*start;
    ptr=(struct node *)malloc(sizeof(struct node ));
    if((*start)->data==before)
    {
        p->next=(*start);
        (*start)=ptr;
    }
    while(p && p->next)
    {
        if(p->next->data==before)
        {
            ptr->data=data;
            ptr->next=p->next;
            p->next=ptr;
            return 0;
        }
        p=p->next;
    }
    free(ptr);
}
// display the node 
void display()
{
    struct node * ptr;
    printf("H->");
    if(start==NULL)
    {
        printf("List Is Empty\n");
        return;
    }
    else
    {
        ptr=start;
        while(ptr!=NULL)
        {
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }
    }
    printf("|||");
}
//Main function
int main()
{
    int data,n=0,i,after,before,index;
    char prevnode[20];
    printf("----------------The Linked List is--------------------\n");
    printf("______________________________________________________\n");
    printf("Enter the number of the node: ");
    scanf("%d",&n);
    printf("the initial linked list is :\n");
    insertion(n);
    printf("the final linked list is:\n");
    display();

    printf("\n");
    printf("Enter the node which you want to insert in the first: ");
    scanf("%d",&data);
    start=insert_at_first(start,data);
    printf("After insert the node at first: \n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to insert between the node: ");
    scanf("%d",&data);
    printf("Enter the insdex:");
    scanf("%d",&index);
    start=insert_between_node(start,data,index);
    printf("After insertion the linked list is: \n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to enter after the node: ");
    scanf("%d",&data);
    printf("after: ");
    scanf("%d",&after);
    insert_after_node(start,data,after);
    printf("After insertion the linked is: \n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to insert before the node: ");
    scanf("%d",&data);
    printf("before: ");
    scanf("%d",&before);
    insert_before_node(&start,data,before);
    printf("After insertion the linked list is: \n");
    display(start);

    printf("\n");
    printf("Enter the node wihch you want to insert in the last: ");
    scanf("%d",&data);
    start=insert_at_end(start,data);
    printf("After insertion the linked list is: ");
    display(start);
}