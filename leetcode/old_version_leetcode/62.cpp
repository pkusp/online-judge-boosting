/*
vector<vector<int> > array(m); //这个m一定不能少
//初始化一个m*n的二维数组
for(int i=0;i<m;i++) {
    array[i].resize(n);
}
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
    	if(m==0||n==0) return 0;
    	vector< vector<int> > dp(10);

    	for(int i=0;i<10;++i){
    		dp[i].resize(10);
    	}

    	for(int i=0;i<10;++i){
    		for(int j=0;j<10;++j){
    			cout<<dp[i]<<" ";
    		}
    		cout<<endl;
    	}
    	return 0;
        
    }
};

int main(){
	Solution ss;
	int res = ss.uniquePaths(10,10);
}