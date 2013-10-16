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
        map<int,pair<int,int> >mp3;
        map<int,pair<int,int> >::iterator pos,r,qos,par;
        
        int m,q,id,sal,h;
        cin>>m>>q;
        for(int i=0;i<m;i++)
        {
            cin>>id>>sal>>h;
            mp1[id]=make_pair(sal,h);
            mp2[sal]=make_pair(id,h);
            mp3[id]=make_pair(0,0);
        }
        for(pos=mp2.begin();pos!=mp2.end();pos++)
            for(r=pos,r++;r!=mp2.end();r++)
            if(r->second.second>=pos->second.second)
            {
                qos=mp3.find(pos->second.first);
                qos->second.first=r->second.first;
                par=mp3.find(r->second.first);
                par->second.second+=qos->second.second+1;
                break;
            }
        for(int i=0;i<q;i++)
        {
            cin>>id;
            pos=mp3.find(id);
            cout<<pos->second.first<<" "<<pos->second.second<<endl;
        }
    }
    return 0;
}
