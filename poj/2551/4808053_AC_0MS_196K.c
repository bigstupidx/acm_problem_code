/*
内存的计算不仅仅和你定义的变量有关，
还和你使用的操作有关，注意使用移位操作会比乘法操作快，
取模操作尽量少用。
*/

#include <stdio.h>
int main()
{
	int n,a,i;	
	while(scanf("%d",&n)!=EOF)
	{
		for (i=1,a=1;a;i++)
		{
			a=(a<<3)+(a<<1);//a*10
			a++;
			a%=n;
		}
		printf("%d\n",i);
	}
	return 0;
}