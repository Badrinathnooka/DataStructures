#include<stdio.h>
#include<stdlib.h>
//B172085
//Program is about Breadth_first_search (BFS Graph)
struct arra{
	int b[50];
	int f;
	int r;
};
void enque(int ele,struct arra *p){
	p->f++;
	p->b[p->f]=ele;
}
int deque(struct arra *p){
	p->r++;
	return p->b[p->r];
}
int isempty(struct arra *p){
	if(p->f<=p->r){
		return 1;
	}
	else{
		return 0;
	}
}
void print(int visit[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ,",visit[i]);
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
	struct arra *p;
	p=(struct arra *)malloc(sizeof(struct arra));
	p->f=-1;
	p->r=-1;
	enque(0,p);
	while(!isempty(p)){
		k=deque(p);
		if(visit[k]==0){
			printf("%d ",k);
			visit[k]=1;
			for(i=0;i<n;i++){
				if(a[k][i]==1 && visit[i]==0){
					enque(i,p);
				}
			}
		}
	}
	print(visit,n);
}
