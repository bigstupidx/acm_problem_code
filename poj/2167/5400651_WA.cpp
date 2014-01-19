#include<stdio.h>
#include<map>
#include<math.h>
#define MAX 100002
using namespace std;
int prime[MAX];
int ans[MAX];
map<int,int>temp;
void pre_done()
{
    for(int i=2;i<MAX;i++)
        for(int j=2;i*j<MAX;j++)
            prime[i*j]=1;
}

void part_n(int n)
{
    int xx=n;
    temp.clear();
    for(int i=2;i<=n;i++)
        if(!prime[i])
        {
            if(n%i != 0)continue;
            temp[i]=0;
            while(xx%i == 0)
            {
                xx/=i;
                temp[i]++;
            }
        }
    return ;
}
int main()
{
    int n,m;
    pre_done();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        int top=0;
        map<int,int>mp,mm;
        map<int,int>::iterator p,q;
        
        n--;
        part_n(m);
        for( p = temp.begin(); p != temp.end(); p++)
            mm[p->first] = p->second;
        
        part_n(n);
        for( p = temp.begin(); p != temp.end(); p++)
            mp[p->first] = p->second;
        
        if(n%m == 0)
            ans[top++]=1;
        for(i=2;i<n;i++)
        {
            int ok=1;
            part_n(n-i+1);
            for( p = temp.begin(); p != temp.end(); p++)
                mp[p->first] += p->second;
            
            part_n(i);
            for( p = temp.begin(); p != temp.end(); p++)
                mp[p->first] -= p->second;
            
            for( p = mm.begin(); p != mm.end(); p++)
            {
                q=mp.find(p->first);
                if(q->second < p->second)
                {
                    ok=0;
                    break;
                }
            }
            if(ok)  ans[top++]=i;     
        }
        printf("%d\n",top);
        for(i=0;i<top;i++)
            printf("%d ",ans[i]+1);
        puts("");
    }
    return 0;
}
