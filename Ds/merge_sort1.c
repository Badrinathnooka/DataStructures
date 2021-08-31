#include<stdio.h>
#include<stdlib.h>
//B172085
//This Program  is Implementation of Merge Sort
int merge(int a[],int st,int mid,int en){
	printf("merge\n");
	int i=st,j=mid+1,k,l=0,c[20];
	
	while(i<=mid && j<=en){
		if(a[i]<a[j]){
			
			c[l]=a[i];
			l=l+1;
			i=i+1;
		}
		else{
			
			c[l]=a[j];
			l=l+1;
			j=j+1;
		}
		
	}
	while(i<=mid){
		
		c[l]=a[i];
		l=l+1;
		i=i+1;
	}
	while(j<=en){
		
		c[l]=a[j];
		l=l+1;
		j=j+1;
	}
	//printf("%d\n",l);
	for(i=0;i<l;i++){
		a[st+i]=c[i];
		//printf("%d\n",a[st+i]);
	}
	
}
int ms(int a[],int st,int en)
{
	if(st<en){
		int mid,i;
		mid = (st+en-1)/2;
		ms(a,st,mid);
		ms(a,mid+1,en);
		merge(a,st,mid,en);
	
	}
}
int main()
{
	int i,j,k,m;
	printf("Enter the size of array :");
	scanf("%d",&k);
	int a[k];
	for(i=0;i<k;i++){
		printf("Enter ele:");
		scanf("%d",&a[i]);
	}
	ms(a,0,k);
	for(i=0;i<k;i++){
		printf("%d  ",a[i]);
	}
}
