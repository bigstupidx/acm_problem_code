#include<stdio.h>

struct nnode{
	int element;
	int number;
	int lc,rc;
}nnodes[100010];

int n,query;
int max[20][100010];

void rmq_make(int m)
{
	int t=1,i=0,j;
	while(t*=2,i++,t<=m)
		for(j=t;j<=m;j++)
			max[i][j]=max[i-1][j]>max[i-1][j-t/2]?max[i-1][j]:max[i-1][j-t/2];
}

int rmq_check(int left,int right)
{
	int l=right-left+1,t=1,i=0;
	while(t*2<=l){
		i++;
		t*=2;
	}
	return max[i][left+t-1]>max[i][right]?max[i][left+t-1]:max[i][right];
}

int main()
{
	while(scanf("%d",&n),n){
		int i,j=0,k;
		nnodes[0].element=nnodes[n+1].element=100010;
		scanf("%d",&query);
		for(i=1;i<=n;i++){
			scanf("%d",&nnodes[i].element);
			if(nnodes[i].element!=nnodes[i-1].element){
				++j;
				nnodes[i].number=j;
				nnodes[i].lc=1;
			}
			else{
				nnodes[i].number=j;
				nnodes[i].lc=nnodes[i-1].lc+1;
			}
		}
		k=j;
		for(i=n;i>0;i--){
			if(nnodes[i].number!=nnodes[i+1].number){
				nnodes[i].rc=1;
				max[0][j]=nnodes[i].lc;
				j--;
			}
			else
				nnodes[i].rc=nnodes[i+1].rc+1;
		}
		rmq_make(k);
		for(i=0;i<query;i++){
			int a,b,answer=0;
			scanf("%d%d",&a,&b);
			if(nnodes[a].number==nnodes[b].number)
				answer=nnodes[b].lc-nnodes[a].lc+1;
			else{
				if(nnodes[a].number+1<nnodes[b].number)
					answer=rmq_check(nnodes[a].number+1,nnodes[b].number-1);
				if(answer<nnodes[a].rc)answer=nnodes[a].rc;
				if(answer<nnodes[b].lc)answer=nnodes[b].lc;
			}
			printf("%d\n",answer);
		}
	}
	return 0;
}