#include<stdio.h>
#include<math.h>

int main()
{
	long ans,b;
	double a;
	int n;
	while(scanf("%d%d",&b,&n),b||n){
		long x,y,z;
		a=pow(10,(log10(b))/n);
		y=(long)a;
		x=y-1;
		z=y+1;
		ans=fabs(pow(y,n)-b)<fabs(pow(z,n)-b)?y:z;
		ans=fabs(pow(x,n)-b)<fabs(pow(ans,n)-b)?x:ans;
		printf("%ld\n",ans);
	}
	system("pause");
	return 0;
}