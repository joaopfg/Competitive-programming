#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int cases;

int exp10(int x){
	int res = 1;
	rep(i,1,x) res *= 10;
	return res;
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b,a%b);
}

int main(){
fio

cin >> cases;

while(cases--){
	string n;
	int point = -1, den = 1, num = 0, sz, ans = 1;

	cin >> n;

	sz = (int)n.size();

	rep(i,0,sz-1){
		if(n[i] == '.') point = i; 
	}

	if(point != -1){
		int exp = sz-1-point;
		den = exp10(exp);
	} 

	if(den == 1) cout << ans << endl;
	else{
		string numb;

		rep(i,0,sz-1){
			if(n[i] != '.') numb.push_back(n[i]);
		}

		int nsz = (int)numb.size();

		repi(i,nsz - 1,0) num += (int)(numb[i] - '0')*exp10(nsz-1-i);

		ans = den/gcd(num,den);
		
		cout << ans << endl;
	}
}
return 0;
}
