/*
水题
*/

#include<stdio.h>
#include<string.h>
int map[8]={1,2,4,8,16,32,64,128};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               char ip[32];
               int a[4],i,j;
               memset(a,0,sizeof(a));
               scanf("%s",ip);
               for(i=0;i<4;i++)
                   for(j=i*8;j<(i+1)*8;j++)
                      a[i]+=(ip[j]-'0')*map[(i+1)*8-j-1];
               printf("%d.%d.%d.%d\n",a[0],a[1],a[2],a[3]);
    }
    return 0;
}
                                
               
               
