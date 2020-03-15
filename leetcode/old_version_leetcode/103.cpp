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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;

        while(!q.empty()){
        	int qsize = q.size();
        	vector<int> oneLevel;
        	for(int i=0;i<qsize;++i){
        		TreeNode* tmp = q.front();q.pop();
        		oneLevel.push_back(tmp->val);
        		if(tmp->left) q.push(tmp->left);
        		if(tmp->right) q.push(tmp->right);

        	}
        	if(flag){
        		res.push_back(oneLevel);
        		flag=false;
        	}
        	else{
        		vector<int> zig;
        		for(int j=oneLevel.size()-1;j>=0;--j){
        			zig.push_back(oneLevel[j]);
        		}
        		res.push_back(zig);
        		flag=true;
        	}

        }

        return res;

    }
};