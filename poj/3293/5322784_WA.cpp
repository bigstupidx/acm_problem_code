#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct nodeP
{int x , y , z;};

const int Max = 100010;

nodeP p[Max];
int n , L , ans;
int save[Max] , E[Max][5] , a[Max];
bool used[Max] , success;

bool cmp1(int i , int j)
{
     return(p[i].x < p[j].x || p[i].x == p[j].x && p[i].y < p[j].y); 
} 

bool cmp2(int i , int j)
{
     return(p[i].y < p[j].y || p[i].y == p[j].y && p[i].x < p[j].x); 
} 

void init()
{
     scanf("%d" , &n);
     for (int i = 0 ; i < n ; ++i)
     {
      scanf("%d %d" , &p[i].x , &p[i].y); 
      E[i][0] = -1; 
      E[i][1] = -1; 
      a[i] = i;
     } 
     memset(used , 0 , sizeof(used)); 
     ans = 0 ; L = 1;
     used[0] = 1;     
      
     sort(a , a + n , cmp1); 
     for (int i = 0 ; i < n ; ++i)
      if (i < n - 1&& p[a[i + 1]].x == p[a[i]].x) 
      {
        E[a[i]][0] = a[i + 1]; 
        E[a[i + 1]][0] = a[i];
        ans += p[a[i + 1]].y - p[a[i]].y;
        ++i; 
      }  
     else success = 0; 
     sort(a , a + n , cmp2); 
     for (int i = 0 ; i < n ; ++i)
      if (i < n - 1 && p[a[i + 1]].y == p[a[i]].y) 
      {
        E[a[i]][1] = a[i + 1]; 
        E[a[i + 1]][1] = a[i];
        ans += p[a[i + 1]].x - p[a[i]].x;
        ++i;        
      } 
      else success = 0; 
} 

void work(int k)
{
     ++L; 
     used[k] = 1; 
     if (!used[E[k][0]]) work(E[k][0]);
     else if (!used[E[k][1]]) work(E[k][1]); 

} 

int main()
{
    int tot;
    
    scanf("%d" , &tot);
    while (tot--)
    {
          success = 1;
          init();
          if (success)
           work(E[0][0]); 
          if (L == n && success)  
           cout<<ans<<endl;
          else cout<<-1<<endl; 
    } 
}

