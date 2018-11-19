#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	if(coins.empty()) return -1;

    	vector<int> dp(amount+1,amount+1);
    	dp[0] = 0;
    	for(int i=1;i<=amount;++i){
    		for(int j=0;j<coins.size();++j){
    			cout<<i<<" "<<coins[j]<<"\t";
    			if(i-coins[j]>=0)
    				dp[i] = min(dp[i],dp[i-coins[j]]+1);
    		}
    	}
    	for(auto i:dp) cout<<i<<" ";
    	return dp[amount]==amount+1?-1:dp[amount];

    }
};

int main(){
	Solution ss;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(5);
	int am = 11;

	int res = ss.coinChange(nums,am);
}
