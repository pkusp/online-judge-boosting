/*
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
*/

class Solution { // dp 
public:
    string longestPalindrome(string s) {
   	if(s.size()==0) return "";

	int max_len = 0,left=0,right=0;
	int dp[s.size()][s.size()]={0};

	for(int i=0;i<s.size();++i){
		for(int j=0;j<i;++j){
			dp[i][j] = (s[i]==s[j]&&(i-j<2||dp[i-1][j+1]));
			// cout<<j<<" "<<i<<" "<<dp[j][i]<<endl;
			if(dp[j][i]&&max_len<i-j+1){
				left = j;
				right = i;
				max_len = i-j+1;
			}
		}
		dp[i][i]=1;

	}
	// cout<<left<<"\t"<<right<<endl;
	return s.substr(left,right-left+1);
  
    }


};

int main(){
	Solution so;
	string sinput = "aaaa",res;
	res= so.longestPalindrome(sinput);
	for(int i=0;i<res.size();++i){
		cout<<res[i];
	}



}