#include<stdio.h>
int main()
{
    char a[300],b[300];
    while(1){
          int i,j,m,n;
          scanf("%s%s",a,b);
          m=0;n=0;
          for(i=0;a[i];i++)
              for(j=m;b[j];j++)
                  if(a[i]==b[j]){m=j;n++;}
          printf("%d\n",n);
    }
    return 0;
}
