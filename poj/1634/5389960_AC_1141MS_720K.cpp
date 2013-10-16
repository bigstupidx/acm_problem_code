#include<algorithm>
#include<iostream>
using namespace std;
int aa[40000],par[40000];

struct node{
    int id,sal,h;
    int par,child;
    bool operator<(const node a)const
    {
        return a.sal>sal;
    }
}nodes[30010];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int q,m;
        cin>>m>>q;
        for(int i=0;i<m;i++)
        {
            cin>>nodes[i].id>>nodes[i].sal>>nodes[i].h;
            nodes[i].par=0;
            nodes[i].child=0;
        }
        sort(nodes,nodes+m);
        for(int i=0;i<m;i++)
            for(int j=i+1;j<m;j++)
            {
                if(nodes[j].h>=nodes[i].h)
                {
                    nodes[i].par=nodes[j].id;
                    nodes[j].child+=nodes[i].child+1;
                    break;
                }
            }
        for(int i=0;i<q;i++)
        {
            int id,j;
            cin>>id;
            for(j=0;j<m;j++)
                if(nodes[j].id==id)
                    break;
            cout<<nodes[j].par<<" "<<nodes[j].child<<endl;
        }
    }
    return 0;
}
