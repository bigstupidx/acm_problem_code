
class Solution
{
    public:
        vector<vector<int> > zigzagLevelOrder(TreeNode *root)
        {
            vector<vector<int> > ans;

            if (root == NULL)
                return ans;

            int now = 0;
            vector<TreeNode *> Q[2];
            Q[0].push_back(root);

            do
            {
                Q[1 - now].clear();
                Q[1 - now].reserve(0);
                vector<int> arr;

                for (int i = 0, n = Q[now].size(); i < n; i++)
                {
                    TreeNode *item = Q[now][i];
                    arr.push_back(item->val);

                    if (item->left != NULL)
                    {
                        Q[1 - now].push_back(item->left);
                    }

                    if (item->right != NULL)
                    {
                        Q[1 - now].push_back(item->right);
                    }
                }

                if (now == 1)
                {
                    int n = arr.size() / 2, m = arr.size();

                    for (int temp, i = 0; i < n; i++)
                    {
                        temp = arr[i];
                        arr[i] = arr[m - i - 1];
                        arr[m - i - 1] = temp;
                    }
                }

                ans.push_back(arr);

                if (Q[1 - now].size() == 0)
                    break;

                now = 1 - now;
            }
            while (true);

            return ans;
        }
};
