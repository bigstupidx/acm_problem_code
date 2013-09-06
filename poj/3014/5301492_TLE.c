#include<stdio.h>
#define MAX 4510
#define MOD 1000000007

int f[MAX][MAX];
void pre_done()
{
	int i,j;
	for(i=0;i<MAX;i++)
		f[1][i]=1,f[i][0]=1;
	for(i=2;i<MAX;i++){
		for(j=1;j<i;j++)
			f[i][j]=f[j][j];
		for(j=i;j<MAX;j++)
			f[i][j]=(f[i-1][j]+f[i][j-i])%MOD;
	}
	return ;
}
int main()
{
	int m,n;
	pre_done();
	while(scanf("%d%d",&m,&n)!=EOF){
		printf("%d\n",f[m][n]);
	}
	return 0;
}