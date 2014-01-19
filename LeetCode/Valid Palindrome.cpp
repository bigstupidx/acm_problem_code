#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <queue>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 1002

int c[MAXN];

void merge_sort(int arr[], int len)
{
    if(len < 2)return;

    int len1 = len / 2;
    int len2 = len - len1;

    merge_sort(arr, len1);
    merge_sort(arr + len1, len2);

    int i = 0, j = len1, k = 0;

    while(i < len1 && j < len)
    {
        if(arr[i] < arr[j])
        {
            c[k++] = arr[i++];
        }
        else
        {
            c[k++] = arr[j++];
        }
    }

    while(i < len1)c[k++] = arr[i++];

    while(j < len)c[k++] = arr[j++];

    i = 0;

    while(i < len) {arr[i] = c[i]; i++;}
}


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution
{
    public:
        int isCharter(char ch)
        {
            if(ch >= 'A' && ch <= 'Z')return 1;

            if(ch >= 'a' && ch <= 'z')return 0;

            if(ch <= '9' && ch >= '0')return 0;

            return -1;
        }

        bool isPalindrome(string s)
        {
            int length = s.length();

            if(length <= 1)return true;

            int k = 0;

            for(int i = 0; i < length; i++)
            {
                int flag = isCharter(s[i]);

                if(flag == 0)
                {
                    s[k++] =  s[i];
                }
                else if(flag == 1)
                {
                    s[k++] = s[i] - 'A' + 'a';
                }
            }

            printf("%d\n", k);

            for(int i = 0; i < k / 2; i++)
            {
                if(s[i] != s[k - 1 - i])
                {
                    return false;
                }
            }

            return true;
        }
};

int main()
{

    Solution a;

    a.isPalindrome("aa");

    getchar();

    return 0;
}
