#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 101

int cases,n,m;
int dp[MAXN][MAXN][MAXN];

int sol(int donuts, int player1, int player2){
	if(dp[donuts][player1][player2] != -1) return dp[donuts][player1][player2];

	if(donuts == 0){
		if(player1 == 0 && player2 == 0) return dp[donuts][player1][player2] = 0;
		return dp[donuts][player1][player2] = sol(player1,0,0);
	}

	int total = donuts + player1 + player2;
	dp[donuts][player1][player2] = 0;

	rep(i,1,min(donuts,m)) dp[donuts][player1][player2] = max(dp[donuts][player1][player2] , total - sol(donuts - i,player2,player1 + i));

	return dp[donuts][player1][player2];
}

int main(){
fio

cin >> cases;

while(cases--){
	cin >> n >> m;

	memset(dp,-1,sizeof(dp));

	cout << sol(n,0,0) << endl;
}
return 0;
}