#include<stdio.h>
#include<string.h>

int main()
{
	char str[200];
	while(gets(str)){
		int len,i,ans=0,top,top1;
		char stack[2][200];
		if(!strcmp(str,"end"))
			break;
		len=strlen(str);
		top=top1=0;
		for(i=0;i<len;i++)
		{
			if(str[i]=='(')
				stack[0][++top]='(';
			else if(str[i]=='[')
				stack[1][++top1]='[';
			else if(str[i]==')'){
				if(stack[0][top]=='(')
					ans++,top--;
			}
			else{
				if(stack[1][top1]=='[')
					ans++,top1--;
			}
		}
		printf("%d\n",ans*2);
	}
	return 0;
}