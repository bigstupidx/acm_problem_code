#include<stdio.h>
int main()
{
    char a[300],b[300];
    while(scanf("%s%s",a,b)!=EOF){
          int i,j,m,n,flag,k,f;
          m=0;n=0;flag=0;k=0;
          for(f=0;a[f];f++){
            for(i=0;a[i];i++){
              if(m)j=m+1;
              else if(flag) j=1;
              else j=0;
              for(;b[j];j++)
                  if(a[i]==b[j]){flag=1;m=j;n++;break;}
            }
            if(k<n)k=n;
          }
          printf("%d\n",k);
    }
    return 0;
}
