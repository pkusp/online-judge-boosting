// class Solution{
// public:
// 	int maxProduct(vector<int>& nums){
// 		if(nums.size()==0) return 0;
// 		int res=nums[0],n=nums.size();
// 		vector<int> maxDp(n,0),minDp(n,0);
// 		maxDp[0]=res;minDp[0]=res;
// 		for(int i=1;i<n;++i){
// 			maxDp[i] = max(nums[i],max(minDp[i-1]*nums[i],maxDp[i-1]*nums[i]));
// 			minDp[i] = min(nums[i],min(maxDp[i-1]*nums[i],minDp[i-1]*nums[i]));
// 			res = max(res,max(maxDp[i],minDp[i]));
// 		}
// 		return res;
// 	}
// };

class Solution{
public:
	int maxProduct(vector<int>& nums){
		if(nums.size()==0) return 0;
		int res = nums[0],n=nums.size();
		int maxMulti=res,minMulti=res,maxTmp,minTmp;
		for(int i=1;i<n;++i){
			maxTmp = max(nums[i],max(nums[i]*maxMulti,nums[i]*minMulti));
			minTmp = min(nums[i],min(nums[i]*minMulti,nums[i]*maxMulti));
			maxMulti = maxTmp;
			minMulti = minTmp;
			res = max(res,maxMulti);
		}
		return res;
	}

};
