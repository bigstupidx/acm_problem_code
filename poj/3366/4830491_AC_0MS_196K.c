#include<stdio.h>
#include<string.h>
char special_a[21][21];
char special_b[21][21];
int main()
{
	char word[21];
	int i,j,m,n;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
		scanf("%s%s",special_a[i],special_b[i]);
	for(i=0;i<n;i++){
		int len;
		scanf("%s",word);
		len=strlen(word);
		for(j=0;j<m;j++)
			if(!strcmp(word,special_a[j])) break;
		if(j<m) { 
			printf("%s\n",special_b[j]);
			continue;
		}
		if(len>=2&&word[len-1]=='y'&&!(word[len-2]=='a'||word[len-2]=='e'||word[len-2]=='i'
			||word[len-2]=='o'||word[len-2]=='u')){
			for(j=0;j<len-1;j++)
				printf("%c",word[j]);
			printf("%s\n","ies");
			continue;
		}
		if(word[len-1]=='x'||word[len-1]=='o'||word[len-1]=='s'){
			printf("%s%s\n",word,"es");
			continue;
		}
		if(len>=2&&word[len-1]=='h'&&(word[len-2]=='s'||word[len-2]=='c')){
			printf("%ses\n",word);
			continue;
		}
		printf("%ss\n",word);
	}
	return 0;
}
