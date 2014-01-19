class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > ans;
		int now = 0;
		vector<TreeNode*> Q[2];
		Q[0].push_back(root);
		do {
			Q[1 - now].clear();
			Q[1 - now].reserve(0);
			vector<int> arr;
			for (int i = 0, n = Q[now].size(); i < n; i++) {
				TreeNode* item = Q[now][i];
				if (item == NULL)
					continue;
				arr.push_back(item->val);
				if (item->left != NULL) {
					Q[1 - now].push_back(item->left);
				}
				if (item->right != NULL) {
					Q[1 - now].push_back(item->right);
				}
			}
			if (arr.size() > 0)
				ans.push_back(arr);
			if (Q[1 - now].size() == 0)
				break;
			now = 1 - now;
		} while (true);
		return ans;
	}
};
