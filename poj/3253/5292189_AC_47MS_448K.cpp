#include<iostream>
#include<queue>
using namespace std;
struct num{
       int x;
};
bool operator<(num a,num b)
{
     return a.x>b.x;
}
int main()
{
		int i,temp,n;
		long long sum=0;
		priority_queue<num>q;
		num a;
                cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>temp;
			a.x=temp;
			q.push(a);
		}
		if(n==1)cout<<0<<endl;
		else{
			while(q.size()>1){
				int z,y;
				a=q.top();
				z=a.x;
				q.pop();
				a=q.top();
				y=a.x;
				q.pop();
				a.x=z+y;
				q.push(a);
				sum+=z+y;
			}
			cout<<sum<<endl;
		}
	        return 0;
}
