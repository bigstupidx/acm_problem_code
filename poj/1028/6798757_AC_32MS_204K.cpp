#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main()
{
    stack<string>back, front;
    string op, now, start="http://www.acm.org/";
    now=start;
    while(cin>>op, op!="QUIT"){
        if(op=="VISIT"){
            back.push(now);
            cin>>now;
            cout<<now<<endl;
            while(!front.empty())front.pop();
        }
        else if(op=="BACK"){
            if(!back.empty()){
                front.push(now);
                now=back.top();back.pop();
                cout<<now<<endl;
            }
            else
                cout<<"Ignored"<<endl;
        }
        else{
            if(!front.empty()){
                back.push(now);
                now=front.top();front.pop();
                cout<<now<<endl;
            }
            else
                cout<<"Ignored"<<endl;
        }
    }
    return 0;
}
