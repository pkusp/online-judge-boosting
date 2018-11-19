class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> visit(nums.size(),0);
        vector<int> tmp;
        dfs(0,nums,tmp,visit,res);
        return res;
    }

    void dfs(int level,vector<int> &nums,vector<int> &tmp,vector<int> &visit,vector< vector<int> > &res){
  		if(level==nums.size()) res.push_back(tmp);
  		else{
  			for(int i=0;i<nums.size();++i){
  				if(!visit[i]){
  					visit[i]=1;
  					tmp.push_back(nums[i]);
  					dfs(level+1,nums,tmp,visit,res);
  					tmp.pop_back();
  					visit[i]=0;
  				}
  			}
  		}
   
    }


};