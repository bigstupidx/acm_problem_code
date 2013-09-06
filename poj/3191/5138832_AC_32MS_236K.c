#include<stdio.h>
#include<math.h>
int main()
{
	__int64 n;
	char aa[100];
	int i=0;
	scanf("%I64d",&n);
	if(n==0){
			printf("0\n");
			return 0;
    }
    while(n!=0){
	            if(abs(n)%2)
			    {
				            aa[i++]='1';
				            n=(n-1)/(-2);
			    }
		     	else{
        			   	aa[i++]='0';
                        n=n/(-2);
			    }
	}
	while((--i)>=0)printf("%c",aa[i]);
	printf("\n");
	system("pause");
	return 0;
}
