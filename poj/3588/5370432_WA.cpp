
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               int i,n,m,flag=0;
               string ask,task;
               map<string,string>Q1,Q2,Q3;
               map<string,string>::iterator pos;
               vector<string>str;
               vector<string>::iterator p;
               
               scanf("%d%d",&n,&m);
               for(i=0;i<m;i++){
                    cin>>ask>>task;
                    if(ask=="New"){
                         if(Q1.size()<n)
                               Q1.insert(make_pair(task,"downloading"));
                         else  
                               Q2.insert(make_pair(task,"waiting"));
                    }
                    else if(ask=="Pause"){
                         if(Q1.size()){
                             pos=Q1.find(task);
                             if(pos!=Q1.end()){
                               Q3.insert(make_pair(task,"paused"));
                               Q1.erase(pos);
                               if(!Q2.size())continue;
                               if(!flag)pos=Q2.begin();
                               else {pos=Q2.end();pos--;}
                               Q1.insert(make_pair(pos->first,"downloading"));
                               Q2.erase(pos);
                             }
                         }
                    }
                    else if(ask=="Continue"){
                         if(Q3.size()){
                            pos=Q3.find(task);
                            if(pos!=Q3.end()){
                                if(Q1.size()<n)
                                  Q1.insert(make_pair(pos->first,"downloading"));
                                else
                                  Q2.insert(make_pair(pos->first,"waiting"));
                                Q3.erase(pos);
                            }
                         }
                    }
                    else if(ask=="Finish"){
                         if(Q1.size()){
                            pos=Q1.find(task);
                            if(pos!=Q1.end()){
                                           str.push_back(pos->first);
                                           Q1.erase(pos);
                                           if(!Q2.size())continue;
                                           if(!flag)pos=Q2.begin();
                                           else{pos=Q2.end();pos--;}
                                           Q1.insert(make_pair(pos->first,"downloading"));
                                           Q2.erase(pos);
                            }
                         }
                    }
                    else{
                         if(task=="asc"&&flag)flag=0;
                         else if(task=="desc"&&flag==0)flag=1;
                    }
               }
               for(pos=Q2.begin();pos!=Q2.end();pos++)
                    Q1.insert(make_pair(pos->first,pos->second));
               for(pos=Q3.begin();pos!=Q3.end();pos++)
                    Q1.insert(make_pair(pos->first,pos->second));
               for(p=str.begin();p!=str.end();p++)
                    Q1.insert(make_pair(*p,"finished"));
               if(flag){
                        pos=Q1.end();pos--;
                        do{
                        cout<<pos->first<<' '<<pos->second<<endl;
                        }while((pos--)!=Q1.begin());
               }
               else{
                    for(pos=Q1.begin();pos!=Q1.end();pos++)
                        cout<<pos->first<<' '<<pos->second<<endl;
               }
               if(t!=1)printf("\n");
    }
    return 0;
} 
