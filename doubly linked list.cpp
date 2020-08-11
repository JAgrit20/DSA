/*Write a program to implement doubly linked list with following operations:
1.	Insert at Beginning
2.	Insert at End
3.	Delete from Beginning
4.	Delete from End
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node * prev;
    struct node * next;
    int data;

};
struct node *start=NULL, * ptr, *temp;
void insert_at_begin()
{
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&temp->data);
    if(start==NULL)
    {
        temp->next=NULL;
        temp->prev=NULL;
        start=temp;

    }
    else
    {
        temp->next=start;
        start->prev=temp;
        temp->prev=NULL;
        start=temp;
    }
    printf("Element inserted\n");
}
void insert_at_end()
{
    if(start==NULL)
    {
        insert_at_begin();
    }
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&temp->data);
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
        temp->next=NULL;
        printf("element inserted\n");
    }
}
void delete_at_begin()
{
    if(start==NULL)
        printf("no number is there\n");

    else if(start->next==NULL)
    {
        start=start->next;
        printf("Element deleted\n");
    }

    else
    {
        ptr=start;
        start=start->next;
        start->prev=NULL;
        free(ptr);
        printf("Element deleted\n");
    }
}
void delete_at_end()
{
    if(start==NULL)
        printf("no number is there\n");
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        if(ptr==start)
        {
            delete_at_begin();
        }
        else
        {
            ptr->prev->next=NULL;
            free(ptr);
            printf("Element deleted\n");
        }
    }
}
void traverse()
{
    if(start==NULL)
    {
        printf("No element to traverse\n");
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
void main()
{
    int ch=1;
    do
    {
        printf("Enter 1 for insert at begin\n");
        printf("Enter 2 for insert at end \n");
        printf("Enter 3 for delete at begin \n");
        printf("Enter 4 for delete at end \n");
        printf("Enter 5 for traversing the list\n");
        printf("Enter 6 for exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                {
                    insert_at_begin();
                    break;
                }
            case 2:
                {
                    insert_at_end();
                    break;
                }
            case 3:
                {
                    delete_at_begin();
                    break;

                }
            case 4:
               {
                   delete_at_end();
                   break;
               }
            case 5:
                {
                    traverse();
                    break;

                }
            case 6:
                {
                    exit(0);
                }

        }
    }while(ch!=6);
}