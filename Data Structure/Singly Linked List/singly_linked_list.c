#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create_singly_linked_list(struct node *start, int data);
struct node *insert_at_first(struct node *start, int data);
struct node *insert_at_end(struct node *start, int data);
struct node *insert_after(struct node *start, int data, int after);
struct node *insert_before(struct node *start, int data, int before);
struct node *delete_beginning(struct node *start);
struct node *delete_end(struct node *start);
struct node *delete_after(struct node *start, int after_del);
struct node *delete_node(struct node *star, int data);
struct node *delete_list(struct node *star);
struct node *display(struct node *start);

struct node *create_singly_linked_list(struct node *start, int data)
{
    struct node *ptr;
    struct node *p;
    int i, n;
    printf("Enter the number of the node  ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter the node %d: ", i);
        scanf("%d", &data);
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = data;
        if (start == NULL)
        {
            ptr->next = NULL;
            start = ptr;
        }
        else
        {
            p = start;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = ptr;
            ptr->next = NULL;
        }
    }
    return start;
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
struct node *insert_at_end(struct node *start, int data)
{
    struct node *ptr;
    struct node *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    p = start;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return start;
}
struct node *insert_after(struct node *start, int data, int after)
{
    struct node *ptr;
    struct node *p;
    struct node *preptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    p = start;
    preptr = p;
    while (preptr->data != after)
    {
        preptr = p;
        p = p->next;
    }
    preptr->next = ptr;
    ptr->next = p;
    return start;
}
struct node *insert_before(struct node *start, int data, int before)
{
    struct node *ptr;
    struct node *p;
    struct node *preptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    p = start;
    while (p->data != before)
    {
        preptr = p;
        p = p->next;
    }
    preptr->next = ptr;
    ptr->next = p;
    return start;
}
struct node *delete_beginning(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr;
    struct node *p;
    p = start;
    while (p->next != NULL)
    {
        ptr = p;
        p = p->next;
    }
    ptr->next = p->next;
    free(p);
    return start;
}
struct node *delete_after(struct node *start, int after_del)
{
    struct node *ptr;
    struct node *p;
    p = start;
    ptr = p;
    while (ptr->data != after_del)
    {
        ptr = p;
        p = p->next;
    }
    ptr->next = p->next;
    free(p);
    return start;
}
struct node *delete_node(struct node *star, int data)
{
    struct node *ptr;
    struct node *p;
    p = start;
    if (p->data == data)
    {
        start = delete_beginning(start);
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
        free(p);
        return start;
    }
}
struct node *delete_list(struct node *star)
{
    struct node *ptr;
    ptr = start;
    if (start != NULL)
    {
        while (ptr != NULL)
        {
            start = delete_beginning(start);
        }
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return start;
}
int main(int argc,char *argv[])
{
    int data, after, after_del, before;
    int option;
    do
    {
        printf("\n-----------Main Menu------------\n");
        printf("Singly linked list\n");
        printf("1: create singly linked list\n");
        printf("2: display the singly linked list\n");
        printf("3: insert at first\n");
        printf("4: insert after node\n");
        printf("5: insert before node\n");
        printf("6: insert at end\n");
        printf("7: delete beginning\n");
        printf("8: delete ending\n");
        printf("9: delte node after the node\n");
        printf("10: delete the given node\n");
        printf("11: delete whole list\n");
        printf("12: EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_singly_linked_list(start, data);
            printf("Linked list created\n");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            printf("Enter the node which you want to insert at first: ");
            scanf("%d", &data);
            start = insert_at_first(start, data);
            break;
        case 4:
            printf("Enter the node which you want to inset after the node: ");
            scanf("%d", &data);
            printf("AFTER: ");
            scanf("%d", &after);
            start = insert_after(start, data, after);
            display(start);
            break;
        case 5:
            printf("Enter the node which you want to insert before the node: ");
            scanf("%d", &data);
            printf("BEOFRE: ");
            scanf("%d", &before);
            start = insert_before(start, data, before);
            break;
        case 6:
            printf("Enter the node which you want to insert at the end: ");
            scanf("%d", &data);
            start = insert_at_end(start, data);
            break;
        case 7:
            start = delete_beginning(start);
            break;
        case 8:
            start = delete_end(start);
            break;
        case 9:
            printf("Enter the node which you want to delete after the node: ");
            scanf("%d", &after_del);
            start = delete_after(start, after_del);
            break;
        case 10:
            printf("Enter the node which you want to delete: ");
            scanf("%d", &data);
            start = delete_node(start, data);
            break;
        case 11:
            start = delete_list(start);
            break;
        }
    } while (option != 12);
    return 0;
}