#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long int ll;

#define MAXN 100002

int n;
int h[MAXN];
stack<int> st;

int main(){
fio

while(true){
	cin >> n;

	if(n == 0) break;

	ll Max = -1;
	int Top;

	rep(i,1,n){
		cin >> h[i];

		if(st.empty() || h[i] >= h[st.top()]) st.push(i);
		else{
			while(true){
				Top = st.top();
				st.pop();

				if(st.empty()) Max = max(Max,1LL*(i - 1)*h[Top]);
				else Max = max(Max,1LL*(i - 1 - st.top())*h[Top]);

				if(st.empty() || h[i] >= h[st.top()]){
					st.push(i);
					break;
				}
			}
		}
	}

	while(!st.empty()){
	    Top = st.top();
		st.pop();

		if(st.empty()) Max = max(Max,1LL*n*h[Top]);
		else Max = max(Max,1LL*(n - st.top())*h[Top]);
	}

	cout << Max << endl; 
}
return 0;
}