#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//B172085
//Infix To Postfix
//Program To change Infix Expression to Postfix expression using stack
struct stack{
	int a[100];
	int top;
	int max;
};
struct stack p;
int b[100],j=0;

int precedence(char s){
	if(s=='('){
		return 0;
	}
	else if(s=='-' || s=='+'){
		return 1;
	}
	else if(s=='*' || s=='/'){
		return 2;
	}
}
void postfix(char k[]){
	int i=0;
	while(k[i]!='~'){
		if(isdigit(k[i]) || isalpha(k[i])){
				b[j]=k[i];
				j=j+1;
					}
		else if(k[i]=='('){
			p.top=p.top+1;
			p.a[p.top]=k[i];
		}
		else if(k[i]==')'){
			while(p.a[p.top]!='('){
				b[j]=p.a[p.top];
				j=j+1;
				p.top=p.top-1;
			}
			p.top=p.top-1;
		}	
		else {
			if(p.top==-1){
				p.top=p.top+1;
				p.a[p.top]=k[i];
			}
			else {
				if(precedence(k[i])<=precedence(p.a[p.top])){
					b[j]=p.a[p.top];
					j=j+1;
					p.top=p.top-1;
					if(precedence(k[i])<=precedence(p.a[p.top])){
						b[j]=p.a[p.top];
						j=j+1;
						//p.top=p.top-1;
						p.a[p.top]=k[i];
					}
					else{
						p.top=p.top+1;
						p.a[p.top]=k[i];}
			}
				else{			
					p.top=p.top+1;
					p.a[p.top]=k[i];
				
				}
		}
			
		}
	i=i+1;
	}
}
void display(){
	int i,l;
	printf("PostfixExpression:")
	for(i=p.top;i>=0;i--){
			b[j]=p.a[i];
			j=j+1;
	}
	for(l=0;l<j;l++){
		printf("%c",b[l]);
	}	
}
int main(){
	p.max=5;
	p.top=-1;
	printf("Enter infinix expression and at last enter null ~");
	char k[100];
	gets(k);
	postfix(k);	
	display();
}
