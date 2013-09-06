#include<stdio.h>
#include<string.h>
char number[32000];
int t,len;
int getnumber()
{
	int i,ans=0;
	for(i=0;i<len;i++){
		int xx;
		if(number[i]<='9')
			xx=number[i]-'0';
		else if(number[i]>='a')
			xx=number[i]-'a'+36;
		else 
			xx=number[i]-'A'+10;
		ans+=xx;
	}
	return ans;
}
int main()
{
	while(scanf("%s",number)!=EOF){
		int i,num;
		t=1;
		len=strlen(number);
		for(i=0;i<len;i++){
			int xx;
			if(number[i]<='9')
				xx=number[i]-'0';
			else if(number[i]>='a')
				xx=number[i]-'a'+36;
			else 
				xx=number[i]-'A'+10;
			if(t<xx)t=xx;
		}
		num=getnumber();
		for(i=t+1;i<=62;i++){
			if(!(num%(i-1)))break;
		}
		printf("%d\n",i);
	}
	return 0;
}
