#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;

struct node *insertion(struct node *start, int n)
{
    struct node *ptr;
    struct node *p;
    int data, i;
    printf("Enter the number of node: ");
    scanf("%d", &n);
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
        start->prev = NULL;
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
                ptr->prev = p;
                p->next = ptr;
                p = p->next;
            }
        }
    }
    return start;
}
struct node *delete_beginning(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    start->prev = NULL;
    free(ptr);
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    return start;
}
struct node *delete_after(struct node *start, int data)
{
    struct node *ptr;
    struct node *p;
    ptr = start;
    while (ptr->data != data)
    {
        ptr = ptr->next;
    }
    p = ptr->next;
    ptr->next = p->next;
    p->next->prev = ptr;
    free(p);
    return start;
}
struct node *delete_before(struct node *start, int data)
{
    struct node *ptr;
    struct node *p;
    ptr = start;
    while (ptr->data != data)
    {
        ptr = ptr->next;
    }
    p = ptr->prev;
    if (p == start)
    {
        start = delete_beginning(start);
    }
    else
    {
        ptr->prev = p->prev;
        p->prev->next = ptr;
    }
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
        ptr->next->prev=ptr;
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
        while(ptr!=NULL)
        {
            start=delete_beginning(start);
        }
    }
    free(ptr);
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    struct node *node;
    if (start == NULL)
    {
        printf("EMPTY");
    }
    else
    {
        ptr = start;
        printf("Traversing in Forward Direction\n");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            node = ptr;
            ptr = ptr->next;
        }
    }
    printf("\n");
    if (start == NULL)
    {
        printf("EMPTY");
    }
    else
    {
        printf("Traversing in Backward Direction\n");
        while (node != NULL)
        {
            printf("%d ", node->data);
            node = node->prev;
        }
    }
    return start;
}
int main()
{
    int data, n;
    printf("Doubly Linked List\n");
    start = insertion(start, n);
    printf("The initial linked list\n");
    start = display(start);

    printf("\n\n");
    printf("Deletion of first node\n");
    start = delete_beginning(start);
    printf("After deletion of first node the new linked list is\n");
    start = display(start);

    printf("\n\n");
    printf("Deletion of last node\n");
    start = delete_end(start);
    printf("After deletion of last node the new linked list is\n");
    start = display(start);

    printf("\n\n");
    printf("Enter the node which you want to delete after the node: ");
    scanf("%d", &data);
    start = delete_after(start, data);
    printf("After deletion after the node the linked list is\n");
    start = display(start);

    printf("\n\n");
    printf("Enter the node which you want to delete before the node: ");
    scanf("%d", &data);
    start = delete_before(start, data);
    printf("After deletion before the node the linked list is\n");
    start = display(start);

    printf("\n\n");
    printf("Enter the node which you want to delete: ");
    scanf("%d",&data);
    start=delete_node(start,data);
    printf("After deletion the given node the linked list is\n");
    start=display(start);   

    printf("\n\n");
    printf("lets delete the whole linked list\n");
    start=delete_list(start);
    start=display(start);

    return 0;
}