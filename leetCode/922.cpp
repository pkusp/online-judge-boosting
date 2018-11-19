class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
    	int left=0,right=A.size()-1;
    	if((A.size()-1)%2==0) right-=1;
    	while(left<A.size()&&right>=0){
    		while(right>0&&A[right]%2!=0) right-=2;
    		if(A[left]%2!=0){
    			swap(A[left],A[right]);
    		}
    		left+=2;
    	}
    	return A;
        
    }
};