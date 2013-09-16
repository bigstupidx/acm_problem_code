
#include<stdio.h>
char arrey[2010];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,j,x,y;
		int t=0;
		for(i=0;i<n;i++)
			scanf("%s",arrey+i);/*接收方式不同*/
		i=0;j=n-1;
		while(i<j){
			x=i;y=j;
			while(x<=y)
			{
				if(arrey[x]<arrey[y]){
					printf("%c",arrey[i]);
					i++;
					break;
				}
				else if(arrey[x]>arrey[y]){
					printf("%c",arrey[j]);
					j--;
					break;
				}
				x++;y--;
			}
			if(x>y){
				printf("%c",arrey[i]);
				i++;
			}
			if(t%80==79)printf("\n");
			t++;
		}
		printf("%c\n",arrey[i]);
	}
	return 0;
}
