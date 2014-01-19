#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
#include <hash_set>

using namespace std;

int ladderLength(string start, string end, unordered_set<string> &dict)
{
    map<int, string> mp;

    int id = 0, g[101][101];

    int inf = 1000000;

    int n = dict.size(), len = start.length(), s, t;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][j] = inf;
        }

        g[i][i] = 0;
    }

    unordered_set<string>::iterator p;

    for (p = dict.begin(); p != dict.end(); p++)
    {
        cout << *p << endl;

        if (*p == start)s = id;

        if (*p == end)t = id;

        mp[id++] = *p;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string a = mp[i];
            string b = mp[j];

            int cnt = 0;

            for (int k = 0; k < len; k++)
            {
                if (a[k] != b[k])
                {
                    ++cnt;
                }
            }

            if (cnt == 1)
            {
                g[i][j] = g[j][i] = 1;
            }
        }
    }

    cout << n << endl;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (g[i][k] == inf)continue;

            for (int j = i + 1; j < n; j++)
            {
                if (g[k][j] == inf)continue;

                if (g[i][j] > g[i][k] + g[k][j])
                {
                    g[i][j] = g[j][i] = g[i][k] + g[k][j];
                }
            }
        }
    }

    return g[s][t];
}


string xx[] = { "hot", "dot", "dog", "lot", "log" };

int main()
{
    unordered_set<string> dict;

    for (int i = 0; i < 5; i++)
    {
        cout << xx[i] << endl;
        dict.insert(xx[i]);
    }

    string yy = "hit";
    string zz = "cog";

    ladderLength(yy, zz, dict);

    int y = 0;
    cin >> y;

    return 0;
}
