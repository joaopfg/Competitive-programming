#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long int ll;

map<int,ll> dp;

ll sol(int n){
if(dp.count(n) > 0) return dp[n];

if(n == 0) return dp[n]  = 0;

return dp[n] = max(1LL*n , sol(n/2) + sol(n/3) + sol(n/4));
}

int main(){
fio

int n;

while(scanf("%d",&n) != EOF){
cout << sol(n) << endl;
dp.clear();
}
return 0;
}