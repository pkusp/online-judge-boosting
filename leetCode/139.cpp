#include<vector>
#include<string>
#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    	map<string,int> dict;
    	for(int i=0;i<wordDict.size();++i){
    		dict[wordDict[i]]=1;
    	}
    	vector<int> dp(s.size(),0);
    	for(int i=0;i<s.size();++i){
    		for(int j=0;j<=i;++j){
    			if(j==0&&dict.find(s.substr(0,i+1))!=dict.end()) dp[i]=1;
    			else if(dp[j]==1 && dict.find(s.substr(j+1,i-j))!=dict.end()){
    				dp[i]=1;
    			}
    		}
    	}
    	for(int k=0;k<s.size();++k){
    		cout<<dp[k]<<"\t";
    	}
    	return dp[s.size()-1]==1?true:false;
        
    }
};


int main(){
	Solution ss;
	string s="a";
	vector<string> vec;
	vec.push_back("a");
	// vec.push_back("pen");
	bool f=ss.wordBreak(s,vec);
	cout<<" res :"<<f<<endl;

}