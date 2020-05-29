#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n,k;

int main(){
fio

cin >> n >> k;

int x, quant = 0;

rep(i,1,n){
	cin >> x;

	if(x%k == 0) quant++;
}

cout << quant << endl;
return 0;
}