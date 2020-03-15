class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size()==0) return res;
        map<int,int> mp;
        for(int i=0;i<nums.size();++i){
            int key = target-nums[i];
            if(mp.find(key)!=mp.end()){
                res.push_back(i);
                res.push_back(mp[key]);
            }
            else{
                mp[nums[i]]=i;
            }
        }
        return res;
    }
        
};