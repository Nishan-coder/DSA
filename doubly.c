#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *previous;
};
struct node *start=NULL;
void createlist(int data)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(start==NULL)
    {
        start=newnode;
        newnode->data=data;
        newnode->next=NULL;
        newnode->previous=NULL;
    }
}
void insertEnd(int data)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->previous=temp;
    newnode->next=NULL;
    newnode->data=data;
}
void insertFront(int data)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    start->previous=newnode;
    newnode->next=start;
    newnode->previous=NULL;
    start=newnode;
    newnode->data=data;
}
void insert_at_any_position(int position,int data)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    int count=1;
    temp=start;
    while(count!=position-1)
    {
        temp=temp->next;
        count++;
    }
    newnode->next=temp->next;
    newnode->previous=temp;
    temp->next=newnode;
    newnode->data=data;
}
void deleteEnd()
{
    struct node *temp;
    temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->previous->next=NULL;
    free(temp);
}
void deleteFront()
{
    struct node *temp;
    temp=start;
start->next->previous=NULL;
start=start->next;
free(temp);
}
void delete_at_any_position(int position)
{
    struct node *temp,*savedlocation;
    int count=1;
    temp=start;
    while(count!=position-1)
    {
        temp=temp->next;
        count++;
    }
    savedlocation=temp->next;
    temp->next=temp->next->next;
   savedlocation->next->previous=temp;
    free(savedlocation);
}
void display()
{
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d ,",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    createlist(20);
    display();
    insertEnd(40);
    display();
    insertFront(50);
    display();
     insertFront(90);
    display();
     insertFront(70);
    display();
    insert_at_any_position(4,1500);
    display();
    deleteEnd();
    display();
    deleteFront();
    display();
    delete_at_any_position(3);
    display();
    return 0;
}
