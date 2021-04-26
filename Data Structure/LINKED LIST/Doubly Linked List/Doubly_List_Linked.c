#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;
struct node *create_Doubly_linked_list(struct node *start, int n);
struct node *display(struct node *start);
struct node *insert_at_first(struct node *start, int data);
struct node *insert_between_node(struct node *start, int data, int index);
struct node *insert_after_node(struct node **start, int data, int after);
struct node *insert_before_node(struct node **start, int data, int before);
struct node *insert_at_end(struct node *start, int data);
struct node *delete_beginning(struct node *start);
struct node *delete_end(struct node *start);
struct node *delete_after(struct node *start, int data);
struct node *delete_before(struct node *start, int data);
struct node *delete_node(struct node *start, int data);
struct node *delete_list(struct node *start);

struct node *create_Doubly_linked_list(struct node *start, int n)
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
struct node *insert_at_first(struct node *start, int data)
{
    struct node *ptr;
    ptr = start;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = start;
    ptr->prev = NULL;
    if (start != NULL)
    {
        start->prev = ptr;
    }
    start = ptr;
    return start;
}
struct node *insert_between_node(struct node *start, int data, int index)
{
    struct node *ptr;
    struct node *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    p = start;
    ptr->data = data;
    int i = 1;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->prev = p;
    if (p != NULL)
    {
        p->next->prev = ptr;
    }
    p->next = ptr;
    return start;
}
struct node *insert_after_node(struct node **start, int data, int after)
{
    struct node *ptr;
    struct node *p;
    p = (*start);
    while (p != NULL)
    {
        if (p->data == after)
        {
            ptr = (struct node *)malloc(sizeof(struct node));
            ptr->data = data;
            ptr->next = p->next;
            ptr->prev = p;
            if (p != NULL)
            {
                p->next->prev = ptr;
            }
            p->next = ptr;
            return 0;
        }
        p = p->next;
    }
}
struct node *insert_before_node(struct node **start, int data, int before)
{
    struct node *ptr;
    struct node *p;
    p = (*start);
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
            ptr->prev = p;
            if (p != NULL)
            {
                p->next->prev = ptr;
            }
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
    ptr->prev = p;
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
struct node *delete_node(struct node *start, int data)
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
        ptr->next->prev = ptr;
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
        while (ptr!=NULL)
        {
            start = delete_beginning(start);
        }
    }
    free(ptr);
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    struct node *node;
    ptr = start;
    if (start == NULL)
    {
        printf("EMPTY");
    }
    else
    {
        ptr = start;
        printf("Travsersing in Forward Direction\n");
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
    int data, i, n, after, before, index, option;
    do
    {
        printf("\n\n___________MAIN MENU__________________\n");
        printf("___________Doubly Linked List_________\n");
        printf("1: Create Doubly Linked List\n");
        printf("2: Display\n");
        printf("3: insertion at first\n");
        printf("4: insertion between the node\n");
        printf("5: insertion after the node\n");
        printf("6: insertion before the node\n");
        printf("7: insert at the end of the node\n");
        printf("8: deletion at beginning\n");
        printf("9: deletion at end\n");
        printf("10: deletion after the node\n");
        printf("11: deletion before the node\n");
        printf("12: deletion of the given node\n");
        printf("13: deletion of whole linked list\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n");
            start = create_Doubly_linked_list(start, n);
            break;
        case 2:
            printf("\n");
            start = display(start);
            break;
        case 3:
            printf("\nEnter the node which you want to insert at first: ");
            scanf("%d", &data);
            start = insert_at_first(start, data);
            break;
        case 4:
            printf("\nEnter the node which you want to insert between the node: ");
            scanf("%d", &data);
            printf("INDEX: ");
            scanf("%d", &index);
            start = insert_between_node(start, data, index);
            break;
        case 5:
            printf("\nEnter the node which you want to insert after the node:  ");
            scanf("%d", &data);
            printf("AFTER: ");
            scanf("%d", &after);
            insert_after_node(&start, data, after);
            break;
        case 6:
            printf("\nEnter the node which you want to insert before the node:");
            scanf("%d", &data);
            printf("BEFORE: ");
            scanf("%d", &before);
            insert_before_node(&start, data, before);
            break;
        case 7:
            printf("\nEnter the node which you want to insert at the end of the node:  ");
            scanf("%d", &data);
            start = insert_at_end(start, data);
            break;
        case 8:
            printf("\n");
            start = delete_beginning(start);
            break;
        case 9:
            printf("\n");
            start = delete_end(start);
            break;
        case 10:
            printf("\nEnter the node which you want to delete after the node: ");
            scanf("%d", &data);
            start = delete_after(start, data);
            break;
        case 11:
            printf("\nEnter the node which you want to delete before the node:  ");
            scanf("%d", &data);
            start = delete_before(start, data);
            break;
        case 12:
            printf("\nEnter the node which you want to delete: ");
            scanf("%d", &data);
            start = delete_node(start, data);
            break;
        case 13:
            start = delete_list(start);
            break;
        case 14:
        default:
            exit;
        }
    } while (option != 14);
    return 0;
}