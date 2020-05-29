#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef pair<int,int> ii;
typedef unsigned long long int ll;

int cases;
int quant, from, to;
ll cur;
ii sq[5], otherSq[4], sqAux[5];
bool visit[8][8][8][8][8][8][8][8];

int pos(ii Sq){
	int row = Sq.first;
	int col = Sq.second;

	return 8*(row-1)+col; 
}

ii square(int p){
	int row,col;

	if(p%8 == 0){
		row = p/8;
		col = 8;
	}
	else{
		row = (p/8) + 1;
		col = p%8;
	}

	return make_pair(row,col);
}

bool right(ii see){
	ii sq1 = otherSq[1];
	ii sq2 = otherSq[2];
	ii sq3 = otherSq[3];

	if(see.second + 1 > 8) return false;

	if(see.first == sq1.first && (see.second + 1) == sq1.second) return false;
	if(see.first == sq2.first && (see.second + 1) == sq2.second) return false;
	if(see.first == sq3.first && (see.second + 1) == sq3.second) return false;

	return true;
}

bool left(ii see){
	ii sq1 = otherSq[1];
	ii sq2 = otherSq[2];
	ii sq3 = otherSq[3];

	if(see.second - 1 < 1) return false;

	if(see.first == sq1.first && (see.second - 1) == sq1.second) return false;
	if(see.first == sq2.first && (see.second - 1) == sq2.second) return false;
	if(see.first == sq3.first && (see.second - 1) == sq3.second) return false;

	return true;
}

bool up(ii see){
	ii sq1 = otherSq[1];
	ii sq2 = otherSq[2];
	ii sq3 = otherSq[3];

	if(see.first - 1 < 1) return false;

	if(see.second == sq1.second && (see.first - 1) == sq1.first) return false;
	if(see.second == sq2.second && (see.first - 1) == sq2.first) return false;
	if(see.second == sq3.second && (see.first - 1) == sq3.first) return false;

	return true;
}

bool down(ii see){
	ii sq1 = otherSq[1];
	ii sq2 = otherSq[2];
	ii sq3 = otherSq[3];

	if(see.first + 1 > 8) return false;

	if(see.second == sq1.second && (see.first + 1) == sq1.first) return false;
	if(see.second == sq2.second && (see.first + 1) == sq2.first) return false;
	if(see.second == sq3.second && (see.first + 1) == sq3.first) return false;

	return true;
}

bool right2(ii see){
	ii sq1 = otherSq[1];
	ii sq2 = otherSq[2];
	ii sq3 = otherSq[3];

	if(see.second + 2 > 8) return false;

	if(see.first == sq1.first && (see.second + 2) == sq1.second) return false;
	if(see.first == sq2.first && (see.second + 2) == sq2.second) return false;
	if(see.first == sq3.first && (see.second + 2) == sq3.second) return false;

	return true;
}

bool left2(ii see){
	ii sq1 = otherSq[1];
	ii sq2 = otherSq[2];
	ii sq3 = otherSq[3];

	if(see.second - 2 < 1) return false;

	if(see.first == sq1.first && (see.second - 2) == sq1.second) return false;
	if(see.first == sq2.first && (see.second - 2) == sq2.second) return false;
	if(see.first == sq3.first && (see.second - 2) == sq3.second) return false;

	return true;
}

bool up2(ii see){
	ii sq1 = otherSq[1];
	ii sq2 = otherSq[2];
	ii sq3 = otherSq[3];

	if(see.first - 2 < 1) return false;

	if(see.second == sq1.second && (see.first - 2) == sq1.first) return false;
	if(see.second == sq2.second && (see.first - 2) == sq2.first) return false;
	if(see.second == sq3.second && (see.first - 2) == sq3.first) return false;

	return true;
}

bool down2(ii see){
	ii sq1 = otherSq[1];
	ii sq2 = otherSq[2];
	ii sq3 = otherSq[3];

	if(see.first + 2 > 8) return false;

	if(see.second == sq1.second && (see.first + 2) == sq1.first) return false;
	if(see.second == sq2.second && (see.first + 2) == sq2.first) return false;
	if(see.second == sq3.second && (see.first + 2) == sq3.first) return false;

	return true;
}

void Visit(ll mask){
	quant = 0;

	rep(i,0,63){
		if((1LL << i) & cur) sqAux[++quant] = square(i+1);
	}

	sort(sqAux + 1, sqAux + quant + 1);

	visit[sqAux[1].first][sqAux[1].second][sqAux[2].first][sqAux[2].second][sqAux[3].first][sqAux[3].second][sqAux[4].first][sqAux[4].second] = true;
}

bool isVisit(ll mask){
	quant = 0;

	rep(i,0,63){
		if((1LL << i) & cur) sqAux[++quant] = square(i+1);
	}

	sort(sqAux + 1, sqAux + quant + 1);

	if(!visit[sqAux[1].first][sqAux[1].second][sqAux[2].first][sqAux[2].second][sqAux[3].first][sqAux[3].second][sqAux[4].first][sqAux[4].second])
		return false;

	return true;
}

int main(){
fio

cin >> cases;

while(cases--){
int row, col, p;
ll start = 0LL, end = 0LL;
queue<ll> q;
//set<ll> visit;
map<ll,int> dist;

rep(i,1,4){
	cin >> row >> col;
	p = pos(make_pair(row,col));
	start += (1LL << (p-1));
}
rep(i,1,4){
	cin >> row >> col;
	p = pos(make_pair(row,col));
	end += (1LL << (p-1));
}

q.push(start);
//visit.insert(start);
Visit(start);
dist[start] = 0;

ii neighborSq;
ll neighbor;
bool found = false;

while(!q.empty()){
	cur = q.front();

	if(dist[cur] == 9) break;

	if(cur == end){
		found = true;
		break;
	}

	q.pop();

	quant = 0;

	rep(i,0,63){
		if((1LL << i) & cur) sq[++quant] = square(i+1);
	}

	rep(i,1,4){
		quant = 0;
		rep(j,1,4){
			if(j != i) otherSq[++quant] = sq[j];
		}

		if(right(sq[i])){
			from = pos(sq[i]);

			neighborSq.first = sq[i].first;
			neighborSq.second = sq[i].second + 1;

			to = pos(neighborSq);

			neighbor = cur;
			neighbor ^= (1LL << (from - 1));
			neighbor ^= (1LL << (to - 1));
			if(!isVisit(neighbor)){
				Visit(neighbor);
				q.push(neighbor);
				dist[neighbor] = dist[cur] + 1;
			}
		}
		else if(right2(sq[i])){
			from = pos(sq[i]);

			neighborSq.first = sq[i].first;
			neighborSq.second = sq[i].second + 2;

			to = pos(neighborSq);

			neighbor = cur;
			neighbor ^= (1LL << (from - 1));
			neighbor ^= (1LL << (to - 1));
			if(!isVisit(neighbor)){
				Visit(neighbor);
				q.push(neighbor);
				dist[neighbor] = dist[cur] + 1;
			}
		}

		if(left(sq[i])){
			from = pos(sq[i]);

			neighborSq.first = sq[i].first;
			neighborSq.second = sq[i].second - 1;

			to = pos(neighborSq);

			neighbor = cur;
			neighbor ^= (1LL << (from - 1));
			neighbor ^= (1LL << (to - 1));
			if(!isVisit(neighbor)){
				Visit(neighbor);
				q.push(neighbor);
				dist[neighbor] = dist[cur] + 1;
			}
		}
		else if(left2(sq[i])){
			from = pos(sq[i]);

			neighborSq.first = sq[i].first;
			neighborSq.second = sq[i].second - 2;

			to = pos(neighborSq);

			neighbor = cur;
			neighbor ^= (1LL << (from - 1));
			neighbor ^= (1LL << (to - 1));
			if(!isVisit(neighbor)){
				Visit(neighbor);
				q.push(neighbor);
				dist[neighbor] = dist[cur] + 1;
			}
		}

		if(up(sq[i])){
			from = pos(sq[i]);

			neighborSq.first = sq[i].first - 1;
			neighborSq.second = sq[i].second;

			to = pos(neighborSq);

			neighbor = cur;
			neighbor ^= (1LL << (from - 1));
			neighbor ^= (1LL << (to - 1));
			if(!isVisit(neighbor)){
				Visit(neighbor);
				q.push(neighbor);
				dist[neighbor] = dist[cur] + 1;
			}
		}
		else if(up2(sq[i])){
			from = pos(sq[i]);

			neighborSq.first = sq[i].first - 2;
			neighborSq.second = sq[i].second;

			to = pos(neighborSq);

			neighbor = cur;
			neighbor ^= (1LL << (from - 1));
			neighbor ^= (1LL << (to - 1));
			if(!isVisit(neighbor)){
				Visit(neighbor);
				q.push(neighbor);
				dist[neighbor] = dist[cur] + 1;
			}
		}

		if(down(sq[i])){
			from = pos(sq[i]);

			neighborSq.first = sq[i].first + 1;
			neighborSq.second = sq[i].second;

			to = pos(neighborSq);

			neighbor = cur;
			neighbor ^= (1LL << (from - 1));
			neighbor ^= (1LL << (to - 1));
			if(!isVisit(neighbor)){
				Visit(neighbor);
				q.push(neighbor);
				dist[neighbor] = dist[cur] + 1;
			}
		}
		else if(down2(sq[i])){
			from = pos(sq[i]);

			neighborSq.first = sq[i].first + 2;
			neighborSq.second = sq[i].second;

			to = pos(neighborSq);

			neighbor = cur;
			neighbor ^= (1LL << (from - 1));
			neighbor ^= (1LL << (to - 1));
			if(!isVisit(neighbor)){
				Visit(neighbor);
				q.push(neighbor);
				dist[neighbor] = dist[cur] + 1;
			}
		}
	}
}

if(found) cout << "YES" << endl;
else cout << "NO" << endl;

memset(visit,false,sizeof(visit));
}
return 0;
}