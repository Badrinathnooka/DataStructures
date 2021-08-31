#include<stdio.h>
#include<stdlib.h>
//B172085
//This Program is of Max Heap
struct node{
	struct node *left;
	int ele;
	struct node *right;
};
struct node *head = NULL;
struct que{
	struct node *a[20];
	int f;
	int r;
};
void enqueu(struct que *q,struct node *el){
	q->r++;
	q->a[q->r]=el;
//	(q)->a[++(q)->r]=el;
	
}
int isempty(struct que *q)
{
	if(q->f<q->r)
		return 0;
	else 
		return 1;
}
struct node * dequeu(struct que *q)
{
	if(q->f==q->r)
		return NULL;
	else
	{
		q->f++;
		//printf("%d",q->a[q->f]);
		return q->a[q->f];
	}
}
void print(){
			struct node *temp1;
			struct que *q;
			q=(struct que *)malloc(sizeof(struct que));
			q->r=-1;
			q->f=-1;
			if(head==NULL){
				printf("s");
			}
			else{
				enqueu(q,head);
			}
			while(!isempty(q))
			{
			//	printf("YEs\n");
				temp1 = dequeu(q);
				printf("  %d  ",temp1->ele);
				if(temp1->left!=NULL)
				{
					enqueu(q,temp1->left);
				}
				if(temp1->right!=NULL){
					enqueu(q,temp1->right);
				}
			}	
}


void Tree(int m){
		if(head==NULL){
			head =(struct node*)malloc(sizeof(struct node));
			head->ele=m;
			head->left=NULL;
			head->right=NULL;
		}
		else{
			struct node *temp,*temp1;
			temp = (struct node*)malloc(sizeof(struct node));
			temp->ele=m;
			temp->left=NULL;
			temp->right=NULL;
			struct que *q;
			q=(struct que *)malloc(sizeof(struct que));
			q->r=-1;
			q->f=-1;
			enqueu(q,head);
			while(1)
			{
			
				temp1 = dequeu(q);
				if(temp1->left!=NULL)
				{
					enqueu(q,temp1->left);
				}
				else{
					if(temp->ele<temp1->ele)
						temp1->left=temp;
					else{
						int p;
						p=temp->ele;
						temp->ele=temp1->ele;
						temp1->ele=p;
						temp1->left=temp;	
					}
					break;
				}
				if(temp1->right!=NULL){
					enqueu(q,temp1->right);
				}
				else{
					if(temp->ele<temp1->ele)
						temp1->right=temp;
					else{
						int p;
						p=temp->ele;
						temp->ele=temp1->ele;
						temp1->ele=p;
						temp1->right=temp;	
					}
					break;
				}
			}
		}
	//return head;
}
int main(){
	int i,j,n;
	//struct node *head=NULL;
	printf("Enter size: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("enter ele :");
		scanf("%d",&j);
		Tree(j);
	}
	print();
}
