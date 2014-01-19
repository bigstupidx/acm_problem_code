#include<stdio.h>
#include<queue>
#include<string.h>
#include<math.h>
using namespace std;
int map[64];
struct node{
    char num[65];
    int va;
    int k;
};
int main()
{
    map[0]=1;
    for(int i=1;i<64;i++)
        map[i]=2*map[i-1];
    int t;
    scanf("%d",&t);
    while(t--){
        int m,n;
        int flag=0;
        char str[65];
        queue<node>Q;
        node now ,next;
        scanf("%d%s%d",&m,str,&n);
        now.k=m-1;
        now.num[m-1]='0';
        now.num[m]='\0';
        now.va=0;
        Q.push(now);
        now.num[m-1]='1';
        if(str[m-1]=='p')
        now.va=1;
        else
        now.va=-1;
        Q.push(now);
        while(!Q.empty()){
            now=Q.front();Q.pop();
            int x=now.k;
            if(now.va==n){
                flag=1;
                for(int j=0;j<x;j++)now.num[j]='0';
                printf("%s\n",now.num);
                break;
            }
            if(x==0)continue;
            next.k=x-1;
            strcpy(next.num,now.num);
            next.num[x-1]='0';
            next.va=now.va;
            Q.push(next);
            
            next.num[next.k]='1';
            if(str[x-1]=='p')
                next.va=now.va+map[m-x];
            else
                next.va=now.va-map[m-x];
            Q.push(next);
        }
        if(flag)continue;
        else printf("Impossible\n");
    }
    return 0;
}
