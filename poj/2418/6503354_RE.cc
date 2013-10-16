#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int n=0;
    char str[32];
    map<string,int>mp;
    map<string,int>::iterator p;
    while(gets(str)){
        p=mp.find(str);
        if(p==mp.end()){
            mp[str]=1;
        }
        else
            p->second++;
        n++;
    }
    for(p=mp.begin();p!=mp.end();p++){
        printf("%s",p->first);
        printf(" %.4lf\n",(p->second)*100.0/n);
    }
    return 0;
}
