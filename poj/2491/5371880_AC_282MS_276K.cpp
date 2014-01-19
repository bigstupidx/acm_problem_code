#include<stdio.h>
#include<map>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {
        string a,b;
        map<string,string>mp1,mp2;
        map<string,string>::iterator q,pos;
        int n;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            mp1[a]=b;
            mp2[b]=a;
        }
        for(pos=mp1.begin();pos!=mp1.end();pos++)
        {
            q=mp2.find(pos->first);
            if(q==mp2.end())break;
        }
        printf("Scenario #%d:\n",j);
        cout<<pos->first<<endl;
        for(int i=1;i<n;i++)
        {
            cout<<pos->second<<endl;
            pos=mp1.find(pos->second);
        }
        if(j!=t)cout<<endl;
    }
}
