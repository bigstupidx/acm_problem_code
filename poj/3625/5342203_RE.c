#include<stdio.h>
#include<math.h>
double matrix[102][102];
double closed[102];
double xx[102],yy[102];
int n;
double distance(int i,int j)
{
	return sqrt((xx[i]-xx[j])*(xx[i]-xx[j])+(yy[i]-yy[j])*(yy[i]-yy[j]));
}
double prim()
{
	int i,j,k;
	double ans=0,temp;
	for(i=1;i<=n;i++)
		closed[i]=matrix[1][i];
	closed[1]=-1;
	for(j=1;j<n;j++){
		temp=100000000;
		for(i=1;i<=n;i++)
			if(closed[i]!=-1&&temp>closed[i])
			{
				temp=closed[i];k=i;
			}
		ans+=temp;
		closed[k]=-1;
		for(i=1;i<=n;i++)
			if(closed[i]!=-1&&matrix[k][i]<closed[i])
				closed[i]=matrix[k][i];
	}
	return ans;
}
int main()
{
	int t;
	while(scanf("%d%d",&n,&t)!=EOF){
		int i,j;
		for(i=1;i<=n;i++){
			scanf("%lf%lf",xx+i,yy+i);
			for(j=1;j<=i;j++)
				matrix[i][j]=matrix[j][i]=distance(i,j);
		}
		while(t--){
			scanf("%d%d",&i,&j);
			matrix[i][j]=matrix[j][i]=0;
		}
		printf("%.2lf\n",prim());
	}
	return 0;
}