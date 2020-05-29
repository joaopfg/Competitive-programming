#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int cases, n;

int main(){
fio

cin >> cases;

while(cases--){
	cin >> n;

	if(n == 0) cout << "10" << endl;
	else if(n == 1) cout << "1" << endl;
	else{
		vector<int> sol;

	repi(i,9,2){
		while(n%i == 0){
			sol.push_back(i);
			n /= i;
		}
	}

	int sz = (int)sol.size();

	if(sz == 0 || n != 1) cout << "-1" << endl;
	else{
		repi(i,sz-1,0) cout << sol[i];
		cout << endl;
	}
	}
}
return 0;
}