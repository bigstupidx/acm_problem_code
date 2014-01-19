class Solution
{
    public:

        int minDepth(TreeNode *root)
        {
            if(root == NULL)return 0;

            if(root->left == NULL && root->right == NULL)return 1;

            int level_ll = minDepth(root->left);
            int level_rr = minDepth(root->right);

            if(level_ll == 0)
            {
                return level_rr + 1;
            }

            if(level_rr == 0)
            {
                return level_ll + 1;
            }

            return min(level_ll, level_rr) + 1;
        }
};
