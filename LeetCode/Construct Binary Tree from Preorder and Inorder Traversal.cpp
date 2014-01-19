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
    private:
        TreeNode *build(vector<int> &preorder, vector<int> &inorder, int i1, int i2, int j1, int j2)
        {
            if(i2 < i1)return NULL;
            int val = preorder[i1], index;
            TreeNode *root = new TreeNode(val);
            for(int i = j1; i <= j2; i++)
            {
                if(inorder[i] == val)
                {
                    index = i;
                    break;
                }
            }
            root->left = build(preorder, inorder, i1 + 1, i1 + index - j1, j1, index - 1);
            root->right = build(preorder, inorder,  i1 + 1 + index - j1, i2, index + 1, j2);
            return root;
        }
    public:
        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
        {
            int size = preorder.size();
            return build(preorder, inorder, 0, size - 1, 0, size - 1);
        }
};
