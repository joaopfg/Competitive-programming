#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAX 27

int cases, n;
int indeg[MAX],outdeg[MAX];
bool isPresent[MAX], visit[MAX];
string s;

void dfs(int x, vector<int> (&g)[27]){
	visit[x] = true;
	
	rep(i,0,(int)g[x].size() - 1){
		if(!visit[g[x][i]]) dfs(g[x][i],g);
	}
}

int main(){
fio

cin >> cases;

while(cases--){
	memset(indeg,0,sizeof(indeg));
	memset(outdeg,0,sizeof(outdeg));
	memset(isPresent,false,sizeof(isPresent));
	
	vector<int> g[27];

	cin >> n;

	rep(i,1,n){
		cin >> s;

		int sz = (int)s.size();
		
		g[(int)(s[0] - 'a')].push_back((int)(s[sz-1] - 'a'));
		
		isPresent[(int)(s[0] - 'a')] = true;
		isPresent[(int)(s[sz-1] - 'a')] = true;
		outdeg[(int)(s[0] - 'a')]++;
		indeg[(int)(s[sz-1] - 'a')]++;
	}
	
	bool con = false;
	
	rep(i,0,25){
		if(isPresent[i]){
			memset(visit,false,sizeof(visit));
			
			con = true;
			
			if(!visit[i]){
				dfs(i,g);
				
				rep(i,0,25){
					if(isPresent[i] && !visit[i]){
						con = false;
						break;
					} 
				}
			}
			
			if(con) break;
		}
	}
	
	if(!con) cout << "The door cannot be opened." << endl;
	else{
	int quant = 0;
	
	rep(i,0,25){
		if(isPresent[i]) quant++;
	}
	
	int even = 0, odd = 0;

	rep(i,0,25){
		if(isPresent[i]){
			if(indeg[i] == outdeg[i]) even++;
			else if(indeg[i] == outdeg[i]+1 || outdeg[i] == indeg[i]+1) odd++;
		}
	}

	bool cycle = false, path = false;

	if(even == quant) cycle = true;
	else if((even == quant-2 && odd == 2) || (even == quant-1 && odd == 1)) path = true;
	
	if(cycle || path) cout << "Ordering is possible." << endl;
	else cout << "The door cannot be opened." << endl;		
	}
}
return 0;
}