#include<stdio.h>
#include<string.h>
char str[80];
int map[26];
int main()
{
	while(gets(str)){
		int len,i,j,k,flag;
		char ans[80];
		memset(map,0,sizeof(map));
		map[0]=map['E'-'A']=map['I'-'A']=map['O'-'A']=map['U'-'A']=1;
		len=strlen(str);
		for(i=0,j=0,flag=0;i<len;i++)
		{
			if(str[i]<='Z'&&str[i]>='A')
			{	if(!map[str[i]-'A']){
					ans[j++]=str[i];
					map[str[i]-'A']=1;
					flag=0;
				}
			}
			else if(str[i]==' '){
				if(!flag)
					ans[j++]=' ',flag=1;
			}
			else{
				ans[j++]=str[i];
				flag=0;
			}
		}
		ans[j]='\0';
		len=strlen(ans);
		i=0;
		while(ans[i]==' '&&i<len)i++;
		j=len-1;
		while(ans[j]==' '&&j>=0)j--;
		for(len=i,k=0;len<=j;len++){
			if(ans[len]==' '&&ans[len+1]<='Z'&&ans[len+1]>='A')
				str[k++]=' ';
			else if(ans[len]!=' ')
				str[k++]=ans[len];
		}
		str[k]='\0';
		printf("%s\n",str);
	}
	return 0;
}