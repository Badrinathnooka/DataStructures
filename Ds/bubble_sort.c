#include<stdio.h>
#include<stdlib.h>
//B172085
//This Program is Implementation of Bubble sort
int main(){
	int i,j,k,n,temp;
	printf("Enter size :");
	scanf("%d",&k);
	int a[k];
	for(i=0;i<k;i++){
		printf("Enter ele : ");
		scanf("%d",&a[i]);
	}
	n=0;
	while(n!=k){
		for(i=k-1;i>n;i--){
			if(a[i]<a[i-1]){
				temp=a[i];
				a[i]=a[i-1];
				a[i-1]=temp;
			}
		}n=n+1;
	}
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
}
