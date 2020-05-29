#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 201

int n,m;
int block[MAXN];
char wall[MAXN][MAXN];

int main(){
fio

cin >> n >> m;

rep(i,1,n){
	rep(j,1,m){
		cin >> wall[i][j];
	}
}

rep(j,1,m){
	int l = 1;

	while(l <= n){
		int acr = 0;

		while(l+acr <= n && wall[l+acr][j] == '0') acr++;
		
		if(acr > 0){
			block[acr]++;
			l += acr;
		}
		else l++;
	}
}

rep(i,1,n){
	if(block[i] > 0) cout << i << " " << block[i] << endl;
}
return 0;
}