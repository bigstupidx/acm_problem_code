
class Solution
{
    public:
        bool isSymmetric(TreeNode *root)
        {
            if(root == NULL)return true;

            int now = 0;
            vector<TreeNode *> Q[2];
            Q[0].push_back(root);

            do
            {
                int n = Q[now].size();
                int m = n / 2;

                for(int i = 0; i < m; i++)
                {
                    TreeNode *item1 = Q[now][i];
                    TreeNode *item2 = Q[now][n - i - 1];

                    if(item1->val != item2->val)return false;

                    if(item1->left != NULL && item2->right == NULL
                            ||
                            item1->left == NULL && item2->right != NULL)
                        return false;

                    if(item1->right != NULL && item2->left == NULL || item1->right == NULL && item2->left != NULL)
                        return false;
                }

                Q[1 - now].clear();
                Q[1 - now].reserve(0);


                for(int i = 0; i < n; i++)
                {
                    TreeNode *item = Q[now][i];

                    if(item == root)
                    {
                        if(item->left != NULL && item->right == NULL || item->left == NULL && item->right != NULL)
                        {
                            return false;
                        }
                    }

                    if(item->left != NULL)
                    {
                        Q[1 - now].push_back(item->left);
                    }

                    if(item->right != NULL)
                    {
                        Q[1 - now].push_back(item->right);
                    }
                }

                if(Q[1 - now].size() == 0)break;

                now = 1 - now;
            }
            while(true);

            return true;
        }
};
