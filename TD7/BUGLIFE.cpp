#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 2001

int cases, bugs, inter;
int gender[MAXN];
bool visit[MAXN];

int main(){
fio

cin >> cases;

rep(j,1,cases){
	memset(visit,false,sizeof(visit));
	memset(gender,false,sizeof(gender));

	cin >> bugs >> inter;

	vector<int> g[bugs+1];
	int u,v;
	bool susp = false;

	rep(i,1,inter){
		cin >> u >> v;

		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	rep(i,1,bugs){
		if(!visit[i]){
			queue<int> q;
			int cur;

			q.push(i);
			visit[i] = true;
			gender[i] = 0;

			while(!q.empty()){
				cur = q.front();
				q.pop();

				rep(i,0,(int)g[cur].size() - 1){
					if(!visit[g[cur][i]]){
						gender[g[cur][i]] = 1-gender[cur];
						visit[g[cur][i]] = true;
						q.push(g[cur][i]);
					}
					else{
						if(gender[g[cur][i]] == gender[cur]){
							susp = true;
							break;
						}
					}
				}

				if(susp) break;
			}

			if(susp) break;
		}
	}


	if(!susp){
		rep(i,1,bugs){
			if(!visit[i]){
				susp = true;
				break;
			} 
		}
	}

	cout << "Scenario #" << j << ":" << endl;

	if(susp) cout << "Suspicious bugs found!" << endl;
	else cout << "No suspicious bugs found!" << endl;
}
return 0;
}