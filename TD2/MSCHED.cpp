#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 10002

typedef pair<int,int> ii;

bool comp(ii a, ii b){
	if(a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

int n;
vector<ii> inf;
bool visit[MAXN];

int main(){
fio

cin >> n;

int g,d;
rep(i,1,n){
	cin >> g >> d;

	inf.push_back(make_pair(g,d));
}

sort(inf.begin(),inf.end(),comp);

	int gal = 0;

	rep(i,0,n-1){
		repi(j,min(n,inf[i].second)-1,0){
			if(!visit[j]){
				visit[j] = true;
				gal += inf[i].first;
				break;
			}
		}
	}

	cout << gal << endl;
return 0;
}