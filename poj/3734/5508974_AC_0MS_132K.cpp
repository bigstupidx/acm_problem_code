#include<iostream>
int exp_modular(int a,int n)
{
    int ans=1;
    int t=a;
    while(n)
    {
        if(n%2)ans=(ans*t)%10007;
        n/=2;
        t=(t*t)%10007;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,t;
        scanf("%d",&n);
        t=exp_modular(2,n-1);
        printf("%d\n",(t+t*t)%10007);
    }
    return 0;
}
