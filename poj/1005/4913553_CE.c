#include<stdio.h>
#include<math.h>
#define pi 3.1415926

int main(void)
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		float x,y;
		scanf("%f%f",&x,&y);
		int year=0;
		
		do 
		{
			year++;
		}while(pi*(x*x+y*y)>100*year);

		printf("Property %d: This property will begin eroding in year %d.\n",i,year);
	}
	printf("END OF OUTPUT.\n");

	return 0;
}