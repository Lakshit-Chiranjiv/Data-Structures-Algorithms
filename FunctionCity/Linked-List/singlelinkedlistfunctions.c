//single linked list 
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;

//creating single linked list
void create()
{
int choice=1;
//head=NULL;
struct node *newnode,*temp;
while(choice)
{
 newnode = (struct node *)malloc(sizeof(struct node));
 printf("enter the data part of newnode : ");
 scanf("%d",&newnode->data);
 newnode->next = NULL;
 if(head == NULL)
 {
 	head = newnode;
 	temp=head;
 }
 else
 {
    temp->next=newnode;
    temp=temp->next;
 }
 printf("to enter another node press 1 \nto stop press 0\n");
 scanf("%d",&choice);
}
}

//to display a pre-made single linked list
void display()
{
  struct node *temp;
  temp=head;
  printf("YOUR LIST : ");
  while(temp!=NULL)
  {
  	printf("%d\t",temp->data);
  	temp=temp->next;
  }
}

//to calculate length of single linked list
void length()
{
	struct node *temp;
	temp=head;
	int c=0;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	printf("\nLength of the list : %d\n",c);
}

//insert a node at beginning
void insatbeg()
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nenter the data part of newnode to insert : ");
	scanf("%d",&newnode->data);
	newnode->next = head;
	head = newnode ;
}

//to insert a node at end
void insatend()
{
	struct node *newnode,*temp;
	temp=head;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nenter the data part of newnode to insert : ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	while(temp->next != NULL)
	{
		temp=temp->next;
	}
	temp->next = newnode;
}

//insert node at any given position
void insatpos()
{
	struct node *newnode,*temp;
	temp=head;
	int pos,i=1;
	printf("\nenter the position at which you want to insert : ");
	scanf("%d",&pos);
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nenter the data part of newnode to insert : ");
	scanf("%d",&newnode->data);
	if(pos==1)
	{
       newnode->next=head;
       head=newnode;
	}
	else
	{
	while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}
	newnode->next = temp->next;
	temp->next = newnode;
    }
}

//to delete a node from beginning
 void delfrombeg()
 {
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);   
 }

 //to delete a node from end
 void delfromend()
 {
 	struct node *temp,*last;
 	temp=last=head;
 	temp=temp->next;
    while(temp->next!=NULL)
    {
    	temp=temp->next;
    	last=last->next;
    }
    last->next = NULL;
    free(temp);
 }

 //to delete a node from a given position
 void delfrompos()
 {
 	struct node *temp,*todel;
	temp=todel=head;
	todel=todel->next;
	int pos,i=1;
	printf("\nenter the position at which you want to delete : ");
	scanf("%d",&pos);
	if(pos==1)
	{
		head=head->next;
		free(temp);
	}
	else
	{
	while(i<pos-1)
	{
		temp=temp->next;
		todel=todel->next;
		i++;
	}
	temp->next=todel->next;
	free(todel);
    }
 }


//to reverse the single linked list
void reverse()
{
	struct node *temp,*backwd,*forwd;
	backwd=head;
    temp=backwd->next;
    forwd=temp->next;
    head->next=NULL;
    while(forwd!=NULL)
    {
    	temp->next=backwd;
    	backwd=temp;
    	temp=forwd;
    	forwd=forwd->next;
    }
    temp->next=backwd;
    head=temp;
}
