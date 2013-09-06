#include<stdio.h>
#include<string.h>
int a[26],b[26];
char str1[102],str2[102];

int mycompare(const void *e1,const void *e2)
{
	return *(int *)e1-*(int *)e2;
}

int solve()
{
	int i;
	int len1,len2;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%s%s",str1,str2);
	len1=strlen(str1);
	len2=strlen(str2);
	if(len1!=len2)return 0;
	for(i=0;i<len1;i++){
		a[str1[i]-'A']++;
		b[str2[i]-'A']++;
	}
	qsort(a,26,sizeof(int),mycompare);
	qsort(b,26,sizeof(int),mycompare);
	for(i=0;i<26;i++)
		if(a[i]!=b[i])break;
	if(i==26)return 1;
	return 0;
}

int main()
{
	if(solve())
		printf("YES\n");
	else 
		printf("NO\n");
	return 0;
}

