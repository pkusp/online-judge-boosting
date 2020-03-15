class Solution {//2018.09.23
public:
    int lengthOfLIS(vector<int>& nums) {
    	int res = 0;
        if(nums.empty()) return res;
        vector<int> state(nums.size(),1);
        for(int i=0;i<nums.size();++i){
        	for(int j=0;j<i;++j){
        		if(nums[i]>nums[j]){
        			state[i] = max(state[i],state[j]+1);
        		}
        	}
        }
        for(int k=nums.size()-1;k>=0;--k){
        	if(state[k]>res) res = state[k];
        }
        return res;
    }
};