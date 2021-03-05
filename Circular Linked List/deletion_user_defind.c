#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

struct node *new_node(struct node **start, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = (*start);
    (*start) = ptr;
}
struct node *delete_node(struct node **start, int data)
{
    struct node *ptr;
    struct node *p = *start;
    if (p != NULL && p->data == data)
    {
        (*start) = p->next;
        free(p);
        return 0;
    }
    while (p != NULL && p->data != data)
    {
        ptr = p;
        p = p->next;
    }
    if (p == NULL)
        return 0;
    ptr->next = p->next;
    free(p);
}
void display(struct node *ptr)
{
    do
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
}
int main()
{
    int i, n = 0;
    int data;
    printf("Enter the number of the node: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter the node %d: ", i);
        scanf("%d", &data);
        new_node(&start, data);
    }
    printf("The initial linked list is:\n");
    display(start);

    printf("\n");
    printf("Enter the number of node which you want to delete: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter the node %d: ", i);
        scanf("%d", &data);
        delete_node(&start, data);
    }
    printf("After deleting the node the list is: \n");
    display(start);
}
