#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *delete_beginning(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = start->next;
    free(start);
    start = ptr->next;
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr;
    struct node *p;
    p = start;
    while (p->next != start)
    {
        ptr = p;
        p = p->next;
    }
    p->next = ptr->next;
    ptr->next = start;
    free(p);
    return start;
}
struct node *delete_after(struct node *start, int data)
{
    struct node *ptr;
    struct node *p;
    p = start;
    ptr = p;
    while (ptr->data != data)
    {
        ptr = p;
        p = p->next;
    }
    ptr->next = p->next;
    free(p);
    return start;
}
struct node *delete_node(struct node *start, int data)
{
    struct node *ptr;
    struct node *p;
    p = start;
    if (p->data == data)
    {
        start = delete_end(start);
        return start;
    }
    else
    {
        while (p->data != data)
        {
            ptr = p;
            p = p->next;
        }
        ptr->next = p->next;
        p->next = start;
        free(p);
        return start;
    }
}
struct node *delete_list(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if (start != NULL)
    {
        while (ptr->next != start)
        {
            start = delete_end(start);
            free(start);
        }
    }
    free(start);
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
}
struct node *create_circular_linked_list(struct node *start, int data)
{
    struct node *ptr;
    struct node *p;
    int i, n;
    printf("Enter the number of node: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter the node %d: ", i);
        scanf("%d", &data);
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = data;
        if (start == NULL)
        {
            ptr->next = ptr;
            start = ptr;
        }
        else
        {
            p = start;
            while (p->next != start)
            {
                p = p->next;
            }
            p->next = ptr;
            ptr->next = start;
        }
    }
    return start;
}
int main()
{
    int data;
    printf("Create the circular linked list\n");
    start = create_circular_linked_list(start, data);
    printf("The initial linked list is\n");
    start = display(start);

    printf("\n");
    printf("Deletion at beginning\n");
    start = delete_beginning(start);
    printf("After deletion the beginning of the list the new linked list is\n");
    start = display(start);

    printf("\n");
    printf("Deletion at end\n");
    start = delete_end(start);
    printf("After deletion the end of the list the new linked list is\n");
    start = display(start);

    printf("\n");
    printf("Enter the node which you want to delete after the node: ");
    scanf("%d", &data);
    start = delete_after(start, data);
    printf("After deletion the node after the node\n");
    start = display(start);

    printf("\n");
    printf("Enter the node which you want to delete: ");
    scanf("%d", &data);
    start = delete_node(start, data);
    printf("After delete the node the new linked list is\n");
    start = display(start);

    printf("\n");
    printf("Now Going to delete the whole list\n");
    start = delete_list(start);

    return 0;
}