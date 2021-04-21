#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node * next;
};
struct node * start=NULL;
void insertion(int n);
void display();
int main()
{
    int n;
    printf("----------------The Linked List is--------------------\n");
    printf("______________________________________________________\n");
    printf("Enter the number of the node: ");
    scanf("%d",&n);
    printf("the initial linked list is :\n");
    insertion(n);
    printf("the final linked list is:\n");
    display();
    return 0;
}
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
void display()
{
    struct node * ptr;
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
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
    }
}
