#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//B172085
//Postfix to Infix
//Program to change Postfix Expression to Infix Expression
struct stack{
	char a[100];
	int top;
};
struct stack p;
void push(char l){
	p.top=p.top+1;
	p.a[p.top]=l;
}
void pop(char l){
	p.top=p.top-1;
}
void infinix(char k[]){
	int i=0;
	while(k[i]!='~'){
		if(isdigit(k[i]) || isalpha(k[i])){
				push(k[i]);
				push(' ');
					}	
		else{
			int j;
			for(j=p.top-1;j>=0;j--){
				if(p.a[j]==' ')
				{
					p.a[j]=k[i];
					break;
				}
			}
		}
	i=i+1;
}
	printf("\npostfix =%s",k);
	printf("\ninfinix= %s",p.a);
	
}
int main(){
	char k[100];
	printf("Enter postfix expression add '~' at last ");
	gets(k);
	p.top=-1;
	infinix(k);	
}


