#include<stdio.h>
#include<stdlib.h>
//B172085
//Program is of stack using call by reference
struct stack {
	int a[5];
	int top;
	int max;
};
int main(){
	struct stack *s;
	s=(struct stack*)malloc(sizeof(struct stack));
	s->top=-1;
	s->max=5;
	int h;
	do{
		printf("1-push ,\n 2-pop , ");
		int op;
		scanf("%d",&op);
		switch(op){
			case 1  : if(s->top==s->max-1){
						printf("The stack is full")	;
						break;}
					  else{
					  	int k;
					  	printf("Enter an element to push: ");
					  	scanf("%d",&k);
					  	s->top=s->top+1;
					  	s->a[s->top]=k;
					  	printf("the top is \n");
					  	printf("%d",s->top);
					  }
					  break;
			case 2 : if(s->top==-1){
						printf("The stack is full");
						break;
						}
					 else{
					 	printf("The top of the element is :");
					 	printf("%d",s->a[s->top]);
					 	s->top=s->top-1;
					 }
					 break;
			default:
				{
					printf("Invalid syntax\n");
				}
				break;
		}
		printf("\nEnter 1 to continue\n");
		
		scanf("%d",&h);
	}
	while(h==1);
}
