#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long int ll;

#define MAXN 21
#define MAX (int)(1 << 20)

int cases, n;
bool assignemnts[MAXN][MAXN];
ll dp[MAX];

ll sol(int mask){
	if(dp[mask] != -1) return dp[mask];

	int stud = __builtin_popcount(mask);

	if(stud == n) return dp[mask] = 1;

	dp[mask] = 0;

	rep(i,1,n){
		if(!(mask & (1 << (i-1))) && assignemnts[stud+1][i]) dp[mask] += sol(mask ^ (1 << (i-1)));
	}

	return dp[mask];
}

int main(){
fio

cin >> cases;

while(cases--){
	cin >> n;

	int a;

	rep(i,1,n){
		rep(j,1,n){
			cin >> a;

			if(a == 0) assignemnts[i][j] = false;
			else assignemnts[i][j] = true;
		}
	}

	memset(dp,-1,sizeof(dp));

	cout << sol(0) << endl;
}
return 0;
}