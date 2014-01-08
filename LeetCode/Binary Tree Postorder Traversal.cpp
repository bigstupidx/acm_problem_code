/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;
 
struct TreeNode{
		int val;
		TreeNode *left, *right;
		TreeNode(int x):val(x), left(NULL), right(NULL){}
};
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
		if(root==NULL)return ans;
		stack<TreeNode*> st;
		stack<int> state;
		st.push(root);
		state.push(1);
		while(!st.empty()){
			TreeNode *top = st.top();
			int top_state = state.top();
			
			if(top_state==1){
				if(top->left!=NULL){
					st.push(top->left);
					state.pop();
					state.push(2);
					state.push(1);
				}else{
					top_state = 2;
				}
			} 
			if(top_state==2){
				if(top->right!=NULL){
					st.push(top->right);
					state.pop();
					state.push(3);
					state.push(1);
				}else{
					top_state = 3;
				}
			}
			
			if(top_state ==3){
				st.pop();
				state.pop();
				ans.push_back(top->val);
			}
		}
		return ans;
    }
};
