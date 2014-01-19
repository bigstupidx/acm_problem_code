#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char map[26]="01230120022455012623010202";
char str[21];

void solve()
{
	int i,j,len;
	char ans[21];
	len=strlen(str);
	for(i=0;i<len;i++)
		str[i]=map[str[i]-'A'];
	ans[0]=str[0];
	for(i=1,j=1;i<len;i++)
		if(str[i]!='0'&&str[i]!=str[i-1])
			ans[j++]=str[i];
	ans[j]='\0';
	len=strlen(ans);
	if(len==1&&ans[0]=='0')
		printf("\n");
	else if(ans[0]=='0'){
		printf("%s\n",ans+1);
		return ;
	}
	else
		printf("%s\n",ans);
	return ;
}

int main()
{
	while(scanf("%s",str)!=EOF)
		solve();
	system("pause");
	return 0;
}