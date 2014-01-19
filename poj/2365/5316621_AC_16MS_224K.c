#include<stdio.h>
#include<math.h>
#define PI 3.1415926535897932384626
double aa[110][2];
int main()
{
	int n;
	double r;
	while(scanf("%d%lf",&n,&r)!=EOF){
		int i;
		float sum=0;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&aa[i][0],&aa[i][1]);
		for(i=0;i<n-1;i++)
			sum+=sqrt((aa[i][0]-aa[i+1][0])*(aa[i][0]-aa[i+1][0])+(aa[i][1]-aa[i+1][1])*(aa[i][1]-aa[i+1][1]));
		sum+=sqrt((aa[0][0]-aa[n-1][0])*(aa[0][0]-aa[n-1][0])+(aa[0][1]-aa[n-1][1])*(aa[0][1]-aa[n-1][1]));
		sum+=2*PI*r;
		printf("%.2lf\n",sum);
	}
	return 0;
}