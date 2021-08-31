#include<stdio.h>
#include<stdlib.h>
//B172085 
//This Program for  Binary_search_Tree 
//This Program includes Searching,Sorting,Deletion and Display functions
//Display function is implemented by inorder Tree.
struct node{
	struct node *left;
	int ele;
	struct node *right;
};
struct node *head = NULL;
void display(struct node *t){
	if(t->left){
		display(t->left);
	}
	printf(" %d ",t->ele);
	if(t->right)
		display(t->right);
}

struct node *delet(struct node *head,int m){
	if(head == NULL)
		return head;
	else if(m<head->ele)
		head->left=delet(head->left,m);
	else if(m>head->ele)
		head->right=delet(head->right,m);
	else{
		if(head->left==NULL && head->right==NULL){
			free(head);
			head=NULL;
		}
		else if(head->left==NULL){
			struct node *temp = head;
			head=head->right;
			free(temp); 
		}
		else if(head->right == NULL){
			struct node *temp=head;
			head= head->left;
			free(temp);
		}
		else{
			struct node *temp;
			struct node *f,*d;
			f=head;
			int i=0;
			while(f){
				d=f;
				if(i==0)
					f=f->right;
				else{
					f=f->left;
				}
				i=i+1;
			}
			temp = d;
			head->ele=temp->ele;
			head->right=delet(head->right,temp->ele);
		}
	}
	return head;
	
}
void search(struct node *p,int a[],int m){
	int i=0,j,flag=0;
	printf("Enter ele to search :");
	scanf("%d",&j);
	while(p!=NULL){
		if(p->ele==j){
			printf("element is found");
			flag=1;
			break;
		}
		else if(p->ele>j){
			p=p->left;
		}
		else{
			p=p->right;
		}
	}
	if(flag==0){
		printf("Elemnt is not found");
	}
}

struct node *Tree(struct node *head,int a[],int m){
	int i,j,k;
	for(i=0;i<m;i++){
		struct node *nn,*p;
		nn=(struct node*)malloc(sizeof(struct node));
		nn->ele=a[i];
		nn->left=NULL;
		nn->right=NULL;
		p=head;
		if(head==NULL){
			head = nn;
		}
		else{
				struct node *cur;
				cur = head;
				while(cur){
					p=cur;
					if(cur->ele>nn->ele){
						cur=cur->left;
					}
					else{
						cur=cur->right;
					}
				}
				if(p->ele>nn->ele){
					p->left=nn;
				}
				else{
					p->right=nn;
				}
			}
		}
		return head;
}
int main(){
	int i,j,m,s,op;
	struct node *head = NULL;
	printf("Enter the size of array :");
	scanf("%d",&m);
	int a[m];
	for(i=0;i<m;i++){
		printf("Enter ele :");
		scanf("%d",&a[i]);
	}
	head=Tree(head,a,m);
	do{
	printf("Enter 1-delete, 2-search , 3-display , 4-break");
	scanf("%d",&op);
	switch(op){
		case 1 : {	printf("Enter ele to delete :");
					scanf("%d",&s);
					head = delet(head,s);	
					break;
				}
		case 2 :{ 
					struct node *p;
					p=head;
					search(p,a,m);
					break;
				}
		case 3 :{					
					struct node *p;
					p=head;
					display(p);
					break;
				}
		case 4 : break;
	}
	}
	while(op!=4);
	
}

