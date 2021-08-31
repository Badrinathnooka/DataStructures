#include<stdio.h>
#include<string.h>
//B172085
//Program for implementing graphs using dfs method
int dfs(int k,int visit[],int a[][20],int n){
	if(visit[k]==0){
		printf("k= %d\n",k);
		visit[k]=1;
		int i;
		for(i=0;i<n;i++){
			if(a[k][i]==1 && visit[i]==0)
				dfs(i,visit,a,n);
		}
	}
}
int main(){
	int i,j,k,l,n;
	printf("Enter number of nodes :");
	scanf("%d",&n);
	int a[n][n];
	printf("Enter 0 if not connected else enter 1 if connected to node \n:");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Enter for %d connected for %d :",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	int visit[n];
	for(i=0;i<n;i++){
		visit[i]=0;
	}
	dfs(0,visit,a,n);
	for(i=0;i<n;i++){
		printf("%d",visit[i]);
	}
}
