#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 10002

int n;
int d[MAXN];
bool visit[MAXN];
vector<int> g[MAXN];

void dfs(int v){
	visit[v] = true;

	rep(i,0,(int)g[v].size() - 1){
		if(!visit[g[v][i]]){
			d[g[v][i]] = d[v] + 1;
			dfs(g[v][i]);
		}
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

dfs(1);

int maxDist = -1;
int vMax;

rep(i,1,n){
	if(d[i] > maxDist){
		maxDist = d[i];
		vMax = i;
	}
}

memset(visit,false,sizeof(visit));
memset(d,0,sizeof(d));

dfs(vMax);

maxDist = -1;

rep(i,1,n){
	if(d[i] > maxDist) maxDist = d[i];
}

cout << maxDist << endl;
return 0;
}