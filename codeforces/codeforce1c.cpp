#include <cstdio>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main(){
	int n;
	while(scanf("%d", &n)!=EOF){
		map<string, int>mp;
		int maxi = -1000000000, point;
		string str, ans;
		for(int i = 0;i<n;i++){
			cin>>str>>point;
			mp[str] += point;
			if(maxi<mp[str]){
				maxi = mp[str];
				ans = str;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
