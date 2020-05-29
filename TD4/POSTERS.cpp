#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXL 10000001

typedef pair<int,int> ii;

int cases;
vector<int> compr(MAXL);

int main(){
fio

cin >> cases;

while(cases--){
	int n;
	vector<ii> intervals;
	set<int> wall;
	set<int> intermediate;
	set<int>::iterator it,itlow, itup;

	cin >> n;

    int a,b;

	rep(i,1,n){
		cin >> a >> b;
		intermediate.insert(a);
		intermediate.insert(b);
		intervals.push_back(make_pair(a,b));
	}

	int cont = 0;
	for(it = intermediate.begin(); it != intermediate.end(); it++){
		cont++;
		compr[*it] = cont; 
	}

	rep(i,1,cont) wall.insert(i);

	int visible = 0;

	repi(i,(int)intervals.size() - 1,0){
		intervals[i].first = compr[intervals[i].first];
		intervals[i].second = compr[intervals[i].second];
		itlow = wall.lower_bound(intervals[i].first);
		itup = wall.upper_bound(intervals[i].second);

		if(itlow != itup) visible++;
		wall.erase(itlow,itup);
	}

	cout << visible << endl;
}
return 0;
}