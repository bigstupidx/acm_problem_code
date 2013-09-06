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
	for(i=0;i<n;i++)
		closed[i]=matrix[0][i];
	for(j=1;j<n;j++){
		temp=100000000;
		for(i=0;i<n;i++)
			if(closed[i]&&temp>closed[i])
			{
				temp=closed[i];k=i;
			}
		ans+=temp;
		closed[k]=0;
		for(i=0;i<n;i++)
			if(closed[i]&&matrix[k][i]<closed[i])
				closed[i]=matrix[k][i];
	}
	return ans;
}
int main()
{
	while(scanf("%d",&n)!=EOF){
		int i,j;
		for(i=0;i<n;i++){
			scanf("%lf%lf",xx+i,yy+i);
			for(j=0;j<=i;j++)
				matrix[i][j]=matrix[j][i]=distance(i,j);
		}
		printf("%.2lf\n",prim());
	}
	return 0;
}