#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const int SQRTN = 31623;
int cases,m,n, ps;
vector<int> primes;

int main(){
fio

vector<char> isPrime(SQRTN+1,true);
isPrime[0] = false;
isPrime[1] = false;

for(int i=2;i*i <= SQRTN; i++){
	if(isPrime[i]){
		for(int j=i*i;j<=SQRTN;j += i) isPrime[j] = false;
	}
}

rep(i,0,SQRTN){
	if(isPrime[i]) primes.push_back(i);
}

ps = (int)primes.size();

cin >> cases;

while(cases--){
	cin >> m >> n;

	bool prime;

	rep(i,m,n){
		prime = true;

		if(i == 1) prime = false;
		else{
			rep(j,0,ps-1){
				if(i%primes[j] == 0 && i != primes[j]) prime = false;
			}
		}

		if(prime) cout << i << endl;
	}

	cout << endl;
}
return 0;
}