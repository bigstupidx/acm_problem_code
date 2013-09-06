#include<stdio.h>
#define MOD 10000
int matrix[3][3];
int mulmatrix[3][3];
int mulmatrix1[3][3],mulmatrix2[3][3];
int res[4]={0,0,1,1};

void mul()
{
	mulmatrix1[1][1]=mulmatrix2[1][1]=mulmatrix[1][1];
	mulmatrix1[1][2]=mulmatrix2[1][2]=mulmatrix[1][2];
	mulmatrix1[2][1]=mulmatrix2[2][1]=mulmatrix[2][1];
	mulmatrix1[2][2]=mulmatrix2[2][2]=mulmatrix[2][2];
	mulmatrix[1][1]=(mulmatrix1[1][1]*mulmatrix2[1][1]+mulmatrix1[1][2]*mulmatrix2[2][1])%MOD;
	mulmatrix[1][2]=(mulmatrix1[1][1]*mulmatrix2[2][1]+mulmatrix1[1][2]*mulmatrix2[2][2])%MOD;
	mulmatrix[2][1]=(mulmatrix1[2][1]*mulmatrix2[1][1]+mulmatrix1[2][2]*mulmatrix2[2][1])%MOD;
	mulmatrix[2][2]=(mulmatrix1[2][1]*mulmatrix2[1][2]+mulmatrix1[2][2]*mulmatrix2[2][2])%MOD;
	return ;
}

void determine(int n)
{
	int nn;
	if(n==1){
		mulmatrix[1][1]=1;
		mulmatrix[1][2]=1;
		mulmatrix[2][1]=1;
		mulmatrix[2][2]=0;
		return ;
	}
	if(n%2==0){
		nn=n/2;
		determine(nn);
		mul();
		return ;
	}
	else{
		nn=n/2;
		determine(nn);
		mul();
		mulmatrix1[1][1]=mulmatrix[1][1];
		mulmatrix1[1][2]=mulmatrix[1][2];
		mulmatrix1[2][1]=mulmatrix[2][1];
		mulmatrix1[2][2]=mulmatrix[2][2];
		mulmatrix[1][1]=(mulmatrix1[1][1]+mulmatrix1[1][2])%MOD;
		mulmatrix[1][2]=mulmatrix1[1][1];
		mulmatrix[2][1]=(mulmatrix1[2][1]+mulmatrix1[2][2])%MOD;
		mulmatrix[2][2]=mulmatrix1[2][1];
		return ;
	}
}
int main()
{
	int n;
	matrix[1][1]=1;
	matrix[1][2]=1;
	matrix[2][1]=1;
	matrix[2][2]=0;
	while(scanf("%d",&n),n!=-1){
		if(n==0)
			printf("0\n");
		else{
			determine(n);
			printf("%d\n",mulmatrix[1][2]);
		}
	}
	return 0;
}