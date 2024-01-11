#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node *start=NULL;
void createlist(int data)
{
    struct node *newnode;
    if(start==NULL)
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    start=newnode;
    newnode->data=data;
    newnode->next=NULL;
    }
}
void insertBack(int data)
{
    struct node*newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
    newnode->data=data;
}
void insertFront(int data)
{
    struct node*newnode,temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(start==NULL)
    {
        printf("there is no list\n");
    }
    else
    {
        newnode->next=start;
        start=newnode;
        newnode->data=data;
    }
}
void insert_at_given_position(int position,int data)
{
    struct node*newnode,*temp,*savedlocation;
    newnode=(struct node*)malloc(sizeof(struct node));
    temp=start;
    int count=1;
    while(count!=position-1)
    {
        temp=temp->next;
                count++;
    }
    savedlocation=temp->next;
    temp->next=newnode;
    newnode->next=savedlocation;
    newnode->data=data;

}
void display()
{
    struct node* temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d , ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void deleteFront()
{
    struct node *savedlocation;
    savedlocation=start;
    start=start->next;
    free(savedlocation);
}
void deleteEnd()
{
    struct node *temp;
    temp=start;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;//second last node samma pugyo.
    }
    free(temp->next);
    temp->next=NULL;
}
void delete_at_given_position(int position)
{
    struct node *temp=start,*savedlocation;
    int count=1;
    while(count!=position-1)
    {
        temp=temp->next;
        count++;
    }
    savedlocation=temp->next;
    temp->next=temp->next->next;
    free(savedlocation);
}
int main()
{
    createlist(10);
    display();
    insertBack(20);
    display();
    insertFront(30);
    insertFront(40);
     insertFront(50);
    insertFront(60);
    display();
    insert_at_given_position(4,5);
    display();
    deleteFront();
    display();
    deleteEnd();
    display();
    delete_at_given_position(3);
    display();
    return 0;
}




