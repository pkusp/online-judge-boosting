class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {  // priority_queue, unordered_map, pair
    	vector<int> res;
    	unordered_map<int,int> mp;
    	priority_queue< pair<int,int> > q;
    	for(auto num:nums){
    		mp[num]++;
    	}
    	for(auto m:mp){
    		q.push({m.second,m.first});
    	}
    	for(int i=0;i<k;++i){
    		res.push_back(q.top().second);q.pop();
    	}
    	return res;
    }
};