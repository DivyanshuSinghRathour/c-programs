#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
void insertion(int n)
{
    int i, data;
    struct node *ptr, *p;
    start = (struct node *)malloc(sizeof(struct node));
    if (start == NULL)
    {
        printf("Enable to insert the elements\n");
    }
    else
    {
        printf("Enter the node 1: ");
        scanf("%d", &data);
        start->data = data;
        start->next = NULL;
        p = start;
        for (i = 2; i <= n; i++)
        {
            ptr = (struct node *)malloc(sizeof(struct node));
            if (ptr == NULL)
            {
                printf("Enable to insert the elements\n");
            }
            else
            {
                printf("Enter the node %d: ", i);
                scanf("%d", &data);
                ptr->data = data;
                ptr->next = NULL;
                p->next = ptr;
                p = p->next;
            }
        }
    }
}
struct node *insert_at_first(struct node *start, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = start;
    start = ptr;
    return start;
}
struct node *insert_between_node(struct node *start, int data, int index)
{
    struct node *ptr;
    struct node *p = start;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    int i = 1;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return start;
}
struct node *insert_after_node(struct node *start, struct node *prevnode, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    return start;
}
struct node *insert_after_node_part_two(struct node *start, int data, int after)
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
struct node *insert_before_node(struct node **start, int data, int before)
{
    struct node *ptr;
    struct node *p = (*start);
    ptr = (struct node *)malloc(sizeof(struct node));
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
struct node *insert_at_end(struct node *start, int data)
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
void delete_node(struct node ** start,int data)
{
    struct node * ptr;
    struct node * p = (*start);
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
void display()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("Empty");
    }
    else
    {
        ptr = start;
        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != NULL);
    }
}
int main()
{
    int data, i, n = 0, after, before, index;
    printf("Enter the number of node: ");
    scanf("%d", &n);
    insertion(n);
    printf("The initial linked list is: \n");
    display();

    printf("\n");
    printf("Enter the node which you want to insert in the first: ");
    scanf("%d", &data);
    start = insert_at_first(start, data);
    printf("After insertion the new linked list is: \n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to insert between the node:  ");
    scanf("%d", &data);
    printf("INDEX: ");
    scanf("%d",&index);
    start = insert_between_node(start, data, index);
    printf("After insertion the new linked list is: \n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to insert after the node: ");
    scanf("%d", &data);
    printf("AFTER: ");
    scanf("%d", &after);
    insert_after_node_part_two(start, data, after);
    printf("After insertion the new linked list is: \n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to insert before the node: ");
    scanf("%d", &data);
    printf("BEFORE: ");
    scanf("%d", &before);
    insert_before_node(&start, data, before);
    printf("After insertion the linked list is: \n");
    display(start);

    printf("\n");
    printf("Enter the node which you want to insert in the end of the node: ");
    scanf("%d", &data);
    insert_at_end(start, data);
    printf("After insertion the linked list is: \n");
    display(start);

    printf("\n");
    printf("Enter the number of node which you want to delete from the linked list: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the node %d: ",i);
        scanf("%d",&data);
        delete_node(&start,data);
    }
    printf("The full n final linked list is: \n");
    display(start);
}