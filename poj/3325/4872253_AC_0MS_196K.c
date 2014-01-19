
#include<stdio.h>
int n;
int arrey[102];
int main()
{
	while(scanf("%d",&n),n){
		int i,j,k,sum;
		for(i=0;i<n;i++)
			scanf("%d",&arrey[i]);
		j=k=0;
		sum=arrey[0];
		for(i=1;i<n;i++){
			sum+=arrey[i];
			if(arrey[i]>arrey[j])
				j=i;
			if(arrey[i]<arrey[k])
				k=i;
		}
		sum-=arrey[j]+arrey[k];
		sum/=n-2;
		printf("%d\n",sum);
	}
	return 0;

}