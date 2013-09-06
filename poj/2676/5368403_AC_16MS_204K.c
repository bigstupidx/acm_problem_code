#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char sudo[10][10];
int place(int r,int c)
{
    int i,j;
    char ch;
    ch=sudo[r][c];
    for(i=0;i<9;i++){
             if(i!=r&&sudo[i][c]==ch)return 0;
             if(i!=c&&sudo[r][i]==ch)return 0;
	}
    for(i=(r/3)*3;i<(r/3+1)*3;i++)
         for(j=(c/3)*3;j<(c/3+1)*3;j++)
               if(i!=r&&j!=c&&sudo[i][j]==ch)return 0;
    return 1;
    
}
int dfs(int loc)
{
     int i;
     if(loc==-1)return 1;
     if(sudo[loc/9][loc%9]!='0')return dfs(loc-1);
     else{
          for(i=0;i<9;i++){
                           sudo[loc/9][loc%9]='1'+i;
                           if(place(loc/9,loc%9)){
                                   if(dfs(loc-1))return 1;
						   }
						   sudo[loc/9][loc%9]='0';
          }          
     }
     return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               int i;
               for(i=0;i<9;i++)
               scanf("%s",sudo[i]);
               dfs(80);
               for(i=0;i<9;i++)
               printf("%s\n",sudo[i]);
    }
    return 0;
}
