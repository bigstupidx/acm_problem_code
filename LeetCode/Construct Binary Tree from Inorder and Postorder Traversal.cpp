
class Solution
{
    private:
        TreeNode *build(vector<int> &inorder, vector<int> &postorder, int i1, int i2, int j1, int j2)
        {
            if(i2 < i1)return NULL;
            int val = postorder[j2], index;
            TreeNode *root = new TreeNode(val);
            for(int i = i1; i <= i2; i++)
            {
                if(inorder[i] == val)
                {
                    index = i;
                    break;
                }
            }
            root->left = build(inorder, postorder, i1, index - 1, j1, j1 + index - i1 - 1);
            root->right = build(inorder, postorder, index + 1, i2, j1 + index - i1, j2 - 1);
            return root;
        }
    public:
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
        {
            int size = inorder.size();
            return build(inorder, postorder, 0, size - 1, 0, size - 1);
        }
};
