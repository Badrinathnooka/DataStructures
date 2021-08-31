#include<stdio.h>
#include<stdlib.h>
//B172085
//This program is implemented to print elements of a tree in a Inorder way
//Inorder Tree
struct node{
	struct node *left;
	int ele;
	struct node *right;
};
struct node *head = NULL;

void inorder(struct node *t){
	if(t->left){
		inorder(t->left);
	}
	printf("%d \n",t->ele);
	if(t->right)
		inorder(t->right);
}
void Tree(int a[],int m){
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
		struct node *l;
		l=head;
		inorder(l);
}
int main(){
	int i,j,m;
	printf("Enter the size of array :");
	scanf("%d",&m);
	int a[m];
	for(i=0;i<m;i++){
		printf("Enter ele :");
		scanf("%d",&a[i]);
	}
	Tree(a,m);
}
