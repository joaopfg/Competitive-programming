#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int cases, n;

int main(){
fio

cin >> cases;

while(cases--){
	cin >> n;

	int ans = 0;

	if(n != 1){
		for(int i=2;i*i<=n;i++){
			if(n%i == 0){
				if(i == n/i) ans += i;
				else ans += (i + n/i);
			}
		}

		ans++;
	}

	cout << ans << endl;

}
return 0;
}
