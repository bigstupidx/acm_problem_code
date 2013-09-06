#include<stdio.h>
#include<stdlib.h>
int arrey[30];

int mycompare(const void *e1,const void *e2)
{
    return *(int *)e1-*(int *)e2;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,i;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&arrey[i]);
		qsort(arrey,n,sizeof(int),mycompare);
		printf("%d\n",2*(arrey[n-1]-arrey[0]));
	}
	system("pause");
	return 0;
}
