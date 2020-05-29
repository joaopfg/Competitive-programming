#include <bits/stdc++.h>
 
#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 
typedef pair<int,int> ii;
typedef pair<int,ii> ip;
 
#define MAXN 10002

const int INF = 0x3f3f3f3f; 
int cases,n,m,k,s,t;
int w[MAXN],wS[MAXN], wT[MAXN];
 
struct comp{
bool operator()(const int (&a), const int (&b)){
return w[a] < w[b];
}
};
 
int main(){
fio
 
cin >> cases;
 
while(cases--){
	cin >> n >> m >> k >> s >> t;
 
	vector<ii> g[n+1], gt[n+1];
 
	int a,b,d;
	rep(i,1,m){
		cin >> a >> b >> d;
		g[a].push_back(make_pair(b,d));
		gt[b].push_back(make_pair(a,d));
	}
 
	vector<ip> edges;
	rep(i,1,k){
		cin >> a >> b >> d;
		edges.push_back(make_pair( a,make_pair(b,d)));
	}
 
	rep(i,1,n) w[i] = INF;
	w[s] = 0;
 
	set<int,comp> q;
	q.insert(s);
 
	int cur,to,weight;
	while(!q.empty()){
		cur = *(q.begin());
		q.erase(cur);
 
		rep(i,0,(int)g[cur].size() - 1){
			to = g[cur][i].first;
			weight = g[cur][i].second;
 
			if(w[cur] + weight < w[to]){
				q.erase(to);
				w[to] = w[cur] + weight;
				q.insert(to);
			}
		}
	}
 
	rep(i,1,n) wS[i] = w[i];
 
	rep(i,1,n) w[i] = INF;
	w[t] = 0;
 
	q.insert(t);
 
	while(!q.empty()){
		cur = *(q.begin());
		q.erase(cur);
 
		rep(i,0,(int)gt[cur].size() - 1){
			to = gt[cur][i].first;
			weight = gt[cur][i].second;
 
			if(w[cur] + weight < w[to]){
				q.erase(to);
				w[to] = w[cur] + weight;
				q.insert(to);
			}
		}
	}
 
	rep(i,1,n) wT[i] = w[i];
 
	int ans = wS[t];
 
	rep(i,0,k-1){
		a = edges[i].first;
		b = edges[i].second.first;
		d = edges[i].second.second;
 
		ans = min(ans, min(wS[a]+d+wT[b],wS[b]+d+wT[a]));
	}
	
	if(ans == INF) ans = -1;
	
	cout << ans << endl; 
}
return 0;
} 