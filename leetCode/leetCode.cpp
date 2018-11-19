#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int foodSort(int n,int m,int p,vector<int> food,queue<char> trad,queue<int> numbe){
	while(!trad.empty()&&!numbe.empty()){
		char tra=trad.front();trad.pop();
		int num=numbe.front();numbe.pop();
		cout<<" trade："<<tra<<num<<endl;
		if(tra=='A'){
			food[num]+=1;
		}else{
			food[num]-=1;
		}
		cout<<"foods::"<<num<<" "<<food[num-1]<<endl;
	}
	int resAmount=food[p];
	cout<<"p:"<<p<<endl;
	cout<<"res amount:"<<resAmount<<endl;
	sort(food.begin(),food.end());
	int cnt=1;
	for(int i=1;i<food.size();++i){
		cout<<"foods i:"<<food[i]<<endl;
		if(food[i]!=food[i-1]){
			cnt++;
		}
		if(food[i]==resAmount) break;

	}
	return cnt;
}


int main(){

cout<<"hello world!"<<endl;
int n,m,p,res;
int foo;
char ab;
int num;
cin>>n>>m>>p;
vector<int> foods(n+1);
queue<char> trade;
queue<int> number;
for(int i=0;i<n;++i){
	cin>>foo;
	cout<<"food"<<i<<" "<<foo<<endl;
	foods.push_back(foo);
}
for(int j=0;j<m;++j){
	cin>>ab;
	cin>> num;
	trade.push(ab);
	number.push(num-1);
	// cout<<ab<<" "<<num<<endl;
}
res=foodSort(n,m,p-1,foods,trade,number);
cout<<res<<endl;
}
