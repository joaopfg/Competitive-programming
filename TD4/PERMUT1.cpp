#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 13
#define MAXK 99

int cases;
int dp[MAXN][MAXK];

int sol(int n ,int k){
if(dp[n][k] != -1) return dp[n][k];

if(k == 0) return dp[n][k] = 1;
if(n == 1) return dp[n][k] = 0;

dp[n][k] = 0;

int left = max(0 , k-n+1);
int right = min(k , ((n-1)*(n-2))/2);

rep(i,left,right) dp[n][k] += sol(n-1,i);

return dp[n][k];
}

int main(){
fio

cin >> cases;

while(cases--){
	int n, k;

	cin >> n >> k;

	memset(dp,-1,sizeof(dp));
	
	cout << sol(n,k) << endl;
}
return 0;
}