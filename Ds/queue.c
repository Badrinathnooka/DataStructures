#include <stdio.h>
//B172085
//Program for queue using structure and functions
struct queue
{
int que[20];
int f,r;
}q;
struct queue enqueue(int n)
{
   int x;
   if(q.r==n-1)
    {
      printf("queue is full\n");
    }
   else 
{
 printf("enter the element to be inserted:");
   scanf("%d",&x);
   q.r++;
   q.que[q.r]=x;
}
return q;
}
struct queue dequeue()
{
   if(q.f==q.r)
   {
    printf("queue is empty\n");
   }
   else 
   {
     q.f++;
     printf("element deleted is %d ",q.que[q.f]);
   }
  return q;
}
struct queue display()
{
 int i;
  if(q.f==q.r)
   {
    printf("queue is empty\n");
    }
   else
   {
      printf("queue is:\n");
      for(i=0;i<=q.r;i++)
      {
        printf("%d\n",q.que[i]);
       }
}
return q;
}
     
void main()
{
  int ele,n;
  printf("enter n value:");
  scanf("%d",&n);
  q.f=q.r=-1;
  do
  {
      printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
      printf("enter your option:");
      scanf("%d",&ele);
        switch(ele)
        {
          case 1:
          enqueue(n);
          break;
          case 2:
          dequeue();
          break;
          case 3:
          display();
          break;
          case 4:
          printf("thank you\n");
          break;
          default:
          printf("invalid choice\n");
          break;
       }
}
while(ele!=4);
}

