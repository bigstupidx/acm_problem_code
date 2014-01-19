/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    public:
        void solve(TreeNode *root, int sum, vector<vector<int>> &ans, vector<int> &path)
        {
            if(root == NULL)return ;

            //if(root->val > sum)return;

            path.push_back(root->val);

            if(root->left == NULL && root->right == NULL)
            {
                if(sum == root->val)
                {
                    vector<int>temp;
                    temp.reserve(path.size());

                    for(int i = 0, n = path.size(); i < n; i++)
                    {
                        temp.push_back(path[i]);
                    }

                    ans.push_back(temp);
                }

                path.pop_back();

                return ;
            }

            solve(root->left, sum - root->val, ans, path);
            solve(root->right, sum - root->val, ans, path);
            path.pop_back();
            return ;
        }

        vector<vector<int> > pathSum(TreeNode *root, int sum)
        {
            vector<vector<int> >ans;
            vector<int> path;
            solve(root, sum, ans, path);
            return ans;
        }
};
