#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 20002

const int INF = 20002;

int n, cont, one;
int d[MAXN], ones[MAXN];
string s;

void dfs(){
	cont++;

	int contCopy = cont;

	if(s[cont] == '1'){
		one++;
		ones[cont] = one;
		d[cont+1] = d[contCopy] + 1;
		dfs(); 
		d[cont+1] = d[contCopy] + 1;
		dfs();
	}
	else ones[cont] = 0;
}

int main(){
fio

int cases = 10;

while(cases--){
	cin >> n >> s;

	if(n == 1) cout << "0" << endl;
	else{
		cont = -1;
		one = 0;
		d[0] = 0;

		dfs();

		int maxDist = -1, minOnes = INF;

		rep(i,0,n-1){
			maxDist = max(maxDist,d[i]);
		}

		rep(i,0,n-1){
			if(d[i] == maxDist - 1){
				if(ones[i] < minOnes && ones[i] != 0) minOnes = ones[i];
			}
		}

		cout << minOnes << endl;
	}
}
return 0;
}