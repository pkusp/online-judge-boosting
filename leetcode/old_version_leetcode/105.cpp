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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	return recursiveBuild(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }

    TreeNode* recursiveBuild(vector<int>& preorder,vector<int> inorder, int pleft,int pright,int ileft,int iright){
    	if(pleft>pright||ileft>iright) return NULL;
    	TreeNode* cur = new TreeNode(preorder[pleft]);
    	int index = ileft;
    	while(preorder[pleft]!=inorder[index]){
    		index++;
    	}
    	cur->left = recursiveBuild(preorder,inorder,pleft+1,pleft+index-ileft,ileft,index-1);
    	cur->right = recursiveBuild(preorder,inorder,pright-(iright-index)+1,pright,index+1,iright);
    	return cur;
    }
};