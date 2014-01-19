#include<string.h>
#include<stdlib.h>
#include<stdio.h>
char map[15];
char map1[53]="AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
int maporder[15];
/*int order[15];*/
int len,flag;

int cmp(const void *e1,const void *e2)
{
    return *(int*)e1-*(int*)e2;
}
void next_permutation()
{
     int minlarge,temp;
     int i,kk;
     kk=len-1;
     while(kk>0)
                if(maporder[kk]>maporder[kk-1])break;
                else kk--;
     if(kk==0){
               flag=0;return;}
     minlarge=kk;
     for(i=kk+1;i<len;i++)
         if( maporder[i]<maporder[minlarge] && maporder[i]>maporder[kk-1] )
         minlarge=i;
     temp=maporder[minlarge],maporder[minlarge]=maporder[kk-1],maporder[kk-1]=temp;
     qsort(maporder+kk,len-kk,sizeof(int),cmp);
     return ;
}

int main()
{
    int t;
    /*for(t=2,order[1]=1;t<15;t++)
           order[t]=order[t-1]*t;*/          
    scanf("%d",&t);
    while(t--){
               int i,j,m=1;
               flag=1;
               scanf("%s",map);
               len=strlen(map);
               for(i=0;i<len;i++){
                                 if(map[i]>='a')
                                 maporder[i]=(map[i]-'a')*2+1;
                                 else
                                 maporder[i]=(map[i]-'A')*2;
               }
               qsort(maporder,len,sizeof(int),cmp);
               while(1){
                        for(j=0;j<len;j++)
                        printf("%c",map1[maporder[j]]);
                        printf("\n");
                        next_permutation();
                        if(!flag)break;
               }
    }
    return 0;
}
               
