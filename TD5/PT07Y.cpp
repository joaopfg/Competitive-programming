#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 10002

int n,m;
bool visit[MAXN];
vector<int> g[MAXN];

void dfs(int v){
	visit[v] = true;

	rep(i,0,(int)g[v].size() - 1){
		if(!visit[g[v][i]]) dfs(g[v][i]);
	}
}

int main(){
fio

bool tree = true;

cin >> n >> m;

if(n != (m+1)) tree = false;
else{
int u,v;
rep(i,1,m){
	cin >> u >> v;
	g[u].push_back(v);
	g[v].push_back(u);
}

visit[1] = true;
dfs(1);
rep(i,2,n){
	if(!visit[i]){
		tree = false;
		break;
	} 
}	
}

if(tree) cout << "YES" << endl;
else cout << "NO" << endl;
return 0;
}