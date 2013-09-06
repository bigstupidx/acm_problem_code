#include<stdio.h>
#include<math.h>
int main()
{
	long long n;
	char aa[50];
	int i=0;
	scanf("%lld",&n);
	if(n==0){
			printf("0\n");
			return 0;
    }
    while(n!=1){
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
	aa[i]='1';
	while(i>=0)printf("%c",aa[i--]);
	printf("\n");
	return 0;
}
