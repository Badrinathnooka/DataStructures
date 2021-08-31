#include<stdio.h>
#include<stdlib.h>
//B172085
//This program is about shell sort
void shellsort(int a[],int num){
	int i,j,k,temp;
	for(i=num/2;i>0;i=i/2){
		for(j=i;j<num;j++){
			for(k=j-i;k>=0;k=k-i){
				if(a[k+i]>=a[k]){
					break;
				}
				else{
					temp = a[k];
					a[k]=a[k+i];
					a[k+i]=temp;
				}
			}
		}
	}
}

int main(){
	int i,j,n;
	printf("Enter size :");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		printf("ENter ele :");
		scanf("%d",&a[i]);
	}
	shellsort(a,n);
	printf("SOrted elements are : ");
	for(i=0;i<n;i++){
		printf("%d,",a[i]);
	}
}
