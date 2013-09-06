#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,s,cnt;
char state[4][20]={"downloading","waiting","paused","finished"};

int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--){
        scanf("%d%d",&n,&m);
        
        map<string,int>mp;
        
        map<string,int>waita;
        map<string,int>::iterator p;
        
        map<string,int,greater<string> >waitd;
        map<string,int,greater<string> >::iterator q;
        
        s=0; cnt=0;
        string op,str;
        
        for(int i=0;i<m;i++){
            cin>>op>>str;
            if(op=="Sort"){
                if(str=="asc")
                    s=0;
                else
                    s=1;
            }
            else if(op=="New"){
                if(cnt<n){
                    cnt++;
                    mp[str]=0;
                }
                else{
                    waita[str]=1;
                    waitd[str]=1;
                }
            }
            else if(op=="Pause"){
                p=mp.find(str);
                if(p!=mp.end()){
                   cnt--;
                   p->second=2;
                }
                else{
                    p=waita.find(str);
                    q=waitd.find(str);
                    mp[str]=2;
                    waita.erase(p);
                    waitd.erase(q);
                }
                if(cnt<n&&!waita.empty()){
                    cnt++;
                    if(!s){
                        p=waita.begin();
                        q=waitd.find(p->first);
                        mp[p->first]=0;
                    }
                    else{
                        q=waitd.begin();
                        p=waita.find(q->first);
                        mp[q->first]=0;
                    }
                    waita.erase(p);
                    waitd.erase(q);
                }
            }
            else if(op=="Continue"){
                p=mp.find(str);
                if(cnt<n){
                    cnt++;
                    p->second=0;
                }
                else{
                    mp.erase(p);
                    waita[str]=1;
                    waitd[str]=1;
                }
            }
            else if(op=="Finish"){
                cnt--;
                p=mp.find(str);
                p->second=3;
                if(cnt<n){
                    if(!waita.empty()){
                        cnt++;
                        if(!s){
                            p=waita.begin();
                            q=waitd.find(p->first);
                            mp[p->first]=0;
                        }
                        else{
                            q=waitd.begin();
                            p=waita.find(q->first);
                            mp[q->first]=0;
                        }
                        waita.erase(p);
                        waitd.erase(q);
                    }
                }
            }
        }
        for(p=waita.begin();p!=waita.end();p++)
            mp[p->first]=1;
        if(!s){
            for(p=mp.begin();p!=mp.end();p++){
                cout<<p->first;
                printf(" %s\n",state[p->second]);
            }
        }
        else{
            cnt=0;
            vector<int>a;
            vector<string>b;
            for(p=mp.begin();p!=mp.end();p++){
                cnt++;
                a.push_back(p->second);
                b.push_back(p->first);
            }
            for(int i=cnt-1;i>=0;i--){
                cout<<b[i];
                printf(" %s\n",state[a[i]]);
            }
        }
        puts("");
    }
    return 0;
}
