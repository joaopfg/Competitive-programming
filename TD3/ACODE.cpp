#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long int ll;

map<string,ll> dp;

ll sol(string s){
	if(dp.count(s) > 0) return dp[s];

	if(s.size() == 0 || s.size() == 1) return dp[s] = 1;

	int sz = s.size();

	string sCur = s;

	if(s[sz-1] == '0'){
		s.pop_back();
		s.pop_back();
		return dp[sCur] = sol(s);
	}
	else if(s[sz-2] == '1' || s[sz-2] == '2'){
		s.pop_back();
		string s1 = s;
		s.pop_back();
		string s2 = s;	
		return dp[sCur] = sol(s1) + sol(s2); 
	}
	else{
		s.pop_back();
	    return dp[sCur] = sol(s);
	} 
}

int main(){
fio

string s;

while(true){
	cin >> s;

	if(s == "0") break;

	cout << sol(s) << endl;

	dp.clear();
}
return 0;
}
