class Solution
{
    public:
        bool isValidBST(TreeNode *root)
        {
            map<TreeNode *, int> ll, rr;
            return isValidBST(root, ll, rr);
        }
        bool isValidBST(TreeNode *root, map<TreeNode *, int> &maxi, map<TreeNode *, int> &mini)
        {
            if(root == NULL)return true;

            TreeNode *ll = root->left;
            TreeNode *rr = root->right;

            if(ll != NULL && root->val <= ll->val)return false;

            if(rr != NULL && root->val >= rr->val)return false;

            if(!isValidBST(ll, maxi, mini))return false;

            if(!isValidBST(rr, maxi, mini))return false;

            if(ll != NULL && maxi.find(ll)->second >= root->val
                    || rr != NULL && mini.find(rr)->second <= root->val
              )return false;

            int min_val = root->val;
            int max_val = root->val;

            if(ll)
            {
                min_val = min(min_val, mini.find(ll)->second);
                max_val = max(max_val, maxi.find(ll)->second);
            }

            if(rr)
            {
                min_val = min(min_val, mini.find(rr)->second);
                max_val = max(max_val, maxi.find(rr)->second);
            }

            mini.insert(make_pair(root, min_val));
            maxi.insert(make_pair(root, max_val));
            return true;
        }
};
