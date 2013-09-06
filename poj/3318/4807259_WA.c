#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int a[500][500],b[500][500],c[500][500];
int n;
int solve()
{
    int i,j,k;
    int times=10000;
    for(i=0;i<n;i++)
              for(j=0;j<n;j++)
              scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
              for(j=0;j<n;j++)
              scanf("%d",&b[i][j]);
    for(i=0;i<n;i++)
              for(j=0;j<n;j++)
              scanf("%d",&c[i][j]);
    srand( (unsigned)time(NULL) );
    while(times--){
               int sum=0;
               i=rand();
               j=rand();
               i=(int)i%((n-1)-0+1)+0;
               j=(int)j%n;
               for(k=0;k<n;k++)
                   sum+=a[i][k]*b[k][j];
               if(sum!=c[i][j])return 0;
    }
    return 1;
}
          
int main()
{
    while(scanf("%d",&n)!=EOF)
        if(solve())
                   printf("YES\n");
        else printf("NO\n");
    return 0;
}
    
