
#include<stdio.h>
#include<algorithm>
using namespace std;

int arrey[12];
int main()
{
	int n;
	while(scanf("%d",&n),n){
		int i,flag=0;
		for(i=0;i<n;i++)
			scanf("%d",arrey+i);
		if(n%2){
			printf("1\n");
			continue;
		}
		sort(arrey,arrey+n);
		for(i=0;i<n;i+=2){
			if(arrey[i]!=arrey[i+1])
				flag=1;break;
		}
		if(!flag)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}
