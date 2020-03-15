/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int> > res;
    	if(!root) return res;
    	queue<TreeNode*> q;
    	q.push(root);
    	while(!q.empty()){
    		int qsize = q.size();
    		vector<int> oneLevel;
    		for(int i =0;i<qsize;++i){
    			TreeNode* tmp = q.front();q.pop();
    			oneLevel.push_back(tmp->val);
    			if(tmp->left) q.push(tmp->left);
    			if(tmp->right) q.push(tmp->right);
    		}
    		res.push_back(oneLevel);
    	}
    	return res;
    }
};