
class Solution
{
    public:
        TreeNode *copyTree(TreeNode *root)
        {
            if(root == NULL)return NULL;

            TreeNode *result = new TreeNode(root->val);

            if(root->left != NULL)
            {
                result->left = copyTree(root->left);
            }

            if(root->right != NULL)
            {
                result->right = copyTree(root->right);
            }

            return result;
        }

        vector<TreeNode *> buildTree(int cnt, int start)
        {
            vector<TreeNode *> result;

            if(cnt == 0)
            {
                result.push_back(NULL);
            }

            for(int i = 0; i < cnt; i++)
            {
                vector<TreeNode *>ll = buildTree(i, start);
                vector<TreeNode *>rr = buildTree(cnt - i - 1, start + i + 1);

                int n1 = ll.size();
                int n2 = rr.size();

                for(int i1 = 0; i1 < n1; i1++)
                {
                    for(int i2 = 0; i2 < n2; i2++)
                    {
                        TreeNode *root = new TreeNode(start + i);
                        root->left = copyTree(ll[i1]);
                        root->right = copyTree(rr[i2]);
                        result.push_back(root);
                    }
                }

                for(int j = 0; j < n1; j++)delete ll[j];

                for(int j = 0; j < n2; j++)delete rr[j];

                ll.clear();
                rr.clear();
            }

            return result;
        }
        vector<TreeNode *> generateTrees(int n)
        {
            return buildTree(n, 1);
        }
};
