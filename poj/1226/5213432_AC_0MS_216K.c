#include<stdio.h>
#include<string.h>
#define MAX 110

char str[MAX][MAX];
char sub[MAX],subrev[MAX],str1[MAX];
int n,ans;

void substring(int start,int length)
{
	int k=0,temp=length;
	while(temp--){
		sub[k]=str1[start+k];
		subrev[k++]=str1[start+temp];
	}
	sub[k]='\0';
	subrev[k]='\0';
	return ;
}

int check()
{
	int i;
	for(i=0;i<n;i++)
		if(strstr(str[i],sub)==NULL&&strstr(str[i],subrev)==NULL)
			return 0;
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int i,j,minlen;
		minlen=MAX;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			int temp;
			scanf("%s",str[i]);
			temp=strlen(str[i]);
			if(temp<minlen){
				minlen=temp;
				strcpy(str1,str[i]);
			}
		}
		for(i=minlen;i>=1;i--)
		{
			for(j=0;j<=minlen-i;j++)
			{
				substring(j,i);
				if(check())
					
					goto next;
			}
		}
next:printf("%d\n",i);
	}
	return 0;
}