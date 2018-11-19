class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> res;
    	stack<char> st;
    	char init='(';
    	dfs(init,"(",n-1,n,res);
    	return res;
    }

    void dfs(char c,string s,int left,int right,vector<string> &res){
    	if(left==0&&right==0){
    		res.push_back(s);
    	}else if(left<0||right<0){
    		cout<<s<<endl;
    		return;
    	}
    	if(left>right) return;
    	dfs('(',s+'(',left-1,right,res);
    	dfs(')',s+')',left,right-1,res);
    }
};