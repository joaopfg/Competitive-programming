#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 10002
#define RED 0
#define BLUE 1
#define GREEN 2

int t, pos, node, sz;
int dp[MAXN][3];
string s;

void dfs(vector<int> (&g)[MAXN]){
	if(s[pos] == '1'){
		g[node].push_back(node+1);
		//g[node+1].push_back(node);
		node++;
		pos++;
		dfs(g);
	}
	else if(s[pos] == '2'){
		g[node].push_back(node+1);
		//g[node+1].push_back(node);
		int cur = node;
		node++;
		pos++;
		dfs(g);
		g[cur].push_back(node+1);
		//g[node+1].push_back(cur);
		node++;
		pos++;
		dfs(g);
	}
}

int solMax(int v, int color, vector<int> (&g)[MAXN]){
	if(dp[v][color] != -1) return dp[v][color];

	int vsz = g[v].size();

	if(vsz == 0){
		if(color == RED || color == BLUE) return dp[v][color] = 0;
		else return dp[v][color] = 1;
	}
	else if(vsz == 1){
		int c = g[v][0];

		if(color == RED) return dp[v][color] = max(solMax(c,BLUE,g), solMax(c,GREEN,g));
		else if(color == BLUE) return dp[v][color] = max(solMax(c,RED,g), solMax(c,GREEN,g));
		else return dp[v][color] = 1+max(solMax(c,RED,g), solMax(c,BLUE,g));
	}
	else{
		int c1 = g[v][0];
		int c2 = g[v][1];

		if(color == RED) return dp[v][color] = max(solMax(c1,BLUE,g) + solMax(c2,GREEN,g), solMax(c1,GREEN,g) + solMax(c2,BLUE,g));
		else if(color == BLUE) return dp[v][color] = max(solMax(c1,RED,g) + solMax(c2,GREEN,g), solMax(c1,GREEN,g) + solMax(c2,RED,g));
		else return dp[v][color] = 1+max(solMax(c1,RED,g) + solMax(c2,BLUE,g), solMax(c1,BLUE,g) + solMax(c2,RED,g));
	}
}

int solMin(int v, int color, vector<int> (&g)[MAXN]){
	if(dp[v][color] != -1) return dp[v][color];

	int vsz = g[v].size();

	if(vsz == 0){
		if(color == RED || color == BLUE) return dp[v][color] = 0;
		else return dp[v][color] = 1;
	}
	else if(vsz == 1){
		int c = g[v][0];

		if(color == RED) return dp[v][color] = min(solMin(c,BLUE,g), solMin(c,GREEN,g));
		else if(color == BLUE) return dp[v][color] = min(solMin(c,RED,g), solMin(c,GREEN,g));
		else return dp[v][color] = 1+min(solMin(c,RED,g), solMin(c,BLUE,g));
	}
	else{
		int c1 = g[v][0];
		int c2 = g[v][1];

		if(color == RED) return dp[v][color] = min(solMin(c1,BLUE,g) + solMin(c2,GREEN,g), solMin(c1,GREEN,g) + solMin(c2,BLUE,g));
		else if(color == BLUE) return dp[v][color] = min(solMin(c1,RED,g) + solMin(c2,GREEN,g), solMin(c1,GREEN,g) + solMin(c2,RED,g));
		else return dp[v][color] = 1+min(solMin(c1,RED,g) + solMin(c2,BLUE,g), solMin(c1,BLUE,g) + solMin(c2,RED,g));
	}
}

int main(){
fio

cin >> t;

while(t--){
	cin >> s;
	sz = (int)s.size();
	pos = 0;
	node = 1;
	vector<int> g[MAXN];
	dfs(g);
	memset(dp,-1,sizeof(dp));
	cout << max(max(solMax(1,RED,g),solMax(1,BLUE,g)),solMax(1,GREEN,g));
	memset(dp,-1,sizeof(dp));
	cout << " " << min(min(solMin(1,RED,g),solMin(1,BLUE,g)),solMin(1,GREEN,g)) << endl;
}
return 0;
}