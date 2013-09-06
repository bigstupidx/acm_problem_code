
#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		char str[1010];
		int i,len,j=0;
		scanf("%s",str);
		len=strlen(str);
		for(i=0;i<len;i=j){
			int count=1;
			for(j=i+1;j<len;j++)
				if(str[j]==str[i]) count++;
				else break;
			printf("%d%c",count,str[i]);
		}
		printf("\n");
	}
	return 0;
}
