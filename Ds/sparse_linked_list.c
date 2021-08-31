#include<stdio.h>
#include<stdlib.h>
//B172085
//This program is about Sparse Linked List
struct node{
	int row;
	int col;
	int ele;
	struct node *next;
};
struct node *head = NULL;
void display(){
	struct node *p;
	p=head;
	while(p!=NULL){
		printf("col = %d",p->col);
		printf("row = %d",p->row);
		printf("ele = %d",p->ele);
		printf("\n");
		p=p->next;
	}
}
int main(){
	int n,m,i,j,p=0;
	printf("Enter rows :");
	scanf("%d",&n);
	printf("Enter columns:");
	scanf("%d",&m);
	int a[n][m],r[100],c[100],v[100];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("Enter ele :");
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i][j]!=0){
				struct node *nn;
				nn=(struct node*)malloc(sizeof(struct node));
				nn->col=j;
				nn->row=i;
				nn->ele=a[i][j];
				nn->next=NULL;
				if(head == NULL){
					head = nn;
				}
				else{
					struct node *p;
					p= head;
					while(p->next!=NULL){
						p=p->next;
					}
					p->next=nn;
				}
			}
		}
	}
	display();
}
