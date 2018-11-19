class Solution {
public:
    vector<int> countBits(int num) {
    	vector<int> dp(num+1);
    	for(int i=1;i<num+1;++i){
    		dp[i]=dp[i&(i-1)]+1;
    	}
    	return dp;
    }

};