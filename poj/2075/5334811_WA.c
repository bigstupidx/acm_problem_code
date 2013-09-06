#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000000

double total,ans;
char str[500][24];
struct node {
	int i,j;
	double value;
}nodes[250000];
int n,m,father[500],rank[500];

int cmp(const void *e1,const void *e2)
{
    return strcmp((char*)e1,(char*)e2);
}
int cmp1(const void *e1,const void *e2)
{
	struct node *p1,*p2;
	p1=(struct node *)e1;
	p2=(struct node *)e2;
	return p1->value-p2->value;
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
int myfind(int i)
{
	int t;
	if(father[i]==-1)
		return i;
	t=myfind(father[i]);
	father[i]=t;
	return t;
}

void unionij(int i,int j)
{
	if(rank[i]>rank[j])
		father[j]=i;
	else{
		father[i]=j;
		if(rank[i]==rank[j])
			rank[j]++;
	}
}
int kruskal()
{
	int i,j,k;
	for(k=0;k<m;k++){
		i=myfind(nodes[k].i);
		j=myfind(nodes[k].j);
		if(i!=j){
			unionij(i,j);
			ans+=nodes[k].value;
		}
	}
	if(ans>total)return 0;
	return 1;
}
int main()
{
    int i,k;
    double temp;
    char aa[24],bb[24];
    
	memset(father,-1,sizeof(father));
	memset(rank,0,sizeof(rank));
    scanf("%lf",&total);
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",str[i]);
    
    qsort(str,n,sizeof(str[0]),cmp);
    scanf("%d",&m);
    for(k=0;k<m;k++)
    {
              scanf("%s%s%lf",aa,bb,&temp);
              nodes[k].i=find(aa);
			  nodes[k].j=find(bb);
              nodes[k].value=temp;
    }
	qsort(nodes,m,sizeof(nodes[0]),cmp1);
    if(kruskal())printf("Need %.1lf miles of cable\n",ans);
    else printf("Not enough cable\n");
	return 0;
}
