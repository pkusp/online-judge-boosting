// class Solution {
// public:
//     bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

//     	vector< vector<int> > graph(numCourses,vector<int> (0));
//     	vector<int> in(numCourses,0);
//     	for(auto a:prerequisites){
//     		graph[a.second].push_back(a.first);
//     		++in[a.first];
//     	}

//     	queue<int> q;
//     	for(int i=0;i<numCourses;++i){
//     		if(in[i]==0) q.push(i);
//     	}

//     	while(!q.empty()){
//     		int t=q.front();
//     		q.pop();
//     		for(auto a:graph[t]){
//     			--in[a];
//     			if(in[a]==0) q.push(a);
//     		}
//     	}
//     	for(int i=0;i<numCourses;++i){
//     		if(in[i]!=0) return false;
//     	}
//     	return true;
//     }
// };

// class Solution{
// public:
// 	    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
// 	    	vector< vector<int> > graph(numCourses,vector<int> (0));
// 	    	vector<int> gin(numCourses);

// 	    	for(auto a:prerequisites){
// 	    		int left=a.first,right=a.second;
// 	    		gin[right]++;
// 	    		graph[left].push_back(right);
// 	    	}
// 	    	queue<int> q;
// 	    	for(int i=0;i<gin.size();++i){
// 	    		if(gin[i]==0){
// 	    			q.push(i);
// 	    		}
// 	    	}
// 	    	while(!q.empty()){
// 	    		int top = q.front();q.pop();
// 	    		for(auto a:graph[top]){
// 	    			gin[a]--;
// 	    			if(gin[a]==0){
// 	    				q.push(a);
// 	    			}
// 	    		}
// 	    	}
// 	    	for(auto a:gin){
// 	    		if(a!=0) return false;
// 	    	}
// 	    	return true;
// 	    }
// };

class Solution{
public:
		bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
			vector<int> visit;
			vector< vector<int> > graph(numCourses,vector<int> (0));
			for(auto a:prerequisites){
				graph[a.first].push_back(a.second);
			}
			for(int i=0;i<numCourses;++i){
				if(dfs(graph,visit,i)){
					
				}
			}


		    }

		bool dfs(vector< vector<int> > &graph, vector<int> visit,int i){
			visit[i] = 1;




		}

};








