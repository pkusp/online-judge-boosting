class Solution {
public:
    int calculate(string s) {
    	char op = '+';
    	int tmp = 0,res=0;
    	stack<int> st;
    	for(int i=0;i<s.size();++i){
    		if(s[i]>='0'&&s[i]<='9'){
    			tmp = tmp*10 + s[i]-'0';
    		}
    		if((s[i]<'0'&&s[i]!=' ')||i==s.size()-1){
    			int t=0;
    			switch(op){
    				case '+':
    					st.push(tmp);
    					cout<<"+:"<<tmp<<'\t';
    					break;

    				case '-':
    					st.push(0-tmp);
    					cout<<"-:"<<0-tmp<<'\t';
    					break;
    				case '*':
    					t = st.top();st.pop();
    					cout<<"*:"<<tmp<<'\t';
    					st.push(t*tmp);
    					break;
    				case '/':
    					t = st.top();st.pop();
    					cout<<"/:"<<tmp<<'\t';
    					st.push(t/tmp);
    					break;
    			}
    			if(i!=s.size()-1) op=s[i];
    			tmp = 0;


    		}
    	}
    	while(!st.empty()){
    		cout<<st.top()<<endl;
    		res+=st.top();st.pop();
    	}
    	return res;
    }
};