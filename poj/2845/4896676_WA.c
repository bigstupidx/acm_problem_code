/*水题一道*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int a[85],b[85],c[85];
int main()
{
	char str1[83],str2[83];
	int t;
	scanf("%d",&t);
	while(t--){
		int i,j=0,len1,len2;
		int count,flag=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		scanf("%s%s",str1,str2);
		
		len1=strlen(str1);
		len2=strlen(str2);
		for(i=len1-1;i>=0;i--)
			a[j++]=str1[i]-'0';
		
		for(i=len2-1,j=0;i>=0;i--)
			b[j++]=str2[i]-'0';
		
		len1=len1>len2?len1:len2;
		for(i=0,count=0;i<=len1+1;i++){
			c[i]=(a[i]+b[i]+count)%2;
			count=(a[i]+b[i]+count)/2;
		}
		for(i=len1+2;i>=0;i--)
			if(!flag&&c[i]){
				flag=1;
				printf("%d",c[i]);
			}
			else if(flag)
				printf("%d",c[i]);
		printf("\n");
	}
	system("pause");
	return 0;
}