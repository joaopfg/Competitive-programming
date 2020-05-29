#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 121

typedef pair<int,int> ii;

const int INF = 1000000000;
int cases, n, max_match, c1, c2, edgesSz;
int cost[MAXN][MAXN];
int lx[MAXN], ly[MAXN], xy[MAXN], yx[MAXN], slack[MAXN], slackx[MAXN], ant[MAXN];
bool S[MAXN], T[MAXN];

void init_labels(){
	memset(slack,0,sizeof(slack));
	memset(slackx,0,sizeof(slackx));
	memset(lx, 0, sizeof(lx));
	memset(ly, 0, sizeof(ly));
	for (int x = 0; x < n; x++){
		for (int y = 0; y < n; y++) lx[x] = max(lx[x], cost[x][y]);
	}
}

void update_labels(){
	int x, y, delta = INF;

	for (y = 0; y < n; y++){
		if (!T[y]) delta = min(delta, slack[y]);
	}

	for (x = 0; x < n; x++){
		if (S[x]) lx[x] -= delta;
	}

	for (y = 0; y < n; y++){
		if (T[y]) ly[y] += delta;
	}

	for (y = 0; y < n; y++){
		if(!T[y]) slack[y] -= delta;
	}	 
}

void add_to_tree(int x, int prevx){
	S[x] = true; 
	ant[x] = prevx;

	for (int y = 0; y < n; y++){
		if (lx[x] + ly[y] - cost[x][y] < slack[y]){
			slack[y] = lx[x] + ly[y] - cost[x][y];
			slackx[y] = x;
		}
	} 
}

void augment(){
	if (max_match == n) return;

	int x, y, root; 
	int q[MAXN], wr = 0, rd = 0; 

	memset(S, false, sizeof(S)); 
	memset(T, false, sizeof(T)); 
	memset(ant, -1, sizeof(ant));

	for (x = 0; x < n; x++){
		if (xy[x] == -1){
			q[wr++] = root = x;
			ant[x] = -2;
			S[x] = true;
			break;
		}
	}

	for (y = 0; y < n; y++){
		slack[y] = lx[root] + ly[y] - cost[root][y];
		slackx[y] = root;
	}

	while (true){
		while (rd < wr){
			x = q[rd++];

			for (y = 0; y < n; y++){
				if (cost[x][y] == lx[x] + ly[y] && !T[y]){
					if (yx[y] == -1) break; 

					T[y] = true; 
					q[wr++] = yx[y]; 

					add_to_tree(yx[y], x); 
				}
			}

			if (y < n) break;
		}

		if (y < n) break;

		update_labels();
		wr = rd = 0;

		for (y = 0; y < n; y++){
			if (!T[y] && slack[y] == 0){
				if (yx[y] == -1){
					x = slackx[y];
					break;
				}
				else{
					T[y] = true; 
					if (!S[yx[y]]){
						q[wr++] = yx[y]; 
						add_to_tree(yx[y], slackx[y]); 
					}
				}
			}
		}

		if (y < n) break; 
	}

	if (y < n){
		max_match++;

		for (int cx = x, cy = y, ty; cx != -2; cx = ant[cx], cy = ty){
			ty = xy[cx];
			yx[cy] = cx;
			xy[cx] = cy;
		}

		augment(); 
	}
}

int hungarian(){
	int ret = 0; 
	max_match = 0;

	memset(xy, -1, sizeof(xy));
	memset(yx, -1, sizeof(yx));
	init_labels(); 
	augment();

	for (int x = 0; x < n; x++){
		if(cost[x][xy[x]] > 0) ret += cost[x][xy[x]];
	}

	return ret;
}

int main(){
fio

cin >> cases;

while(cases--){
	cin >> edgesSz;

	n = -1;
	int quantX = 0, quantY = 0;
	set<int> xVal, yVal;
	set<int>::iterator it;
	vector<int> comprx(MAXN), compry(MAXN);
	vector<ii> edges;

	rep(i,1,edgesSz){
		cin >> c1 >> c2;
		
		xVal.insert(c1);
		yVal.insert(c2);
		
		edges.push_back({c1,c2});
	}
	
	for(it = xVal.begin(); it != xVal.end(); it++){
		comprx[*it] = quantX;
		quantX++;
	}
	
	for(it = yVal.begin(); it != yVal.end(); it++){
		compry[*it] = quantY;
		quantY++;
	}
	
	n = max(quantX,quantY);
	
	rep(i,0,n-1){
		rep(j,0,n-1) cost[i][j] = -INF; 
	}
	
	rep(i,0,edgesSz-1) cost[comprx[edges[i].first]][compry[edges[i].second]] = 1;
	
	int ans = hungarian();

	cout << ans << '\n';
}
return 0;
}