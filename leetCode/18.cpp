#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector< vector<int> > res;

        if(nums.back()<target||nums.size()<4) return res;
        // map<int,int> mp;
        // for(int i=0;i<nums.size();++i){
        // 	mp[nums[i]]+=1;
        // }
        for(int i=0;i<nums.size();++i){
        	// mp[nums[i]]-=1;
        	for(int j=nums.size()-1;j>3;--j){
        		// mp[nums[j]]-=1;
        		int k=i+1,m=j-1;
        		int tmp_target=target-nums[i]-nums[j];
        		while(k<m){
        			if(nums[k]+nums[m]==tmp_target){
        				res.push_back({nums[i],nums[k],nums[m],nums[j]});

        			}else if(nums[k]+nums[m]<tmp_target) k++;
        			else m--;
        		}
        	}
        }
        return res;

    	}
	};

int main(){
	Solution s;
}