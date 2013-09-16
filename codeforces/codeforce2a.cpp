#include <cstdio>
#include <string>
#include <map>
#include <iostream>

using namespace std;

string s[1001];
int c[1001];

int main(){
	int n;
	while(scanf("%d", &n)!=EOF){
		map<string, int>mp1, mp2;
		
		for(int i = 0;i<n;i++){
			cin>>s[i]>>c[i];
			mp1[s[i]]+=c[i];
		}
		
		int maxi = 0;
		for(map<string,int>::iterator p = mp1.begin();p!=mp1.end();p++){
			if(maxi < p->second){
				maxi = p->second;
			}
		}
		
		for(int i = 0;i<n;i++){
			mp2[s[i]]+=c[i];
			if(mp2[s[i]]>=maxi && mp1[s[i]]==maxi){
				cout<<s[i]<<endl;
				break;
			}
		}
	}
	return 0;
}
