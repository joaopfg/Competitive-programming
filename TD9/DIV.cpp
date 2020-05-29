#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int qt;

bool ver(int x){
	if(x == 0 || x == 1) return false;

	for(int i=2;i*i<=x;i++){
		if(x%i == 0) return false;
	}

	return true;
}

int main(){
fio

vector<char> isPrime(1001,true);
isPrime[0] = false;
isPrime[1] = false;

for(int i=2;i*i <= 1000; i++){
	if(isPrime[i]){
		for(int j = i*i; j<=1000; j+= i) isPrime[j] = false;
	}
}

vector<int> primes;
rep(i,2,1000){
	if(isPrime[i]) primes.push_back(i);
}

int ps = (int)primes.size();

rep(i,1,1000000){
	int div = 1, numb = i, exp;

	rep(j,0,ps-1){
		if(primes[j]*primes[j] > numb) break;
		exp = 0;
		
		while(numb%primes[j] == 0){
			numb /= primes[j];
			exp++;
		}
		
		div *= (exp+1);
	}

	//i is prime
	if(numb != 1) div *= 2;

	rep(j,0,ps-1){
		if(primes[j]*primes[j] > div) break;
		if(div%primes[j] == 0){
			int p = div/primes[j];

			if(p != primes[j] && ver(p)){
				qt++;
				if(qt%9 == 0) cout << i << endl;
				break;
			}
		}
	}
}
return 0;
}