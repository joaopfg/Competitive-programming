#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long int ll;

#define MAXN 100002

int n;
int a[MAXN];

int main(){
fio

while(true){
	cin >> n;

	if(n == 0) break;

	vector<int> sell, buy, vinSell, vinBuy;

	rep(i,1,n){
		cin >> a[i];
		if(a[i] < 0){
			sell.push_back(i);
			vinSell.push_back(a[i]);
		} 
		else{
			buy.push_back(i);
			vinBuy.push_back(a[i]);
		} 
	}

	if((int)sell.size() == 0) cout << "0" << endl;
	else{
		int ind = 0;
		ll cost = 0;

		rep(i,0,(int)sell.size() - 1){
			while(vinSell[i] < 0){
				if(abs(vinSell[i]) < vinBuy[ind]){
					cost += 1LL*abs(buy[ind] - sell[i])*abs(vinSell[i]);
					vinBuy[ind] += vinSell[i];
					vinSell[i] = 0;
				}
				else{
					cost += 1LL*abs(buy[ind] - sell[i])*vinBuy[ind];
					vinSell[i] += vinBuy[ind];
					vinBuy[ind] = 0;
					ind++;
				}
			}
		}

		cout << cost << endl;
	}
}
return 0;
}