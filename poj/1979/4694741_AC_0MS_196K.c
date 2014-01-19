#include<stdio.h>

int m,n;
char str[21][21];

int determine(int i,int j)
{
    if(i<0||i>=m||j<0||j>=n)return 0;
    if(str[i][j]=='#')return 0;
    else{
         str[i][j]='#';
         return (1+determine(i-1,j)+determine(i+1,j)+determine(i,j-1)+determine(i,j+1));
    }
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)&&m!=0&&n!=0){
                                           for(i=0;i<m;i++)
                                               scanf("%s",str[i]);
                                           for(i=0;i<m;i++)
                                               for(j=0;j<n;j++)
                                                   if(str[i][j]=='@')
                                                   printf("%d\n",determine(i,j));
    }
    return 0;
}
    
