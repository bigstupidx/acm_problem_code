
class Solution
{
    public:
        void flatten(TreeNode *root)
        {
            stack<TreeNode *> st;
            stack<int> state;

            if(root)
            {
                st.push(root);
                state.push(0);
            }

            vector<TreeNode *> node;

            while(!st.empty())
            {
                TreeNode *child = st.top();
                int child_state = state.top();

                if(child_state == 0)
                {
                    node.push_back(child);
                    state.pop();
                    state.push(1);

                    if(child->left != NULL)
                    {
                        st.push(child->left);
                        state.push(0);
                    }
                }
                else if(child_state == 1)
                {
                    state.pop();
                    state.push(2);

                    if(child->right != NULL)
                    {
                        st.push(child->right);
                        state.push(0);
                    }
                }
                else
                {
                    state.pop();
                    st.pop();
                }
            }

            int n = node.size();

            for(int i = 0; i < n; i++)node[i]->left = node[i]->right = NULL;

            --n;

            for(int i = 0; i < n; i++)
            {
                node[i]->right = node[i + 1];
            }

            root = (n == -1 ? NULL : node[0]);
        }
};
