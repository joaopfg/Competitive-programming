#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 100002

int n;
int par[MAXN];
int dp[MAXN][2];
bool visit[MAXN], leaf[MAXN];
vector<int> g[MAXN];
queue<int> q;

int sol(int v,int st){
	if(dp[v][st] != -1) return dp[v][st];

	if(leaf[v]){
		if(st == 0) return dp[v][st] = 0;
		else return dp[v][st] = 1;
	}

	if(st == 0){
		dp[v][st] = 0;
		rep(i,0,(int)g[v].size() - 1){
			if(g[v][i] != par[v]) dp[v][st] += sol(g[v][i],1);
		}
		return dp[v][st];
	}
	else{
		dp[v][st] = 1;
		rep(i,0,(int)g[v].size() - 1){
			if(g[v][i] != par[v]) dp[v][st] += min(sol(g[v][i],0) , sol(g[v][i],1));
		}
		return dp[v][st];	
	}
}

int main(){
fio

cin >> n;

int u,v;
rep(i,1,n-1){
	cin >> u >> v;
	g[u].push_back(v);
	g[v].push_back(u);
}

memset(dp,-1,sizeof(dp));

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

cout << min(sol(1,0) , sol(1,1)) << endl;
return 0;
}