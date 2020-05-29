#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long int ll;

ll MOD = 1000000007;
ll n,l;

ll expBin(ll a, ll b){
	if(b == 0) return 1;

	a %= MOD;
	ll res = expBin(a,b/2);
	res %= MOD;

	if(b%2 == 1) return (((res*res)%MOD)*a)%MOD;
	return (res*res)%MOD; 
}

ll gcd(ll a, ll b, ll (&x), ll (&y)){
	if(a == 0){
		x = 0;
		y = 1;
		return b;
	}

	ll x1,y1;
	ll d = gcd(b%a,a,x1,y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return d;
}

ll invMod(ll a, ll m){
	ll x, y;
	ll d = gcd(a,m,x,y);
	return (x < 0) ? (x + m) : x;
}

int main(){
fio

while(true){
	cin >> n >> l;

	if(n == 0 && l == 0) break;

	ll m = MOD;

	ll invN = invMod(n-1,m);

	cout << (((n*(expBin(n,l) - 1))%MOD)*(invN%MOD))%MOD << endl;
}
return 0;
}