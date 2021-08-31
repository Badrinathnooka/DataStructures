#include<stdio.h>
#include<stdlib.h>
//B172085
//This Program is of Binary Tree and Tree Traversal 
struct node{
	struct node *left;
	int ele;
	struct node *right;
};struct node *head = NULL;
struct que{
	struct node *a[20];
	int f;
	int r;
};
void enque(struct que *q,struct node *ele)
{
	q->f++;
	q->a[q->f]=ele;

}
struct node *deque(struct que *q)
{
	q->r++;
	return q->a[q->r];
}
int isempty(struct que *q)
{
	if(q->f<q->r)
		return 0;
	else 
		return 1;
}
void display(struct node *t){
	if(t->left){
		display(t->left);
	}
	printf(" %d ",t->ele); 
//	printf(" %d ",t->left);
//	printf(" %d \n",t->right);
	if(t->right)
		display(t->right);
}
struct node *Tree(int ele)
{
	struct node *nn;
	
	nn = (struct node *)malloc(sizeof(struct node));
	//nn=(struct node*)malloc(sizeof(struct node));
	
	nn->ele=ele;
	nn->left=NULL;
	nn->right=NULL;
	struct que *q;
	q=(struct que *)malloc(sizeof(struct que));
	q->r=-1;
	q->f=-1;
	
	if(head == NULL)
	{
		head = nn;
	}
	else
	{
		struct node *temp,*p;
		//struct que *q;
		temp = head;
		enque(q,head);
		
		while(1)
		{
			p = deque(q);
			
			if(p->left!=NULL)
			{
				enque(q,p->left);
			}
			else
			{
				p->left=nn;
				
				break;
			}
			if(p->right!=NULL)
			{
				enque(q,p->right);
			}
			else
			{
				p->right=nn;
				
				break;
			}
		}
		
	}
}


int main()
{
	int i,j,k;
	printf("Enter size");
	scanf("%d",&j);
	for(i=0;i<j;i++)
	{
		printf("Enter element :");
		scanf("%d",&k);

		Tree(k);
	}
	printf("elements:");
	struct node *t;
	t=head;
	display(t);
}
