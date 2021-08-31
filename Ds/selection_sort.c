#include<stdio.h>
#include<stdlib.h>
//B172085
//This Program is Selection Sort.
int main(){
	int i,j,n,k,m,f;
	printf("Enter size :");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		printf("ENter ele :");
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		k=a[i];
		for(j=i;j<n;j++){
			if(k>a[j]){
				k=a[j];
				m=j;
			}
		}
		f=a[i];
		a[i]=a[m];
		a[m]=f;
	}
	for(i=0;i<n;i++){
			printf("%d ",a[i]);
		}
}
