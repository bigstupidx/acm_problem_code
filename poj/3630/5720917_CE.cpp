#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char str[10010][12];
int n;
bool cmp(char a[],char b[])
{
	int len1=strlen(a);
	int len2=strlen(b);
	return len1>len2;
}
int mystrstr(int i,int j)
{
	int k,len1=strlen(str[i]),len2=strlen(str[j]);
	for(k=0;k<len1;k++)
		if(str[[i][k]!=str[j][k])
			break;
	if(k==len1)return 0;
	return 1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%s",str[i]);
		sort(str,str+n),cmp;
		int i,flag=1;
		for(i=0;i<n;i++)
		{
			if(!flag)break;
			flag=1;
			for(int j=i+1;j<n;j++)
				if(mystrstr(i,j)){flag=0;break;}
		}
		if(i==n)puts("NO");
		else puts("YES");
	}
	return 0;
}