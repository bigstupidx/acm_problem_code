/*
http://acm.pku.edu.cn/JudgeOnline/problem?id=2914
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1000000000;

int graph[600][600],A[600],V[600],W[600];

// Stoer-Wagner Algorithm
int globalMinCut(int n)
{

    int best=MAX;
    for(int i=0;i<n;i++)
        V[i]=i;
    while(n>1){
        //the most tightly connected vertex.

        int maxj=1;
        // initialize set A and other vertex's weight
        A[V[0]] = true;
        for(int i=1; i<n; ++i)
        {
            A[V[i]]=false;
            W[i]=graph[V[0]][V[i]];
            if(W[i]>W[maxj])
                maxj=i;
        }
        // find a min-cut
        int prev=0,buf=n;
        while(--buf)
        {
            // add it to A
            A[V[maxj]]=true;
            if(buf==1)
            {
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
                if(!A[V[j]])
                {
                    W[j]+=graph[V[prev]][V[j]];
                    if(maxj<0 || W[j]>W[maxj])
                        maxj=j;
                }
        }
    }
    return best;
}


int main()
{
    // n - vertex number
    // m - edge number
    int n,m;
    while(scanf("%d %d",&n,&m)==2)
    {
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
