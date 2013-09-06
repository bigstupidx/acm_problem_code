
#include<stdio.h>

int main()
{
	while(1){
		int i,a[26],b[26];
		char c;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		while(1){
			c=getchar();
			if(c=='\n')
				break;
			if(c==EOF)
				return 0;
			a[c-'a']++;
		}
		while(1){
			c=getchar();
			if(c=='\n')
				break;
			b[c-'a']++;
		}
		for(i=0;i<26;i++){
			int num;
			num=a[i]>b[i]?b[i]:a[i];
			while(num--)
				printf("%c",97+i);
		}
		printf("\n");
	}
	return 0;
}