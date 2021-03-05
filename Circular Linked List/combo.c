#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
void  insertion(int n)
{
    int data,i;
    struct node * ptr;
    struct node * p;
    start=(struct node *)malloc(sizeof(struct node ));
    if(start==NULL)
    {
        printf("Enable to insert the enable the elements\n");
    }
    else
    {
        printf("Enter the node 1: ");
        scanf("%d",&data);
        start->data=data;
        start->next=NULL;
        p=start;
        for( i=2;i<=n;i++)
        {
            if(ptr==NULL)
            {
                printf("Enable to insert the elements\n");
            }
            else
            {
                ptr=(struct node *)malloc(sizeof(struct node ));
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
        printf("EMPTY");
    }
    else
    {
        printf("H->");
        ptr=start;
        do
        {
            printf("%d->",ptr->data);
            ptr=ptr->next;
        } while (ptr!=NULL);
        printf("|||\n");
    }
}
struct node *insert_at_first(struct node *start, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = start;
    return ptr;
}
struct node *insert_between_node(struct node *start, int data, int index)
{
    struct node *ptr;
    struct node *p = start;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return start;
}
struct node *insert_after_the_node_part_two(struct node *start, int data, int after)
{
    struct node *ptr;
    struct node *p = start;
    while (p != NULL)
    {
        if (p->data == after)
        {
            ptr = (struct node *)malloc(sizeof(struct node));
            ptr->data = data;
            ptr->next = p->next;
            p->next = ptr;
            return 0;
        }
        p = p->next;
    }
}
struct node *insert_before_the_node(struct node **start, int data, int before)
{
    struct node *ptr;
    struct node *p = *start;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    if ((*start)->data == before)
    {
        p->next = (*start);
        (*start) = ptr;
    }
    while (p && p->next)
    {
        if (p->next->data == before)
        {
            ptr->data = data;
            ptr->next = p->next;
            p->next = ptr;
            return 0;
        }
        p = p->next;
    }
    free(ptr);
}
struct node *insert_at_the_end(struct node *start, int data)
{
    struct node *ptr;
    struct node *p = start;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return start;
}
int main()
{
    int n = 0, i, index, after, before, data;
    printf("Enter the number of the element: ");
    scanf("%d", &n);
    insertion(n);
    printf("the initial linked list is: \n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to insert at first: ");
    scanf("%d",&data);
    start=insert_at_first(start,data);
    printf("After inseting the linked list is:\n");
    display(start);

    printf("\n");
    printf("Enter the node which you  want to insert between the node: ");
    scanf("%d", &data);
    printf("Index: ");
    scanf("%d", &index);
    start = insert_between_node(start, data, index);
    printf("After inserting the node the linked list is: \n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to insert after the node: ");
    scanf("%d", &data);
    printf("After: ");
    scanf("%d", &after);
    insert_after_the_node_part_two(start, data, after);
    printf("After inserting the node the linked list is: \n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to insert before the node: ");
    scanf("%d", &data);
    printf("Before: ");
    scanf("%d", &before);
    insert_before_the_node(&start, data, before);
    printf("Before inserting the linked list is: \n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to insert at the end of the node: ");
    scanf("%d",&data);
    start=insert_at_the_end(start,data);
    printf("After insertinf the node the final linked list is : \n");
    display(start);
}