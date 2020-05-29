#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef pair<int,int> ii;

#define MAXN 102
#define MAXB (int)((1 << 12) - 1)

const int INF = 1000000009;

int cases, n, m, b, z, order;
int dp[MAXN][MAXB], w[MAXN][MAXN];
vector<ii> ord;

int sol(int city, int mask){
	if(dp[city][mask] != -1) return dp[city][mask];

	if(mask == (1 << order) - 1) return dp[city][mask] = w[city][b];

	int Min = -1;

	rep(i,0,order-1){
		if(!((1 << i) & mask)){
			int newMask = mask ^ (1 << i);
			int from = ord[i].first;
			int to = ord[i].second;

			if(Min == -1 || sol(to,newMask) + w[city][from] + w[from][to] < Min) Min = sol(to,newMask) + w[city][from] + w[from][to];
		}
	}

	return dp[city][mask] = Min;
}

int main(){
fio

cin >> cases;

while(cases--){
	cin >> n >> m >> b;

	rep(i,1,n){
		rep(j,1,n) w[i][j] = INF;
	}

	rep(i,1,n) w[i][i] = 0;

	int u,v,d;
	rep(i,1,m){
		cin >> u >> v >> d;
		w[u][v] = d;
		w[v][u] = d;
	}

	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				w[i][j] = min(w[i][j] , w[i][k] + w[k][j]);
			}
		}
	}

	cin >> z;

	order = 0;

	rep(i,1,z){
		cin >> u >> v >> d;
		order += d;
		rep(j,1,d) ord.push_back(make_pair(u,v));
	}

	memset(dp,-1,sizeof(dp));

    cout << sol(b,0) << endl;

    ord.clear();
}
return 0;
}