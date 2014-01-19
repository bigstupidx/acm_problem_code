/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int sumNumbers(TreeNode *root) {
		// Note: The Solution object is instantiated only once and is reused by each test case.
		int ans = 0;
		dfs(root, 0, ans);
		return ans;
	}

	void dfs(TreeNode *p, int sum, int &total) {
		if (p == NULL)
			return;
		int path_sum = sum * 10 + p->val;
		if (p->left == NULL && p->right == NULL) {
			total += path_sum;
		}
		dfs(p->left, path_sum, total);
		dfs(p->right, path_sum, total);
	}
};
