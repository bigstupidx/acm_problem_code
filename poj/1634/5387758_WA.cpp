#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        map<int,pair<int,int> >mp1;
        map<int,pair<int,int> >mp2;
        map<int,pair<int,int> >::iterator pos,r;
        int m,q,id,sal,h;
        cin>>m>>q;
        for(int i=0;i<m;i++)
        {
            cin>>id>>sal>>h;
            mp1[id]=make_pair(sal,h);
            mp2[h]=make_pair(id,sal);
        }
        for(int i=0;i<q;i++)
        {
            int num=0,flag=0;
            cin>>id;
            pos=mp1.find(id);
            h=pos->second.second;
            pos=mp2.find(h);
            sal=pos->second.second;
            for(r=pos;r!=mp2.end();r++)
            {
                if(r->second.second>sal)
                {
                    cout<<r->second.first<<" ";
                    flag=1;break;
                }
            }
            if(!flag)cout<<0<<" ";
            for(r=mp2.begin();r!=pos;r++)
                if(r->second.second<sal)num++;
            cout<<num<<endl;
        }
    }
    return 0;
}
