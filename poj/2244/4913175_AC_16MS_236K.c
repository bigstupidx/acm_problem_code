/*
Joesphus问题变形
*/
#include<stdio.h>
#include<stdlib.h>

int n;

int determine(int m)
{
	int i,temp=1;
	for(i=1;i<n-1;i++){
		temp=(temp+m-1)%(n-i);
		if(temp==0)temp=n-i;
		if(temp==1)
			return 0;
		
	}
	return 1;
}

int main()
{
	while(scanf("%d",&n),n){
		int i;
		for(i=2;;i++)
			if(determine(i)){
				printf("%ld\n",i);
				break;
			}
	}
	system("pause");
	return 0;
}