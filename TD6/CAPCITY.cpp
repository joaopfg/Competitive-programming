#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 100002

int n,m,comps;
int comp[MAXN], inDeg[MAXN];
bool visit[MAXN];
vector<int> g[MAXN], gt[MAXN];
vector<int> incTout;

void dfsG(int v){
	visit[v] = true;

	rep(i,0,(int)g[v].size() - 1){
		if(!visit[g[v][i]]) dfsG(g[v][i]);
	}

	incTout.push_back(v);
}

void dfsGt(int v){
	visit[v] = true;
	comp[v] = comps;

	rep(i,0,(int)gt[v].size() - 1){
		if(!visit[gt[v][i]]) dfsGt(gt[v][i]);
	}
}

int main(){
fio

cin >> n >> m;

int a,b;
rep(i,1,m){
	cin >> a >> b;
	g[b].push_back(a);
	gt[a].push_back(b);
}

rep(i,1,n){
	if(!visit[i]) dfsG(i);
}

memset(visit,false,sizeof(visit));

repi(i,(int)incTout.size() - 1,0){
	if(!visit[incTout[i]]){
		comps++;
		dfsGt(incTout[i]);
	}
}

rep(i,1,n){
	rep(j,0,(int)g[i].size() - 1){
		if(comp[i] != comp[g[i][j]]) inDeg[comp[g[i][j]]]++;
	}
}

int isZero = 0;
rep(i,1,comps){
	if(inDeg[i] == 0) isZero++;
}

if(isZero != 1) cout << "0" << endl;
else{
	vector<int> caps;

	rep(i,1,n){
		if(inDeg[comp[i]] == 0) caps.push_back(i); 
	}

	cout << (int)caps.size() << endl;
	rep(i,0,(int)caps.size() - 1) cout << caps[i] << " ";
	cout << endl;
}
return 0;
}