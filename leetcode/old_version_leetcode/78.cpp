class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector< vector<int> > res;
    	vector<int> out;
    	dfs_search(nums,res,out,0);
    	return res;
    }

    void dfs_search(vector<int> &nums,vector< vector<int> > &res,vector<int> &out,int pos){
    	res.push_back(out);
    	for(int i=pos;i<nums.size();++i){
    		out.push_back(nums[i]);
    		dfs_search(nums,res,out,pos+1);
    	}
    }

};