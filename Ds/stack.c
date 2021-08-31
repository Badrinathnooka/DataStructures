#include<stdio.h>
#include<stdlib.h>
//B172085
//Program of stack (push and pop)
struct stack{
	int a[5];
	int top;
	int max;	
};
int main(){
	struct stack s;
	s.top=-1;
	s.max=5;
	int h;
	do{
		printf("1-push ,\n 2-pop , ");
		int op;
		scanf("%d",&op);
		switch(op){
			case 1  : if(s.top==s.max){
						printf("The stack is full")	;
						break;}
					  else{
					  	int k;
					  	printf("Enter an element to push");
					  	scanf("%d",&k);
					  	s.top=s.top+1;
					  	s.a[s.top]=k;
					  	printf("%d",s.top);
	
					  }
		}
		printf("Enter 1 to continue\n");
		
		scanf("%d",&h);
	}
	while(h==1);
}
