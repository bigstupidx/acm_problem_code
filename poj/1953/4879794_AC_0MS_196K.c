/*
发现是菲不拉机数列
*/


#include<stdio.h>
long arrey[45];
int main()
{
	int i,t,j=1;
	arrey[0]=1;arrey[1]=1;
	for(i=2;i<=45;i++)
		arrey[i]=arrey[i-1]+arrey[i-2];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&i);
		printf("Scenario #%d:\n%ld\n",j++,arrey[i+1]);
                if(t>0)printf("\n");
	}
	return 0;
}