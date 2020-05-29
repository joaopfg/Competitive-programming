#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n;
string s, ans;

int main(){
fio

cin >> n >> s;

for(int i=0; i<2*n; i += 2){
	if((s[i] == 'A' && s[i+1] == 'B') || (s[i] == 'B' && s[i+1] == 'A')){
		ans.push_back('C');
		ans.push_back('D');
	}
	else if((s[i] == 'A' && s[i+1] == 'C') || (s[i] == 'C' && s[i+1] == 'A')){
		ans.push_back('B');
		ans.push_back('D');
	}
	else if((s[i] == 'A' && s[i+1] == 'D') || (s[i] == 'D' && s[i+1] == 'A')){
		ans.push_back('B');
		ans.push_back('C');
	}
	else if((s[i] == 'B' && s[i+1] == 'C') || (s[i] == 'C' && s[i+1] == 'B')){
		ans.push_back('A');
		ans.push_back('D');
	}
	else if((s[i] == 'B' && s[i+1] == 'D') || (s[i] == 'D' && s[i+1] == 'B')){
		ans.push_back('A');
		ans.push_back('C');
	}
	else if((s[i] == 'C' && s[i+1] == 'D') || (s[i] == 'D' && s[i+1] == 'C')){
		ans.push_back('A');
		ans.push_back('B');
	}
}

for(int i=1; i<= 2*n-3; i += 2){
	if(ans[i] == ans[i+1]) swap(ans[i+1],ans[i+2]);
}

cout << ans << endl;
return 0;
}