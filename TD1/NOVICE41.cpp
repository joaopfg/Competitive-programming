#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 51

int cases, n;
char grid[MAXN][MAXN];

int main(){
fio

cin >> cases;

while(cases--){
	cin >> n;

	rep(i,1,n){
		rep(j,1,n) cin >> grid[i][j];
	}

	vector<int> l(n+1,0), c(n+1,0), diag1(2*n,0), diag2(2*n,0);

	rep(i,1,n){
		rep(j,1,n){
			if(grid[i][j] == '#'){
				l[i]++;
				c[j]++;
				diag1[i+j-1]++;
				diag2[i-j+n]++;
			}
		}
	}

	bool valid = true;

	rep(i,1,n){
		if(l[i] > 1 || c[i] > 1){
			valid = false;
			break;
		}
	}

	if(valid){
		rep(i,1,2*n-1){
			if(diag1[i] > 1 || diag2[i] > 1){
				valid = false;
				break;
			}
		}
	}

	if(valid) cout << "YES" << endl;
	else cout << "NO" << endl;
}
return 0;
}