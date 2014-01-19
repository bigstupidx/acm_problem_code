class Solution
{
    public:
        void connect(TreeLinkNode *root)
        {
            vector<TreeLinkNode *> Q[2];
            int now = 0;

            if(root != NULL)
            {
                Q[0].push_back(root);
            }

            do
            {
                Q[1 - now].clear();
                Q[1 - now].reserve(0);

                for(int i = 0, n = Q[now].size(); i < n; i++)
                {
                    if(i > 0)
                        Q[now][i - 1]->next = Q[now][i];

                    TreeLinkNode *item = Q[now][i];

                    if(item->left)Q[1 - now].push_back(item->left);

                    if(item->right)Q[1 - now].push_back(item->right);
                }

                if(Q[1 - now].size() == 0)break;

                now = 1 - now;
            }
            while(true);
        }
};
