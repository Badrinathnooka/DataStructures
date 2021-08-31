#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//B172085
//Infix To Prefix
//This program is to change the Infix expression to Prefix expression
struct stack{
	int a[100];
	int top;
};
struct stack p;
char b[100];
int j=0;

int precedence(char s){
	if(s==')'){
		return 0;
	}
	else if(s=='-' || s=='+'){
		return 1;
	}
	else if(s=='*' || s=='/'){
		return 2;
	}
}
void prefix(char k[],int i){
	while(i>=0){
		if(isdigit(k[i]) || isalpha(k[i])){
				b[j]=k[i];
				j=j+1;
					}
		else if(k[i]==')'){
			p.top=p.top+1;
			p.a[p.top]=k[i];
		}
		else if(k[i]=='('){
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
					p.a[p.top]=k[i];
			}
				else{
					p.top=p.top+1;
					p.a[p.top]=k[i];
				}
		}
			
		}
	i=i-1;
	}
	
}
void display(){
	int i,l;
	for(i=p.top;i>=0;i--){
			b[j]=p.a[i];
			j=j+1;
	}
	for(l=j;l>=0;l--){
		printf("%c",b[l]);
	}	
}
int main(){
	p.top=-1;
	char k[100];
	printf("Enter the infix expression :");
	scanf("%s",k);
	int i;
	i=strlen(k)-1;
	prefix(k,i);
	display();
}
