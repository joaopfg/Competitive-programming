#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 32
#define INF numeric_limits<double>::max();

const double EPS = 1e-9;
int n, m, cont;

int main(){
fio

while(true){
	cin >> n;

	if(n == 0) break;

	cont++;

	map<string,int> v;
	string s;
	double w[n+1][n+1];

	rep(i,1,n){
		rep(j,1,n) w[i][j] = INF;
	}

	rep(i,1,n) w[i][i] = 0.0;

	rep(i,1,n){
		cin >> s;
		v[s] = i;
	}

	cin >> m;

	string s1,s2;
	double d;

	rep(i,1,m){
		cin >> s1 >> d >> s2;
		w[v[s1]][v[s2]] = d;
	}

	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				if(w[i][k]*w[k][j] > w[i][j]) w[i][j] = w[i][k]*w[k][j];
			}
		}
	}

	bool can = false;

	rep(i,1,n){
		if(w[i][i] > 1.0){
			can = true;
			break;
		}
	}

	if(can) cout << "Case " << cont << ": Yes" << endl;
	else cout << "Case " << cont << ": No" << endl;
}
return 0;
}