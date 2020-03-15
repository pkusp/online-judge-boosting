// ac
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    	int res=0;
        map<int,int> mp1,mp2;
        for(int i=0;i<A.size();++i){
            for(int j=0;j<B.size();++j){
                mp1[A[i]+B[j]]+=1;
            }
        }

        for(int k=0;k<C.size();++k){
        	for(int m=0;m<D.size();++m){
        		mp2[C[k]+D[m]]+=1;
        	}
        }

        for(auto mp:mp1){
        	if(mp2.find(0-mp.first)!=mp2.end()){
        		res=res+mp.second*mp2[-mp.first];
        	}
        }
        return res;
        
    }
};