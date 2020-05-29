#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long int ll;

int n;
ll p1 = 31, p2 = 37, m = 1000000009;
ll hash1[1000][1000], hash2[1000][1000], hash3[1000][1000], hash4[1000][1000];
ll pow1[1000], pow2[1000];

ll subHash1(int l, int p, int q, int st){
	if(st == 1){
		if(p == 0) return (hash1[l][q]*pow1[n+1])%m;
		else return (((hash1[l][q] - hash1[l][p-1] + m)%m)*pow1[n+1-p])%m;
	}
	else{
		if(p == 0) return (hash2[l][q]*pow2[n+1])%m;
		else return (((hash2[l][q] - hash2[l][p-1] + m)%m)*pow2[n+1-p])%m;
	}
}

ll subHash2(int l, int p, int q, int st){
	if(st == 1){
		if(p == 0) return (hash3[l][q]*pow1[n+1])%m;
		else return (((hash3[l][q] - hash3[l][p-1] + m)%m)*pow1[n+1-p])%m;
	}
	else{
		if(p == 0) return (hash4[l][q]*pow2[n+1])%m;
		else return (((hash4[l][q] - hash4[l][p-1] + m)%m)*pow2[n+1-p])%m;
	}
}

int main(){
fio

int n1,n2,m1,m2;

cin >> n1 >> n2;

vector<string> l1(n1); 

rep(i,0,n1-1) cin >> l1[i];

cin >> m1 >> m2;

vector<string> l2(m1);

rep(i,0,m1-1) cin >> l2[i];

n = max(n2,m2);

pow1[0] = 1;
pow2[0] = 1;

rep(i,1,n+1){
	pow1[i] = (pow1[i-1]*p1)%m;
	pow2[i] = (pow2[i-1]*p2)%m;
} 

rep(i,0,n1-1){
	hash1[i][0] = (ll)(l1[i][0] - 'a' + 1);
	hash2[i][0] = (ll)(l1[i][0] - 'a' + 1);

	rep(j,1,n2-1) hash1[i][j] = (hash1[i][j-1] + (pow1[j]*((ll)(l1[i][j] - 'a' + 1)))%m)%m;
	rep(j,1,n2-1) hash2[i][j] = (hash2[i][j-1] + (pow2[j]*((ll)(l1[i][j] - 'a' + 1)))%m)%m;
}

rep(i,0,m1-1){
	hash3[i][0] = (ll)(l2[i][0] - 'a' + 1);
	hash4[i][0] = (ll)(l2[i][0] - 'a' + 1);

	rep(j,1,m2-1) hash3[i][j] = (hash3[i][j-1] + (pow1[j]*((ll)(l2[i][j] - 'a' + 1)))%m)%m;
	rep(j,1,m2-1) hash4[i][j] = (hash4[i][j-1] + (pow2[j]*((ll)(l2[i][j] - 'a' + 1)))%m)%m;
}

bool found = false;

rep(i,0,m1-n1){
	rep(j,0,m2-n2){
		bool ok = true;

		rep(z,0,n1-1){
			if(subHash1(z,0,n2-1,1) != subHash2(i+z,j,j+n2-1,1) ||
				subHash1(z,0,n2-1,2) != subHash2(i+z,j,j+n2-1,2)){
				ok = false;
				break;
			}
		}

		if(ok){
			cout << "(" << i+1 << "," << j+1 << ")" << endl;
			found = true;
		} 
	}
}

if(!found) cout << "NO MATCH FOUND..." << endl; 
return 0;
}