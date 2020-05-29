#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int cases;

int prefMax(string (&s)){
	int sz = (int)s.size();

	vector<int> sPref(sz);
	sPref[0] = 0;
	rep(i,1,sz-1){
		int j = sPref[i-1];
		while(j > 0 && s[i] != s[j]) j = sPref[j-1];
		if(s[i] == s[j]) j++;
		sPref[i] = j;
	}

	return sPref[sz-1];
}

int main(){
fio

cin >> cases;

while(cases--){
	int ans = 0;
	string s, aux;

	cin >> s;

	rep(i,0,(int)s.size() - 1){
		aux.push_back(s[i]);
		reverse(aux.begin(),aux.end());
		ans += i+1-prefMax(aux);
		reverse(aux.begin(),aux.end());
	}

	cout << ans << endl;
}
return 0;
}