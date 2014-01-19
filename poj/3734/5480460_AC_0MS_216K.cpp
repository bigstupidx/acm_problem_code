#include<iostream>
using namespace std;
int MQ(int d,int n)
{
    if(n==0)return 1;
    if(n==1)return d;
    int tt=MQ(d,n/2);
    if(n%2)
        return (tt*(tt*d)%10007)%10007;
    return (tt*(tt%10007))%10007;    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans;
        cin>>n;
        ans=(MQ(2,n-1)+MQ(4,n-1))%10007;
        cout<<ans<<endl;
    }
}
