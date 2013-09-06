#include<stdio.h>
#include<string.h>

int sticks[100];
int used[100],n;

int trace(int ,int,int);

int mycompare(const void *e1,const void *e2)
{
	return *(int *)e2-*(int*)e1;
}

int main()
{
	while(scanf("%d",&n),n){
		int i,sum=0;
		memset(used,1,sizeof(int));
		for(i=0;i<n;i++){
			scanf("%d",&sticks[i]);
			sum+=sticks[i];
		}
		qsort(sticks,n,sizeof(int),mycompare);
		for(i=sticks[0];i<=sum;i++){
			if(sum%i!=0)
				continue;
			else{
				if(trace(i,n,0))
					printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}

int trace(int total_lenth,int unused,int left)
{
	int i;
	if(left==0&&unused==0)
		return 1;
	if(left==0)
		left=total_lenth;
	for(i=0;i<n;i++){
		if(!used[i])
			continue;
		if(sticks[i]>left)
			continue;
		used[i]=0;
		if(trace(total_lenth,unused-1,left-sticks[i]))
			return 1;
		used[i]=1;/*当此木棒用上无法走通，则需要将此木棒恢复可用（下一次用）*/
		if(sticks[i]==left||left==total_lenth)/*剪枝，次木棒不能走通，且为拼接的第一根或最后一根*/
			return 0;
	
	}
}
			
