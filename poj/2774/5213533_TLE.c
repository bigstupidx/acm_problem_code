#include<stdio.h>
#include<string.h>
#define MAX 100001

char str[2][MAX];
char sub[MAX];
int ans,flag;


int main()
{
 	while(scanf("%s%s",str[0],str[1])!=EOF){
		int i,j,len1,len2;
		len1=strlen(str[0]);
		len2=strlen(str[1]);
		flag=0;
		if(len1>len2)
			len1=len2,flag=1;
		for(i=len1;i>=1;i--)
			for(j=0;j<=len1-i;j++)
			{
				int k;
				for(k=0;k<i;k++)
					sub[k]=str[flag][j+k];
				sub[k]='\0';
				if(strstr(str[!flag],sub)!=NULL)
					goto next;
			}
next:printf("%d\n",i);
	}
	return 0;
}
