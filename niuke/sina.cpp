#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int LCS(string s1,string s2){
	// if(s1.empty()||s2.empty()) return 0;
	int res=0;
	int m=s1.size(),n=s2.size();
	vector< vector<int> > state;
	for(int i=0;i<m;++i){
		state[0][i]=0;
	}
	for(int j=0;j<n;++j){
		state[j][0]=0;
	}

	for(int i=0;i<m-1;++i){
		for(int j=0;j<n-1;++j){
			if(s1[i]==s2[j]){
				state[i+1][j+1]=state[i][j]+1;
			}else{
				state[i+1][j+1]=max(state[i][j+1],state[i+1][j]);
			}
		}
	}
	res=state[m-1][n-1];
	return res;
}



int main(){

cout<<"hello world!"<<endl;
string s1,s2;
cin>>s1>>s2;
int res =LCS(s1,s2);
cout<<res<<endl;
}