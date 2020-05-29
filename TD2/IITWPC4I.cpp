#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<ll,ii> lp;

#define MAXN 100002

int cases;
int par[MAXN], w[MAXN];
bool hasMilk[MAXN];

int Find(int v){
	if(par[v] == v) return par[v];
	return par[v] = Find(par[v]);
}

void Union(int u, int v){
	u = Find(u);
	v = Find(v);

	if(w[u] < w[v]) par[u] = v;
	else if(w[u] > w[v]) par[v] = u;
	else{
		par[v] = u;
		w[u]++;
	}
}

int main(){
fio

cin >> cases;

while(cases--){
	int n,m;

	cin >> n >> m;

	int st;

	rep(i,1,n){
		par[i] = i;
		w[i] = 0;

		cin >> st;

		if(st == 0) hasMilk[i] = false;
		else hasMilk[i] = true;
	}

	vector<lp> edges;

	int u,v;
	ll c;

	rep(i,1,m){
		cin >> u >> v >> c;
		edges.push_back(make_pair(c,make_pair(u,v)));
	}

	sort(edges.begin(),edges.end());

	ll cost = 0;

	rep(i,0,(int)edges.size() - 1){
		c = edges[i].first;
		u = edges[i].second.first;
		v = edges[i].second.second;

		if((Find(u) != Find(v)) && !(hasMilk[Find(u)] && hasMilk[Find(v)])){
			if(hasMilk[Find(u)] || hasMilk[Find(v)]){
				Union(u,v);
				hasMilk[Find(u)] = true;
			}
			else Union(u,v);

			cost += c;
		}
	}

	bool possible = true;

	rep(i,1,n){
		if(!hasMilk[Find(i)]) possible = false;
	}

	if(!possible) cout << "impossible" << endl;
    else cout << cost << endl;
}
return 0;
}