#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<string>
using namespace std;

int n,man[102][102],woman[102][102],mx[102],my[102];
char str1[30][2],str2[30][2];
void Gale_Shapley()
{
    queue<int>Q;
    memset(mx,-1,sizeof(mx));
    memset(my,-1,sizeof(my));
    for(int i=1;i<=n;i++)Q.push(i);
    while(!Q.empty()){
        int i=Q.front();Q.pop();
        for(int j=0;j<n;j++)
        {
            if(!man[i][j])continue;
            int w=man[i][j],ii,jj;
            if(my[w]==-1){mx[i]=w;my[w]=i;break;}
            for(int k=0;k<n;k++){
                if(woman[w][k]==my[w])ii=k;
                else if(woman[w][k]==i)jj=k;
            }
            if(ii<jj)man[i][j]=0;
            else{
                mx[i]=w;    my[w]=i;
                Q.push(woman[w][ii]);
                break;
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        char name[30];
        scanf("%d",&n);
        map<char,int>mm,gg;
        map<char,int>::iterator p;
        
        for(int i=1;i<=n;i++){
            scanf("%s",str1[i]);
            gg[str1[i][0]]=i;
        }
        for(int i=1;i<=n;i++){
            scanf("%s",str2[i]);
            mm[str2[i][0]]=i;
        }
        
        for(int i=1;i<=n;i++){
            scanf("%s",name);
            p=gg.find(name[0]);
            int ii=p->second;
            for(int j=0;j<n;j++)
            {
                p=mm.find(name[j+2]);
                man[ii][j]=p->second;
            }
        }
        for(int i=1;i<=n;i++){
            scanf("%s",name);
            p=mm.find(name[0]);
            int ii=p->second;
            for(int j=0;j<n;j++)
            {
                p=gg.find(name[j+2]);
                woman[ii][j]=p->second;
            }
        }
        /*
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<n;j++)
                printf("%d ",man[i][j]);
            puts("");
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<n;j++)
                printf("%d ",woman[i][j]);
            puts("");
        }
        //system("pause");
        */
        Gale_Shapley();
        for(int i=1;i<=n;i++)
            printf("%s %s\n",str1[i],str2[mx[i]]);
        if(t!=0)puts("");
    }
    //system("pause");
    return 0;
}
