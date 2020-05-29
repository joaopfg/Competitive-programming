#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 2002

int dp[MAXN][MAXN];
int sz[MAXN], v[MAXN]; 

int sol(int n, int s){
	if(dp[n][s] != -1) return dp[n][s];

	if(n == 0 || s == 0) return dp[n][s] = 0;

	dp[n][s] = -1;
	dp[n][s] = max(dp[n][s] , sol(n-1,s));

	if(sz[n] <= s) dp[n][s] = max(dp[n][s] , v[n] + sol(n-1,s-sz[n]));

	return dp[n][s];
}

int main(){
fio

int s,n;

cin >> s >> n;

rep(i,1,n) cin >> sz[i] >> v[i];

memset(dp,-1,sizeof(dp));

cout << sol(n,s) << endl;
return 0;
}