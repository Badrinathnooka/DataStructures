//B172085
//This Program is for doubleLinked list 
//It has features or functions like  1-append 2-append_position 3-delete 4-delete_first 5-delete_last 6-sort 7-reverse 8-display
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int ele;
	struct node *next;	
};
struct node *head = NULL;

void display(){
	struct node *m;
	m=head;
	while(m!=NULL){
		//printf("prev = %d ",m->prev);
		printf("ele = %d ",m->ele);
		//printf("next = %d ",m->next);
		printf("\n");
		m=m->next;
	}
}

void append(){
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("Enter the element: ");
	scanf("%d",&nn->ele);
	nn->next=NULL;
	nn->prev=NULL;
	if(head==NULL){
		head = nn;
	}
	else{
		struct node *p;
		p=head;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=nn;
		nn->prev=p;
	}
	printf("Enter 1 to continue or any key to exit");
	int k;
	scanf("%d",&k);
	if(k==1){
		append();
	}
}
void position(){
	printf("Enter the position to append the node :");
	int l,c=0;
	scanf("%d",&l);
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("Enter the element");
	scanf("%d",&nn->ele);
	nn->next=NULL;
	nn->prev=NULL;
	struct node *p;
	struct node *k;
	p=head;
	k=head;
	while(c!=l-1 && p->next!=NULL){
		p=p->next;
		k=k->next;
		c=c+1;
	}
	k=k->next;
	if(p->next!=NULL){
		struct node *temp;
		temp = p->next;
		p->next=nn;
		nn->prev=p;
		nn->next=temp;
		k->prev=nn;
	}
	else {
		printf("the position is out of range :-");		
	}
}
void delete(){
	printf("Enter element to delete :");
	int k;
	scanf("%d",&k);
	struct node *p;
	struct node *m;
	p=head;
	m=head;
	while(p->ele!=k){
		printf("\nYES");
		p=p->next;
		m=m->next;
	}
	p=p->next;
	m=m->prev;
	p->prev=m;
	m->next=p;
}
void delete1(){
	int c=0;
	struct node *p;
	p=head;
	while(c!=1){
		p=p->next;
		c=c+1;
	}
	head = p;
	p->prev=NULL;
}
void deletelast(){
	struct node *p;
	p=head;
	while(p->next->next!=NULL){
		p=p->next;	
	}
	p->next=NULL;
}
void sort(){
	struct node *p;
	struct node *m;
	for(m=head;m!=NULL;m=m->next){
		p=m->next;
		while(p!=NULL){
			if(m->ele>p->ele){
				int temp;
				temp = m->ele;
				m->ele = p->ele;
				p->ele = temp;
			}
			p=p->next;
		}	
	}
}
void reverse(){
	struct node *p;
	struct node *m;
	p=head;
	m=head;
	int c=0,w;
	while(p->next!=NULL){
		p=p->next;
		c=c+1;
	}
	w=c/2;
	c=0;
	while(w!=c){
		int temp;
		temp = p->ele;
		p->ele=m->ele;
		m->ele = temp;
		c=c+1;
		m=m->next;
		p=p->prev;
	}	
}
int main(){
  while(1){
	printf("Select 1-append 2-append_position 3-delete 4-delete_first 5-delete_last 6-sort 7-reverse 8-display :");
	int op,c;
	scanf("%d",&op);
	switch(op){
		case 1 : append();
					break;
		case 2 : position();
					break;
		case 3 : delete();
					break;
		case 4 : delete1();
					break;
		case 5 : deletelast();
					break;
		case 6 : sort();
					break;
		case 7 : reverse();
					break;
		case 8 : display();
					break;
	}
	printf("Enter 1 to continue or 2 to exit :");
	scanf("%d",&c);
	if(c!=1){
		exit(0);
	}
}
	
}
