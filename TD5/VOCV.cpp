#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;

#define MAXN 100002
#define MOD 10007

int t,n;
int par[MAXN];
int dp[MAXN][2], ways[MAXN][2];
bool visit[MAXN], leaf[MAXN];
vector<int> g[MAXN];
queue<int> q;

int sol1(int v,int st){
	if(dp[v][st] != -1) return dp[v][st];

	if(leaf[v]){
		if(st == 0) return dp[v][st] = 0;
		else return dp[v][st] = 1;
	}

	if(st == 0){
		dp[v][st] = 0;
		rep(i,0,(int)g[v].size() - 1){
			if(g[v][i] != par[v]) dp[v][st] += sol1(g[v][i],1);
		}
		return dp[v][st];
	}
	else{
		dp[v][st] = 1;
		rep(i,0,(int)g[v].size() - 1){
			if(g[v][i] != par[v]) dp[v][st] += min(sol1(g[v][i],0) , sol1(g[v][i],1));
		}
		return dp[v][st];	
	}
}

int sol2(int v, int st){
	if(ways[v][st] != -1) return ways[v][st];

	if(leaf[v]) return ways[v][st] = 1;

	if(st == 0){
		ways[v][st] = 1;
		rep(i,0,(int)g[v].size() - 1){
			if(g[v][i] != par[v]) ways[v][st] = (ways[v][st]*sol2(g[v][i],1))%MOD; 
		}
		return ways[v][st];
	}
	else{
		ways[v][st] = 1;
		rep(i,0,(int)g[v].size() - 1){
			if(g[v][i] != par[v]){
				if(dp[g[v][i]][0] == dp[g[v][i]][1]) ways[v][st] = (ways[v][st]*(sol2(g[v][i],0) + sol2(g[v][i],1)))%MOD;
				else if(dp[g[v][i]][0] < dp[g[v][i]][1]) ways[v][st] = (ways[v][st]*sol2(g[v][i],0))%MOD;
				else ways[v][st] = (ways[v][st]*sol2(g[v][i],1))%MOD;
			}
		}
		return ways[v][st];
	}
}

int main(){
fio

cin >> t;

while(t--){
cin >> n;

int u,v;
rep(i,1,n-1){
	cin >> u >> v;
	g[u].push_back(v);
	g[v].push_back(u);
}

memset(dp,-1,sizeof(dp));
memset(ways,-1,sizeof(ways));

visit[1] = true;
q.push(1);

int cur;
while(!q.empty()){
	cur = q.front();
	q.pop();

	bool entry = false;
	rep(i,0,(int)g[cur].size() - 1){
		if(!visit[g[cur][i]]){
			par[g[cur][i]] = cur;
			visit[g[cur][i]] = true;
			q.push(g[cur][i]);
			entry = true;
		}
	}

	if(!entry) leaf[cur] = true;
}

int ans1, ans2;

if(sol1(1,0) == sol1(1,1)){
	ans1 = sol1(1,0);
	ans2 = (sol2(1,0) + sol2(1,1))%MOD;
}
else if(sol1(1,0) < sol1(1,1)){
	ans1 = sol1(1,0);
	ans2 = sol2(1,0)%MOD;
}
else{
	ans1 = sol1(1,1);
	ans2 = sol2(1,1)%MOD;
}

cout << ans1 << " " << ans2 << endl;

rep(i,1,n){
	g[i].clear();
	visit[i] = false;
	leaf[i] = false;
	par[i] = 0;
} 
}
return 0;
}