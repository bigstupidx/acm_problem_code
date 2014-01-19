#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000000
double total,ans;
double matrix[500][500];
double closed[500];
char str[500][24];
int n;
int cmp(const void *e1,const void *e2)
{
    return strcmp((char*)e1,(char*)e2);
}
int find(char xx[])
{
    int low=0,high=n-1,middle,t;
    while(low<=high)
    {
                    middle=(low+high)/2;
                    t=strcmp(xx,str[middle]);
                    if(t==0)return middle;
                    else if(t>0)low=middle+1;
                    else high=middle-1;
    }
    return -1;
}
int prim()
{
	int i,j,k;
	double temp;
	for(i=0;i<n;i++)
		closed[i]=matrix[0][i];
	closed[0]=0;
	for(j=0;j<n-1;j++)
	{
		temp=MAX;
		for(i=0;i<n;i++)
			if(closed[i]&&temp>closed[i])
			{
				temp=closed[i];k=i;
			}
		ans+=temp;
		closed[k]=0;
		for(i=0;i<n;i++)
			if(closed[i]&&closed[i]>matrix[k][i])
				closed[i]=matrix[k][i];
	}
	if(ans>total)return 0;
	return 1;
}
int main()
{
    int i,j,k;
    double temp;
    char aa[24],bb[24];
    
    memset(matrix,0,sizeof(matrix));
    scanf("%lf",&total);
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",str[i]);
    
    qsort(str,n,sizeof(str[0]),cmp);
    scanf("%d",&k);
    while(k--)
    {
              scanf("%s%s%lf",aa,bb,&temp);
              i=find(aa);j=find(bb);
              matrix[i][j]=matrix[j][i]=temp;
    }
    for(i=0;i<n;i++)for(j=0;j<n;j++)
                    if(!matrix[i][j])matrix[i][j]=MAX;
    if(prim())printf("Need %.1lf miles of cable\n",ans);
    else printf("Not enough cable\n");
	return 0;
}
