#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long int ll;

#define MAXN 100002
#define LOGMAXN 30

int n;
string s, sInv;
ll m = (ll)1000000009;
ll p1 = (ll)31;
ll p2 = (ll)37;
ll pow1[MAXN], pow2[MAXN];
ll hash1[MAXN], hash2[MAXN], hashInv1[MAXN], hashInv2[MAXN];

ll subHash(int p, int q, int st){
	if(st == 1){
		if(p == 0) return (hash1[q]*pow1[n+1])%m;
		else return (((hash1[q] - hash1[p-1] + m)%m)*pow1[n+1-p])%m;
	}
	else{
		if(p == 0) return (hash2[q]*pow2[n+1])%m;
		else return (((hash2[q] - hash2[p-1] + m)%m)*pow2[n+1-p])%m;
	}
}

ll subHashInv(int p, int q, int st){
	if(st == 1){
		if(p == 0) return (hashInv1[q]*pow1[n+1])%m;
		else return (((hashInv1[q] - hashInv1[p-1] + m)%m)*pow1[n+1-p])%m;
	}
	else{
		if(p == 0) return (hashInv2[q]*pow2[n+1])%m;
		else return (((hashInv2[q] - hashInv2[p-1] + m)%m)*pow2[n+1-p])%m;
	}
}

bool Equal(int p,int q){
	if(subHash(p,q,1) == subHashInv(n-q-1,n-p-1,1) && subHash(p,q,2) == subHashInv(n-q-1,n-p-1,2)) return true;
	return false;
}

bool pal(int sz){
	rep(i,0,n-sz){
		if(Equal(i,i+sz-1)) return true;
	}

	return false;
}

int evenBs(){
int ans = -1;

if(n == 1) return ans;

int begin = 1, end = n/2, mid, cont = 0;

while(cont <= LOGMAXN && begin != end){
	cont++;
	mid = (begin + end)/2;
	if(pal(2*mid)) begin = mid;
	else end = mid;
}

if(begin == end){
	if(pal(2*begin)) ans = 2*begin;
} 
else{
	if(end < begin) swap(begin,end);
	if(pal(2*end)) ans = 2*end;
	else if(pal(2*begin)) ans = 2*begin;
}

return ans;
}

int oddBs(){
int ans = -1;

int begin = 1, end, mid, cont = 0;

if(n%2 == 1) end = (n/2) + 1;
else end = n/2;

while(cont <= LOGMAXN && begin != end){
	cont++;
	mid = (begin + end)/2;
	if(pal(2*mid-1)) begin = mid;
	else end = mid;
}

if(begin == end){
	if(pal(2*begin-1)) ans = 2*begin -1;
} 
else{
	if(end < begin) swap(begin,end);
	if(pal(2*end-1)) ans = 2*end-1;
	else if(pal(2*begin-1)) ans = 2*begin-1;
}

return ans;
}

int main(){
fio

cin >> n;
cin >> s;

n = (int)s.size();

sInv = s;
rep(i,0,n-1){
	sInv[i] = s[n-1-i];
}

pow1[0] = 1LL;
rep(i,1,n+1) pow1[i] = (pow1[i-1]*p1)%m;
pow2[0] = 1LL;
rep(i,1,n+1) pow2[i] = (pow2[i-1]*p2)%m;

hash1[0] = (ll)(s[0] - 'a' + 1);
rep(i,1,n-1) hash1[i] = (hash1[i-1] + (((ll)(s[i] - 'a' + 1))*pow1[i])%m)%m;
hash2[0] = (ll)(s[0] - 'a' + 1);
rep(i,1,n-1) hash2[i] = (hash2[i-1] + (((ll)(s[i] - 'a' + 1))*pow2[i])%m)%m;

hashInv1[0] = (ll)(sInv[0] - 'a' + 1);
rep(i,1,n-1) hashInv1[i] = (hashInv1[i-1] + (((ll)(sInv[i] - 'a' + 1))*pow1[i])%m)%m;
hashInv2[0] = (ll)(sInv[0] - 'a' + 1);
rep(i,1,n-1) hashInv2[i] = (hashInv2[i-1] + (((ll)(sInv[i] - 'a' + 1))*pow2[i])%m)%m;

int ans = max(evenBs(),oddBs());
cout << max(ans,1) << endl;
return 0;
}