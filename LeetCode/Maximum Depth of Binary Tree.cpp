class Solution {
public:
	int maxDepth(TreeNode *root) {
		if (root == NULL)
			return 0;
		int ans = 0;
		int now = 0;
		vector<TreeNode*> Q[2];
		Q[0].push_back(root);
		do {
			Q[1 - now].clear();
			Q[1 - now].reserve(0);
			for (int i = 0, n = Q[now].size(); i < n; i++) {
				TreeNode* item = Q[now][i];
				if (item->left != NULL) {
					Q[1 - now].push_back(item->left);
				}
				if (item->right != NULL) {
					Q[1 - now].push_back(item->right);
				}
			}
			++ans;
			if (Q[1 - now].size() == 0)
				break;
			now = 1 - now;
		} while (true);
		return ans;
	}
};
