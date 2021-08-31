#include<stdio.h>
#include<stdlib.h>
//B172085
//This Program shows the preorder and postorder Tree traversal.
//Displays the elements of tree in the post and pre order.
struct node{
	struct node *left;
	int ele;
	struct node *right;
};
struct node *head = NULL;

void preorder(struct node *t){
	printf("%d \n",t->ele);
	if(t->left)
		preorder(t->left);
	if(t->right)
		preorder(t->right);
}
void postorder(struct node *t){
	if(t->left)
		postorder(t->left);
	if(t->right)
		postorder(t->right);
	printf("%d \n",t->ele);	
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
		printf("preorder :\n");
		preorder(l);
		printf("postorder :\n");
		postorder(l);
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
