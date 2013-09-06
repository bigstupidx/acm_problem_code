/*
简单枚举，可以先排序
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
	int x,y;
}nodes[201];

int main()
{
	int n,i,j,temp,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&nodes[i].x,&nodes[i].y);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			int lx,ly,k;
			lx=nodes[j].x-nodes[i].x;
			ly=nodes[j].y-nodes[i].y;
			for(k=0,temp=2;k<n;k++){
				if(k==i||k==j)
					continue;
				if((nodes[k].x-nodes[i].x)*ly==(nodes[k].y-nodes[i].y)*lx)
					temp++;
			}
			if(temp>max)
				max=temp;
		}
	printf("%d\n",max);
	system("pause");
	return 0;
}