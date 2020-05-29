#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef pair<int,int> ii;

int cases, a, b, c;
map<ii,int> d;
map<ii,bool> visit;

int gcd(int x,int y){
	if(y == 0) return x;
	return gcd(y,x%y);
}

int main(){
fio

cin >> cases;

while(cases--){
	cin >> a >> b >> c;

	if(c%gcd(a,b) != 0) cout << "-1" << endl;
	else{
		bool achou = false;
		queue<ii> q;
		q.push({0,0});
		visit[{0,0}] = true;
		d[{0,0}] = 0;

		ii cur;
		int x,y;

		while(!q.empty()){
			cur = q.front();
			q.pop();

			x = cur.first;
			y = cur.second;

			if(x == c || y == c){
				achou = true;
				cout << d[{x,y}] << endl;
				break;
			} 

			if(!visit.count({x,0})){
				q.push({x,0});
				visit[{x,0}] = true;
				d[{x,0}] = d[{x,y}] + 1;
			}
			if(!visit.count({0,y})){
				q.push({0,y});
				visit[{0,y}] = true;
				d[{0,y}] = d[{x,y}] + 1;
			}
			if(!visit.count({a,y})){
				q.push({a,y});
				visit[{a,y}] = true;
				d[{a,y}] = d[{x,y}] + 1;
			} 
			if(!visit.count({x,b})){
				q.push({x,b});
				visit[{x,b}] = true;
				d[{x,b}] = d[{x,y}] + 1;
			}
			if(y <= (a-x) && y > 0 && !visit.count({x+y,0})){
				q.push({x+y,0});
				visit[{x+y,0}] = true;
				d[{x+y,0}] = d[{x,y}] + 1;
			}
			if(y > a-x && !visit.count({a,x+y-a})){
				q.push({a,x+y-a});
				visit[{a,x+y-a}] = true;
				d[{a,x+y-a}] = d[{x,y}] + 1;
			}
			if(x <= (b-y) && x > 0 && !visit.count({0,x+y})){
				q.push({0,x+y});
				visit[{0,x+y}] = true;
				d[{0,x+y}] = d[{x,y}] + 1;
			}
			if(x > b-y && !visit.count({x+y-b,b})){
				q.push({x+y-b,b});
				visit[{x+y-b,b}] = true;
				d[{x+y-b,b}] = d[{x,y}] + 1;
			}
		}

		if(!achou) cout << "-1" << endl;

		visit.clear();
		d.clear();
	}
}
return 0;
}