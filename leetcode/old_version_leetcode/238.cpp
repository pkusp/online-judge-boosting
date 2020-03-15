class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {  // many vectors
    	vector<int> forward(nums.size(),1),backward(nums.size(),1),res;

    	for(int i=0;i<nums.size()-1;++i){
    		forward[i+1]=forward[i]*nums[i];
    	}
    	for(int j=nums.size()-1;j>0;--j){
    		backward[j-1]=backward[j]*nums[j];
    	}

    	for(int k=0;k<nums.size();++k){
    		res.push_back(forward[k]*backward[k]);
    	}
    	return res;
        
    }
};