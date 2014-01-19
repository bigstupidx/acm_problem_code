#include<stdio.h>
#include<math.h>
#define PI 3.1415926
int main()
{
	double s;
	while(scanf("%lf",&s)!=EOF){
		printf("%.2lf\n%.2lf\n%.2lf\n",sqrt(s*s*s/(72*PI)),sqrt(2*s/PI),sqrt(s/(4*PI)));
	}
	return 0;
}