#include <bits/stdc++.h>
#define maxn 1005
using namespace std;

int n, k, dp[maxn][maxn*10];

void Dp(int n, int k)
{
    int a;
    memset(dp, 0, sizeof dp);
    for(int i = 0; i != k+1; ++i)
    {
        dp[1][i] = 1;
    }
    for(int i = 2; i != n+1; ++i)
    {
        dp[i][0] = 1;
        for(int j = 1; j != k+1; ++j)
        {
            if(j-i > -1)    a = dp[i-1][j-i];
            else a = 0; 
            dp[i][j] = (dp[i][j-1]+dp[i-1][j]-a);
        }
    }
    return ;
}

int main()
{
  cin>>n>>k;
  Dp(n, k);

  cout<<dp[n][k]-dp[n][k]-1]];
  return 0;
}

