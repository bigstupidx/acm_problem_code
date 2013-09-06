#include<stdio.h>
#include<stdlib.h>

int flag[50010];
typedef struct cow{
	long a,b;
	int x;
}nodes;
nodes cow[5010];
int n,k;

int mycompare1(const void*e1,const void*e2)
{
	nodes *p1,*p2;
	p1=(nodes *)e1;
	p2=(nodes *)e2;
	return p1->a-p2->a;
}

int mycompare2(const void *e1,const void *e2)
{
	nodes *p1,*p2;
	p1=(nodes *)e1;
	p2=(nodes *)e2;
	return p1->b-p2->b;
}

int main()
{
	int i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%ld%ld",&cow[i].a,&cow[i].b);
		cow[i].x=i+1;
	}
	qsort(cow,n,sizeof(nodes),mycompare1);
	qsort(cow+n-k,k,sizeof(nodes),mycompare2);
	printf("%d\n",cow[n-1].x);
	system("pause");
	return 0;
}

