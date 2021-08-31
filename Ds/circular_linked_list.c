#include<stdio.h>
#include<stdlib.h>
//B172085
//Program for Circular Linked List
//Program consists functions like Insertion , deletion and display .
struct node
{
   int data;
   struct node *next;
};
struct node* inserthead(struct node *head,struct node *temp);
struct node* inserttail(struct node *head,struct node *temp);
struct node* insertmiddle(struct node *head,struct node *temp,int n);
struct node* deletehead(struct node *head,struct node *temp);
struct node*deletetail(struct node *head,struct node *temp);
struct node* deletemiddle(struct node *head,struct node *temp,int n);
void main()
{
  struct node *head,*newnode,*temp;
int n,c,ch;
printf("enter the number of nodes:");
scanf("%d",&n);
head=NULL;
c=1;
while(c<=n)
{
newnode=(struct node *)malloc(sizeof(struct node));
printf("enter the data:\n");
scanf("%d",&newnode->data);
newnode->next=head;
if(head==NULL)
{
head=temp=newnode;
head->next=head;
}
else
{
temp->next=newnode;
temp=newnode;
}
c++;
}
temp=head;
while(temp->next!=head)
{
printf("%d-%p\n",temp->data,temp->next);
temp=temp->next;
}
printf("%d-%p\n",temp->data,temp->next);
printf("1.HEAD INSERTION\n2.TAIL INSERTION\n3.MIDDLE INSERTION\n4.HEAD DELETION\n5.TAIL DELETION\n6.MIDDLE DELETION\n");
while(1)
{
printf("enter your choice:");
scanf("%d",&ch);
switch(ch)
{
 case 1:
 {
   head=inserthead(head,temp);
    break;
 }
 case 2:
 {
   head=inserttail(head,temp);
   break;
 }
 case 3:
  {
    head=insertmiddle(head,temp,n);
    break;
  }
 case 4:
  {
   head=deletehead(head,temp);
   break;
  }
 case 5:
 {
    head=deletetail(head,temp);
    break;
  }
 case 6:
 {
    head=deletemiddle(head,temp,n);
    break;
 }
 default:
  {
    printf("invalid choice\n");
    break;
  }
}
}
}
struct node* inserthead(struct node *head,struct node *temp)
{
   if(head==NULL)
     {
        printf("the list is empty\n");
     }
 else
  {
     struct node *insertnode;
     insertnode=(struct node*)malloc(sizeof(struct node));
     printf("enter the element to be inserted at the head:");
     scanf("%d",&insertnode->data);
      temp=head;
     while(temp->next!=head)
         {
            temp=temp->next;
         }
      temp->next=insertnode;
     insertnode->next=head;
     head=insertnode;
     temp=head;
     while(temp->next!=head)
      {
        printf("%d-%p\n",temp->data,temp->next);
        temp=temp->next;
      }
   return head;
}
}
struct node* inserttail(struct node *head,struct node *temp)
{
   temp=head;
   while(temp->next!=head)
    {
      temp=temp->next;
    }
       struct node *tailnode;
       tailnode=(struct node*)malloc(sizeof(struct node));
       printf("enter the element to be inserted at the tail:");
       scanf("%d",&tailnode->data);
       tailnode->next=temp->next;
       temp->next=tailnode;
      temp=head;
       while(temp->next!=head)
      {
        printf("%d-%p\n",temp->data,temp->next);
        temp=temp->next;
      }
     return head;
}
struct node* insertmiddle(struct node *head,struct node *temp,int n)
{
    int i=1,pos;
    struct node *middlenode;
    middlenode=(struct node*)malloc(sizeof(struct node));
    printf("enter the position after which the element should be inserted:");
    scanf("%d",&pos);
    printf("enter the new element:");
    scanf("%d",&middlenode->data);
    if(pos>n)
     {
        printf("invalid position\n");
      }
    else
     {
         temp=head;
        while(i<pos)
          {
             temp=temp->next;
             i++;
          }
      middlenode->next=temp->next;
      temp->next=middlenode;
     }
   temp=head;
   while(temp->next!=head)
      {
        printf("%d-%p\n",temp->data,temp->next);
        temp=temp->next;
      }
    return head;
}
struct node* deletehead(struct node *head,struct node *temp)
{
    struct node *head1;
    head1=head;
    head=head->next;
    free(head1);
    temp=head;
       while(temp->next!=head)
      {
        printf("%d-%p\n",temp->data,temp->next);
        temp=temp->next;
      }
      return head;
}
struct node* deletetail(struct node *head,struct node *temp)
{
   struct node *temp1;
    temp=head;
    while(temp->next!=head)
    {
       temp1=temp;
       temp=temp->next;
    }
   temp1->next=temp->next;
  /* temp->next=NULL;
   free(temp);*/
   
     temp=head;
       while(temp->next!=head)
      {
        printf("%d-%p\n",temp->data,temp->next);
        temp=temp->next;
      }
     return head;
}
struct node* deletemiddle(struct node *head,struct node *temp,int n)
{ 
   int pos,i=1;
   temp=head;
  printf("enter the position of the element that should be deleted:");
  scanf("%d",&pos);
  if(pos>n)
   {
      printf("the list is empty\n");
   }
  else
   {
     struct node *delnode;
      while(i<pos-1)
       {     
          temp=temp->next; 
          delnode=temp->next;
          i++;
      }
    temp->next=temp->next->next;
    delnode->next=NULL;
    free(delnode);
    
   }
   temp=head;
       while(temp->next!=head)
      {
        printf("%d-%p\n",temp->data,temp->next);
        temp=temp->next;
      }
     return head;
}
