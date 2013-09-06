#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

string arr[16];

void pre_done(){
    arr[0]="{}";
    for(int i=1;i<16;i++){
	arr[i]="{";
	for(int j=0;j<i;j++){
	    if(j!=0){
		arr[i]+=",";
	    }
	    arr[i]+=arr[j];
	}
	arr[i]+="}";
//	cout<<arr[i]<<endl;
//	system("pause");
    }
}
int main(){
    pre_done();
    int nca;
    scanf("%d", &nca);
    while(nca--){
	string a, b;
	cin>>a>>b;
	int j, k;
	for(int i=0;i<16;i++){
	    if(arr[i]==a){
		j=i;
	    }
	    if(arr[i]==b){
		k=i;
	    }
	}
	cout<<arr[j+k]<<endl;
    }
//    system("pause");
    return 0;
}