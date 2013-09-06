#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
long long arr[10000010];
void pre_done()
{
    int i=1;
    queue<long long>Q;
    map<long long,int>mp;
    Q.push(1);
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        arr[i++]=u;
        if(i>10000000)break;
        if(mp.find(2*u+1)==mp.end())
        {
            mp[2*u+1]=1;
            Q.push(2*u+1);
        }
        if(mp.find(3*u+1)==mp.end())
        {
            mp[3*u+1]=1;
            Q.push(3*u+1);
        }
    }
}
int main()
{
    int n;
    pre_done();
    sort(arr+1,arr+10000001);
    while(scanf("%d",&n)!=EOF)
        printf("%lld\n",arr[n]);
    return 0;
}
