#include<stdio.h>
#include<string.h>
#define MAX 10
unsigned result[2][160];
int main()
{
    char *str;
    int i,j,k,n,m;
    unsigned anl[5];
	int flag=0;
	gets(str);
	m=str[7]-'0';
    n=str[8]-'0';
	if(str[7]==' ')m=0;
    n=m*10+n;
    for(j=5;j>0;j--)
      if(str[j]=='.'){
		i=5-j;break;
	}
    m=i;i=0;
    for(j=5;j>=0;j--){
		if(j!=5-m){
			anl[i]=str[j]-'0';
			result[1][i++]=str[j]-'0';}
		else
			continue;
	}
    for(i=0;i<n-1;i++){
		for(j=0;j<5;j++)
			for(k=0;k<5*(i+1);k++)
				result[flag][k+j]+=result[!flag][k]*anl[j];
		for(k=0,j=0;k<(i+2)*5+1;k++,j++)
			if(result[flag][j]>=10){
				result[flag][j+1]+=result[flag][j]/10;
				result[flag][j]%=10;
			}
		flag=!flag;
		memset(result[flag],0,sizeof(result[flag]));
	}
	flag=!flag;
	for(i=0;i<160;i++)
		if(result[flag][i])break;
	k=i;m=m*n;j=0;n=0;
	for(i=159;i>=k;i--)
		if(i>m-1){
			if(j)
				printf("%d",result[flag][i]);
			else if(result[flag][i]){
				printf("%d",result[flag][i]);j=1;}
		}
		else if(i<=m-1&&n)
			printf("%d",result[flag][i]);
		else if(i==m-1&&!n){
			printf(".");i++;n=1;
		}
	getch();
}
