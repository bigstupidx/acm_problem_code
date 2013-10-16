#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
struct node{
	char s[12];
	bool operator<(node a)const
	{
		int len1=strlen(a.s);
		int len2=strlen(s);
		return len1>len2;
	}
}str[10010];

int mystrstr(int i,int j)
{
	int k;
    int len1=strlen(str[i].s),len2=strlen(str[j].s);
	for(k=0;k<len1;k++)
		if(str[i].s[k]!=str[j].s[k])
			break;
	if(k==len1)return 1;
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%s",str[i].s);
		sort(str,str);
		int i,flag=1;
		for(i=0;i<n;i++)
		{
			if(!flag)break;
			for(int j=i+1;j<n;j++)
				if(mystrstr(i,j)){flag=0;break;}
		}
		if(!flag)puts("NO");
		else puts("YES");
	}
	return 0;
}
