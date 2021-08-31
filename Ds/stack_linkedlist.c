#include<stdio.h>
#include<stdlib.h>
//B172085
//Program for stack using linked list
struct node
{
  int data;
  struct node *next;
};
struct node *top=NULL;
void push(int ele);
void pop();
void display();
void peek();
void main()
{
int op,ele;
printf("1.push\n2.pop\n3.display\n4.exit\n");
do
{
printf("enter your choice:");
scanf("%d",&op);
switch(op)
{
   case 1:
    {
      printf("enter the element that should be inserted:");
      scanf("%d",&ele);
      push(ele);
      break;
   }
   case 2:
    {
       pop();
      break;
    }
   case 3:
    {
       display();
       break;
    }
  case 4:
   {
      peek();
      break;
   }
    default:
      {
         printf("invalid choice\n");
     }
}
}while(op!=4);
}
void push(int ele)
{
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=ele;
  newnode->next=top;
  top=newnode;
}
void pop()
{
  int item,add;
  struct node *temp;
if(top==NULL)
{
  printf("stack is empty\n");
}
else
{
  item=top->data;
  add=top->next;
  temp=top;
  top=temp->next;
  temp->next=NULL;
 printf("poped item is:%d-%p\n",item,add);
  free(temp);
}
}
void display()
{
  struct node *temp;
  temp=top;
 if(top==NULL)
 {
    printf("stack is empty\n");
 }
else
{
  while(temp!=NULL)
   {
      printf("%d-%p\n",temp->data,temp->next);
      temp=temp->next;
   }
}
}
void peek()
{
   printf("the top most element of the stack is:");
   printf("%d-%p\n",top->data,top->next);
}
