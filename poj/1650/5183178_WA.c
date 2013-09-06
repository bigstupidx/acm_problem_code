#include<stdio.h>
#include<math.h>
int main()
{
	double a;
	while(scanf("%llf",&a)!=EOF){
		int n,d,l,x;
		int i,j;
		double temp=1.0,b;
		scanf("%d",&l);
		x=(int)a;
		for(i=1;i<=l;i++)
			for(j=i*x;j<=l;j++){
				b=(j*1.0)/i;
				if((b-a)>temp)
					break;
				if(fabs(b-a)<temp){
					n=j;d=i;
					temp=fabs(b-a);
				}
			}
		printf("%d %d\n",n,d);
	}
	return 0;
}
