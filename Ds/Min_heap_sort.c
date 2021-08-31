#include<stdio.h>
#include<stdlib.h>
//B172085
//This program is of Min Heap
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

void heap(int c){
			struct node *temp1,*p,*temp2;
			struct que *q;
			q=(struct que *)malloc(sizeof(struct que));
			q->r=-1;
			q->f=-1;
			int k=0,m=0;
			p=head;
			if(head==NULL){
				printf("s");
			}
			else{
				enqueu(q,head);
			}
			while(c!=k)
			{
				temp1 = dequeu(q);
				temp2=temp1;
				if(temp1->left!=NULL)
				{
					k=k+1;
					enqueu(q,temp1->left);
					temp2=temp1->left;
				}
			if(c!=k){	
				if(temp1->right!=NULL){
					k=k+1;
					enqueu(q,temp1->right);
					temp2=temp1->right;
				}}
			}

			m=temp2->ele;
			temp2->ele=p->ele;
			p->ele=m;
				
}

void sort(int c){
		struct node *p,*cur,*temp1;
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
				temp1 = dequeu(q);
				if(temp1->left!=NULL)
				{
					enqueu(q,temp1->left);
				}
				if(temp1->right!=NULL){
					enqueu(q,temp1->right);
				}
			}
			q->f=-1;
			int k=0,w=0;
	while(c!=w){
		p=dequeu(q);
		cur=p;
		if(p->left!=NULL){
			w=w+1;
			if(p->ele<p->left->ele){
				k=p->ele;
				p->ele=p->left->ele;
				p->left->ele=k;
			}
			enqueu(q,p->left);		
		}
		if(c!=w){
		if(p->right!=NULL){
			w=w+1;
			if(p->ele<p->right->ele){
				k=p->ele;
				p->ele=p->right->ele;
				p->right->ele=k;
			}
			enqueu(q,p->right);
		}
	}
	}
}

void Tree(){
	int i,j,n,m,c;
	printf("Enter size: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("enter ele :");
		scanf("%d",&m);
		c=0;
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
					c=c+1;
					enqueu(q,temp1->left);
				}
				else{
					c=c+1;
					temp1->left=temp;
					break;
				}
				if(temp1->right!=NULL){
					c=c+1;
					enqueu(q,temp1->right);
				}
				else{
					c=c+1;
					temp1->right=temp;
					break;
				}
			}
		}
	}
	while(c!=0){
		sort(c);
		heap(c);
		c=c-1;}
		print();
}
int main(){
	Tree();
}
