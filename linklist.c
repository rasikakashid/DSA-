#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *start = NULL;
void create();
void display();
void insert_beg();
void insert_end();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();
void create() 
{
	struct node*temp,*ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    if (!temp) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (start == NULL) 
    {
        start = temp;
    } else 
    {
        struct node *ptr = start;
        while (ptr->next != NULL) 
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void display() 
{
    struct node *ptr = start;
    if (ptr == NULL) 
    {
        printf("List empty!\n");
        return;
    }
    while (ptr != NULL) 
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
void insert_beg() 
{
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    if (!temp) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = start;
    start = temp;
}
void insert_end() 
{
    create(); 
}
void insert_pos() 
{
    int pos, i;
    struct node*temp;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos < 1) 
    {
        printf("Invalid position\n");
        return;
    }
    temp = (struct node*)malloc(sizeof(struct node));
    if (!temp) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &temp->data);
    if (pos == 1) 
    {
        temp->next = start;
        start = temp;
        return;
    }
    struct node *ptr = start;
    for (i = 1; i < pos - 1 && ptr != NULL; i++) 
    {
        ptr = ptr->next;
    }
    if (ptr == NULL) 
    {
        printf("Position not found\n");
        free(temp);
    } else 
    {
        temp->next = ptr->next;
        ptr->next = temp;
    }
}
void delete_beg() 
{
    if (start == NULL) 
    {
        printf("List empty!\n");
        return;
    }
    struct node *temp = start;
    start = start->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}
void delete_end() 
{
    if (start == NULL) 
    {
        printf("List empty!\n");
        return;
    }
    if (start->next == NULL) 
    {
        printf("Deleted: %d\n", start->data);
        free(start);
        start = NULL;
        return;
    }
    struct node *ptr = start;
    while (ptr->next->next != NULL) 
    {
        ptr = ptr->next;
    }
    struct node *temp = ptr->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
    ptr->next = NULL;
}
void delete_pos() 
{
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos < 1) 
    {
        printf("Invalid position\n");
        return;
    }

    if (start == NULL) 
    {
        printf("List empty!\n");
        return;
    }
    if (pos == 1) 
    {
        struct node *temp = start;
        start = start->next;
        printf("Deleted: %d\n", temp->data);
        free(temp);
        return;
    }
    struct node *ptr = start;
    for (i = 1; i < pos - 1 && ptr != NULL; i++) 
    {
        ptr = ptr->next;
    }
    if (ptr == NULL || ptr->next == NULL) 
    {
        printf("Position not found\n");
    } else 
    {
        struct node *temp = ptr->next;
        ptr->next = temp->next;
        printf("Deleted: %d\n", temp->data);
        free(temp);
    }
}
int main() 
{
    int choice;
    while (1) 
    {
        printf("\n1.Create \n2.Display \n3.InsertBeg \n4.InsertEnd \n5.InsertPos");
        printf(" \n6.DeleteBeg \n7.DeleteEnd \n8.DeletePos \n9.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert_beg(); break;
            case 4: insert_end(); break;
            case 5: insert_pos(); break;
            case 6: delete_beg(); break;
            case 7: delete_end(); break;
            case 8: delete_pos(); break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
