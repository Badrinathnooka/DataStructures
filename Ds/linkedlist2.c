#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//B172085
//This Program is of Linkedlist concept it as functions like insert at position , deletion and display
struct node{
	int ele;
	struct node *next;
};
struct node *head = NULL;

void append(){
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("Enter a element");
	scanf("%d",&nn->ele);
	nn->next=NULL;
	if(head==NULL)
	{
		head = nn;
	}
	else
	{
		struct node *p;
		p=head;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=nn;
	}
}


void beggining(){
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("Enter element");
	scanf("%d",&nn->ele);
	struct node *p;
	p=head;
	head=nn;
	nn->next=p;
}

void position(){
	int pos,flag=0,c=0;
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("Enter the postion :\n ");
	scanf("%d",&pos);
	printf("ENter the element :\n ");
	scanf("%d",&nn->ele);
	struct node *p;
	p=head;
	printf("yes\n");
	while(p!=NULL){
		
		if(c==pos-1)
		{
				flag =1;
				nn->next=p->next;
				p->next=nn;
		}
		else
		{			p=p->next;
			
		}
		c=c+1;
	}
	if(flag==0){
		printf("position uavialabe");
	}
	else{
		printf("available");
	}
}
void delete1(){
	struct node *p;
	p=head;
	p=p->next;
	head = p;
}
void deletelast()
{
	struct node *p;
	p=head;
	while(p->next->next!=NULL)
	{
		p=p->next;
		printf("Yes\n");
		
	}
	p->next=NULL;
}

void deletepos(){
	struct node *p;
	int pos,c=0;
	printf("ENter positon to delete:");
	scanf("%d",&pos);
	p=head;
	while(p!=NULL){
		if(c==pos-1){
			p->next=p->next->next;
		}
		else{
			p=p->next;
		}
		c=c+1;
	}
}
void display(){
	struct node *p;
	p=head;
	while(p->next!=NULL){
		printf("%d",p->ele);
		p=p->next;
	}
	printf("%d",p->ele);
}

int main(){
	int op,k=1;
	while(k==1){
	
	printf("Enter 1.insert: \n    2.deletion  3.display :");
	scanf("%d",&op);
	switch(op){
		case 1: {
				int op1;
				printf("Enter 1.append , 2.beggining 3.postion");
				scanf("%d",&op1);
				switch(op1){
					case 1 : append();
								break;
					
					case 2 : beggining();
								break;
					
					case 3 : position();
								break;
				}
				break;
				}
			
		case 2 : {
				printf("Enter 1.delete 1st , 2.deletelast , 3.delete_postion");
				int op2;
				scanf("%d",&op2);
				switch(op2){
					case 1 : delete1();
								break;
					case 2 : deletelast();
								break;
					case 3 : deletepos();
								break;
				}
			
			break;
		}
		case 3 : display();
					break;
	}
	printf("Enter 1 to continue and 0 to exit");
	scanf("%d",&k);
	}
}
