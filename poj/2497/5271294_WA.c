#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int aa[30],bb[30],time[3][30];
char name[3][10]={"Steve","Bill","Linus"};

int cmp(const void *e1,const void *e2)
{
	return *(int *)e1-*(int *)e2;
}

int main()
{
	int t,ii;
	scanf("%d",&t);
	for(ii=1;ii<t;ii++)
	{
		int sum[3],total,n,i,nn[3],xx[3];
		scanf("%d%d",&total,&n);
		for(i=0;i<n;i++){
			scanf("%d",aa+i);
			bb[i]=aa[i];
		}
		memset(sum,0,sizeof(sum));
		memset(nn,0,sizeof(nn));
		memset(xx,0,sizeof(xx));
		qsort(bb,n,sizeof(int),cmp);
		time[1][0]=aa[0];time[0][0]=bb[0];time[2][n-1]=bb[n-1];
		for(i=1;i<n;i++){
			time[1][i]=time[1][i-1]+aa[i];
			time[0][i]=time[0][i-1]+bb[i];
			time[2][n-i-1]=time[2][n-i]+bb[n-i-1];
		}
		for(i=0;i<n;i++){
			xx[1]+=aa[i];
			if(xx[1]>total)break;
			nn[1]++;
			sum[1]+=time[1][i];
		}
		for(i=0;i<n;i++){
			xx[0]+=bb[i];
			if(xx[0]>total)break;
			nn[0]++;
			sum[0]+=time[0][i];
		}
		for(i=n-1;i>=0;i--){
			xx[2]+=bb[i];
			if(xx[2]>total)break;
			nn[2]++;
			sum[2]+=time[2][i];
		}
		for(i=1,n=0;i<3;i++){
			if(nn[i]>nn[n])n=i;
			else if(nn[i]==nn[n]){
				if(sum[i]<sum[n])
					n=i;
			}
		}
		printf("Scenario #%d:\n%s wins with %d solved problems and a score of %d.\n\n",ii,name[n],nn[n],sum[n]);
	}
	return 0;
}