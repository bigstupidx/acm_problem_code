class Solution
{
    public:
        int getLevel(TreeNode *root, bool &ans)
        {
            if(!ans)return 0;

            if(root == NULL)return 0;

            if(root->left == NULL && root->right == NULL)return 1;

            int level_ll = getLevel(root->left, ans);
            int level_rr = getLevel(root->right, ans);

            if(level_ll - level_rr > 1 || level_rr - level_ll > 1)
            {
                ans = false;
                return 0;
            }

            return max(level_ll, level_rr) + 1;
        }

        bool isBalanced(TreeNode *root)
        {
            bool ans = true;
            getLevel(root, ans);
            return ans;
        }
};
