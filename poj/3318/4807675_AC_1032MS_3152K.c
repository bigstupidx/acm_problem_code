
/*
判断矩阵乘式是否成立。方法是随机化一个1×N的矩阵，两边乘上。
A*B*R 应该 == C*R,其中R为随机化的一个一维向量
如果这个相等的话则可近似认为A*B = C成立
*/

#include<stdio.h>
#include<stdlib.h>//rand()发生器的库函数
#include<string.h>

int a[501][501];
int b[501][501];
int c[501][501];
int random[501];
int ans1[501];
int ans2[501];
int ans3[501];

int matrix_mul(int p[501][501],int q[501],int ans[501],int n)
{
   int i,j;
   for(i = 0 ;i < n; i++)
     for(j = 0 ; j < n; j++)
        ans[i] += p[i][j] * q[j];
   return 0;
}
int main()
{
	int n,i,j;
    scanf("%d",&n);
    
	memset(ans1,0,sizeof(ans1));
    memset(ans2,0,sizeof(ans2));
    memset(ans3,0,sizeof(ans3));
    memset(random,0,sizeof(random));
    
	for(i=0;i<n;i++)
       for(j=0;j<n;j++)
           scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
       for(j=0;j<n;j++)
           scanf("%d",&b[i][j]);
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
           scanf("%d",&c[i][j]);

    for(i=0;i<n;i++)
           random[i]=rand();
    matrix_mul(b,random,ans1,n); //a * b * c = a * (b * c) , a * b *c != a * c * b
    matrix_mul(a,ans1,ans2,n);
    matrix_mul(c,random,ans3,n);

    for(i = 0 ;i < n; i++){

        if(ans2[i] != ans3[i]){
           printf("NO\n");
           return 0;
		}
    }
    printf("YES\n");
    return 0;
}
