#include<stdio.h>
//B172085
//Quick sort Program 
//To sort the elements in ascendeing order
void swap(int *a, int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
int partition(int a[],int low,int high){
	int pivot = a[high];
	int i = (low-1);
	int j;
	for(j=low;j<=high-1;j++){
		if(a[j]<pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return (i+1);
}
void quicksort(int a[],int low,int high){
	if(low<high){
		int pi = partition(a,low,high);
		quicksort(a,low,pi-1);
		quicksort(a,pi+1,high);
		
	}
}
void print(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}

int main(){
	int n,i;
	printf("ENter size :");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		printf("Enter ele :");
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	print(a,n);
}
