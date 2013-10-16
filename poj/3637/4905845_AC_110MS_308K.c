#include<stdio.h>
#include<stdlib.h>

int mycompare(const void *e1,const void *e2)
{
	return *(int *)e2-*(int *)e1;
}

int item[20010];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,i;
		long ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&item[i]);
		qsort(item,n,sizeof(int),mycompare);
		for(i=2;i<n;i+=3)
			ans+=item[i];
		printf("%ld\n",ans);
	}
	system("pause");
	return 0;
}