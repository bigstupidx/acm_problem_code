#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

bool arr[10000000];

void pre_done()
{
    arr[0] = true;
    arr[1] = true;

    for(int i = 2; i < 10000000; i++)
    {
        if(arr[i])continue;

        for(int j = 2; j * i < 10000000; j++)
        {
            arr[i * j] = true;
        }
    }
}

int main()
{
    int n;
    pre_done();
    vector <int> ans;

    for(int i = 0; i < 10000000; i++)
    {
        if(!arr[i])
        {
            ans.push_back(i);
        }
    }

    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            printf("%d ", ans[i]);
        }

        puts("");
    }

    //system("pause");
    return 0;
}
