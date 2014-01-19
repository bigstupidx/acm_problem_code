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
        vector<int> inorderTraversal(TreeNode *root)
        {
            stack<TreeNode *> st;
            stack<int> state;

            if(root)
            {
                st.push(root);
                state.push(0);
            }

            vector<int> ans;

            while(!st.empty())
            {
                TreeNode *node = st.top();
                int node_state = state.top();

                if(node_state == 0)
                {
                    state.pop();
                    state.push(1);

                    if(node->left != NULL)
                    {
                        st.push(node->left);
                        state.push(0);
                    }
                }
                else if(node_state == 1)
                {
                    ans.push_back(node->val);
                    state.pop();
                    state.push(2);
                }
                else
                {
                    state.pop();
                    st.pop();

                    if(node->right)
                    {
                        st.push(node->right);
                        state.push(0);
                    }
                }
            }

            return ans;
        }
};
