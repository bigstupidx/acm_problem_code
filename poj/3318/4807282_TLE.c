

//-------------------

#include<stdio.h>
#include<time.h>
// srand( (unsigned)time(NULL) );//随机产生一个rand（）函数的初始值
int a[500][500];
int b[500][500];
long c[500][500];

int main()
{

	int n,w=0;
	int i,j,k;
	long sum;
	int x,y;
	long times=100000;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&b[i][j]);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%ld",&c[i][j]);
	srand( (unsigned)time(NULL) );//初始化随机数发生器 
	while(times--){
		sum=0;
		x=rand();
		y=rand();
		i=(int)x%((n-1)-0+1)+0;  //随机数的范围:
		j=(int)y%((n-1)-0+1)+0;  //(int)x%(max-min+1)+min产生一个[min,max]区间内的数
		for(k=0;k<n;k++)
			sum+=a[i][k]*b[k][j];
		if(sum!=c[i][j]){
			w=1;break;
		}
	}
	if(w==1)
			printf("NO\n");
	else
			printf("YES\n");
	return 0;
}
