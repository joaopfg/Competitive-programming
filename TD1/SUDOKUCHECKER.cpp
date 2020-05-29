#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 1001

int cases, n;
int cont[MAXN*MAXN];
int s[MAXN][MAXN];

int main(){
fio

cin >> cases;

rep(test,1,cases){
	cin >> n;

	rep(i,1,n*n){
		rep(j,1,n*n) cin >> s[i][j];
	}

	bool valid = true;

	rep(i,1,n*n){
		memset(cont,0,sizeof(cont));

		rep(j,1,n*n) cont[s[i][j]]++;

		rep(j,1,n*n){
			if(cont[j] == 0 || cont[j] > 1){
				valid = false;
				break;
			}
		}

		if(!valid) break;
	}

	if(valid){
		rep(j,1,n*n){
			memset(cont,0,sizeof(cont));

			rep(i,1,n*n) cont[s[i][j]]++;

			rep(i,1,n*n){
				if(cont[i] == 0 || cont[i] > 1){
					valid = false;
					break;
				}
			}

			if(!valid) break;
		}

		if(valid){
			rep(i,1,n){
				rep(j,1,n){
					memset(cont,0,sizeof(cont));

					rep(p,n*i-n+1,n*i){
						rep(q,n*j-n+1,n*j){
							cont[s[p][q]]++;
						}
					}

					rep(p,1,n*n){
						if(cont[p] == 0 || cont[p] > 1){
							valid = false;
							break;
						}
					}

					if(!valid) break;
				}
				if(!valid) break;
			}
		}
	}

	cout << "Case #" << test << ": ";
	if(valid) cout << "Yes" << endl;
	else cout << "No" << endl;
}
return 0;
}