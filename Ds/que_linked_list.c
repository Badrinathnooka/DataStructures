#include<stdio.h>
#include<stdlib.h>
//B172085
//Program for queue using linked list
struct node
{
   int data;
   struct node *next;
};
  struct node *front=NULL;
  struct node *rear=NULL;
void enqueue(int ele)
{
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=ele;
  newnode->next=NULL;
  if(front==NULL && rear==NULL)
   {
      front=rear=newnode;
   }
 else
  {
     rear->next=newnode;
     rear=newnode;
  }
}
void dequeue()
{
  struct node *temp;
  if(front==NULL)
   {
     printf("queue is empty\n");
    }
  else
   {
     temp=front;
     front=front->next;
     printf("the dequeued element is:%d-%p\n",temp->data,temp->next);
     free(temp);
   }
}
void display()
{
   struct node *temp;
   if(front==NULL && rear==NULL)
   {
      printf("queue is empty\n");
   }
  else
  {
    temp=front;
   while(temp!=NULL)
   {
    printf("%d-%p\n",temp->data,temp->next);
    temp=temp->next;
    }
}
}
void main()
{
  int ch,ele;

printf("1.enqueue\n2.dequeue\n3.display\n");
while(1)
{
printf("enter your option:");
scanf("%d",&ch);
switch(ch)
{
  case 1:
   {
      printf("enter the element to be inserted:");
     scanf("%d",&ele);
     enqueue(ele);
     break;
   }
  case 2:
    {
       dequeue();
       break;
    }
  case 3:
   {
      display();
      break;
   }
}
}
}
