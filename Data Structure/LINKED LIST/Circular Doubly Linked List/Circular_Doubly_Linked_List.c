#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;

struct node *circular_doubly_linked_list(struct node *start, int n);
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

struct node *circular_doubly_linked_list(struct node *start, int n)
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
        start->next = start;
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
                ptr->next = start;
                ptr->prev = p;
                start->prev = ptr;
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
    struct node *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    p = start;
    while (p->next != start)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = start;
    ptr->prev = p;
    start->prev = ptr;
    start = ptr;
    return start;
}
struct node *insert_between_node(struct node *start, int data, int index)
{
    struct node *ptr;
    struct node *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    int i = 1;
    p = start;
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
        p=p->next;
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
    while (p->next != start)
    {
        p = p->next;
    }
    p->next=ptr;
    ptr->next=start;
    ptr->prev=p;
    start->prev=ptr;
    return start;
}
struct node *delete_beginning(struct node *start)
{
    struct node *ptr;
    struct node *p;
    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = start->next;
    p = start;
    start=start->next;
    start->prev = ptr;
    free(p);
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr;
    struct node *p;
    p = start;
    while (p->next != start)
    {
        p = p->next;
    }
    p->prev->next = start;
    start->prev = p->prev;
    free(p);
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
    ptr->prev = p->prev;
    p->prev->next = ptr;
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
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
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
        while (ptr != NULL)
        {
            start = delete_beginning(start);
        }
    }
    free(start);
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
        do
        {
            printf("%d ", ptr->data);
            node = ptr;
            ptr = ptr->next;
        } while (ptr != start);
    }
    printf("\n");
    if (start == NULL)
    {
        printf("EMPTY");
    }
    else
    {
        printf("Traversing in Backward Direction\n");
        do
        {
            printf("%d ", node->data);
            node = node->prev;
        } while (node->next != start);
    }
    return start;
}
int main()
{
    int data, i, after, before, index, option, n;
    do
    {
        printf("\n\n____________________________MAIN_MENU_____________________________\n");
        printf("______________________Circular Doubly Linked List______________________\n\n");
        printf("1: Create Circular Doubly Linked List\n");
        printf("2: Display\n");
        printf("3: Insertion at first\n");
        printf("4: Insertion between the node\n");
        printf("5: Insertion after the node\n");
        printf("6: Insertion before the node\n");
        printf("7: insert at the end\n");
        printf("8: Deletion at beginning\n");
        printf("9: Deletion at end\n");
        printf("10: Deletion after the node\n");
        printf("11: Deletion before the node\n");
        printf("12: Deletion of the given node\n");
        printf("13: Deletion of Whole linked list\n");
        printf("\n\nEnter your choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = circular_doubly_linked_list(start, n);
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
            printf("Enter the node which you want to between the node: ");
            scanf("%d", &data);
            printf("INDEX: ");
            scanf("%d", &index);
            start = insert_between_node(start, data, index);
            break;
        case 5:
            printf("Enter the node which you want to insert after the node: ");
            scanf("%d",&data);
            printf("AFTER: ");
            scanf("%d",&after);
            insert_after_node(&start,data,after);
            break;
        case 6:
            printf("Enter the node which you want to insert before the node: ");
            scanf("%d",&data);
            printf("BEFORE: ");
            scanf("%d",&before);
            insert_before_node(&start,data,before);
            break;
        case 7:
            printf("Enter the node which you want to insert at the end: ");
            scanf("%d",&data);
            start=insert_at_end(start,data);
            break;
        case 8:
            start=delete_beginning(start);
            break;
        case 9:
            start=delete_end(start);
            break;
        case 10:
            printf("Enter the node which you want to delete after the node: ");
            scanf("%d",&data);
            start=delete_after(start,data);
            break;
        case 11:
            printf("Enter the node which you want to delete before the node: ");
            scanf("%d",&data);
            start=delete_before(start,data);
            break;
        case 12:
            printf("Enter the node which you want to delete from the list: ");
            scanf("%d",&data);
            start=delete_node(start,data);
            break;
        case 13:
            start=delete_list(start);
            break;
        case 14:
        default:
            break;
        }
    } while (option != 14);
    return 0;
}