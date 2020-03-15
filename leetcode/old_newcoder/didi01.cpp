#include<bits/stdc++.h>
// #define IL inline
#define N 1000 
using namespace std;
const int mod = 1000000007 ; 
int dp[10*N],C[N+5][N+5],E[N+5][N+5],fact[N+5],a[N+5],n,sum,ans;
int inv[N+5],inv_fact[N+5],coef[N+5]; 

void Process(){
    C[0][0] = 1;
    for( int i = 1,j; i <= N; i ++)
        for(j = C[i][0] = 1; j <= i; j ++)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod ;
    for( int i = 1,e; i <= N; i ++)
        for( int j = i,e = 1; j >= 1; j --)
            E[i][j] = (mod + C[i-1][j-1] * e) % mod, e = -e ;
    fact[0] = inv[0] = 1 ;
    inv[1] = inv_fact[0] = 1 ;
    for(int i = 1; i <= N; i ++){
        fact[i] = 1ll * i * fact[i-1] % mod;
        if(i ^ 1)inv[i] = 1ll * (mod - mod/i) * inv[mod % i] % mod;
        inv_fact[i] = 1ll * inv_fact[i-1] * inv[i] % mod ; 
    }return ; 
}

void optimize(int &x,int y){
    x += y; if(x>=mod) x-= mod ; 
}

int main(){
    Process() ;
    sum = 0; dp[0] = 1 ;
    for(int i = 1; i <= N; i ++) dp[i] = 0;
    for(int index = 1; index <= 3; index ++){
        scanf("%d",&a[index]) ;  
        for(int k = 1; k <= a[index]; k ++)
            coef[k] = 1ll * E[a[index]][k] * inv_fact[k] % mod ;
        for(int j = sum; j >= 0; j --){
            int tmp = dp[j] ;
            dp[j] = 0;
            for(int k = 0; k <= a[index]; k ++)
                optimize(dp[j + k] , 1ll * coef[k] * tmp % mod) ; 
        }
        sum += a[index];  
    }
    ans = 0;
    for(int k = 0; k <= sum; k ++) optimize(ans , 1ll * dp[k] * fact[k] % mod) ;
    printf("%d\n" , ans) ;  return 0;
}