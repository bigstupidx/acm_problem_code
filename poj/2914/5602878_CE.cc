#include <iostream>
#include <algorithm>
#include <cstdio>
#inlcude <cstring>
using namespace std;

#define initSet(n,Arr) for(int i=0;i<n;++i)Arr[i]=i;
#define MAX 1<<30;
int graph[600][600];

// Stoer-Wagner Algorithm
int globalMinCut(int n){
// A is A set for Stoer-Wagner Algorithm
bool* A=new bool[n];
// V is vertex index
int* V=new int[n];
int* W=new int[n];

initSet(n,V);

int best=MAX;
while(n>1){

//the most tightly connected vertex.
int maxj=1;

// initialize set A and other vertex's weight
A[V[0]] = true;
for(int i=1; i<n; ++i){
A[V[i]]=false;
W[i]=graph[V[0]][V[i]];

if(W[i]>W[maxj])
maxj=i;
}

// find a min-cut
int prev=0,buf=n;
while(--buf){
// add it to A
A[V[maxj]]=true;

if(buf==1){
// update min cut
best=min(best,W[maxj]);

// merge prev and last vertex
for(int k=0; k<n; ++k)
   graph[V[k]][V[prev]]=(graph[V[prev]][V[k]]
     +=graph[V[maxj]][V[k]]);
V[maxj]=V[--n];
}
prev=maxj;
maxj=-1;

// update the weights
for(int j=1; j<n; ++j)
if(!A[V[j]]){
   W[j]+=graph[V[prev]][V[j]];

   if(maxj<0 || W[j]>W[maxj])
    maxj=j;
}
}
}

delete[] A;
delete[] V;
delete[] W;
return best;
}


int main(){
// n - vertex number
// m - edge number
int n,m;

while(scanf("%d %d",&n,&m)==2){
memset(graph,0,sizeof(graph)/sizeof(bool));

// v-w is an edge with c weight
int v,w,c;

while(m--){
scanf("%d %d %d",&v,&w,&c);
graph[v][w]+=c;
graph[w][v]+=c;
}

// output min cut
printf("%d\n",globalMinCut(n));
}
}