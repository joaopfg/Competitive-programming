#include <bits/stdc++.h>
 
#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 
#define MAXN 1001
 
int cases, n, k;
int q[MAXN][MAXN], pref[MAXN][MAXN];
int arr[MAXN], cont[MAXN];
 
int main(){
fio
 
cin >> cases;
 
while(cases--){
	cin >> n >> k;
 
	memset(q,0,sizeof(q));
	memset(pref,0,sizeof(pref));
	memset(cont,0,sizeof(cont));
 
	int x,y,f,xMax = -1,yMax = -1;
	vector<int> ys;
 
	rep(i,1,n){
		cin >> x >> y >> f;
 
		if(x > xMax) xMax = x;
		if(y > yMax) yMax = y;
 
		q[x][y] = f;
		cont[y]++;
	}
 
	rep(i,1,xMax){
		pref[i][1] = q[i][1];
		rep(j,2,yMax) pref[i][j] = pref[i][j-1] + q[i][j];
	}

	rep(i,1,yMax){
		if(cont[i] > 0) ys.push_back(i);
	}
 
	int area = -1, start, sum;
	int quantY = (int)ys.size();

	rep(l,0,quantY-1){
		rep(r,l,quantY-1){
			int i = ys[l];
			int j = ys[r];
			
			rep(z,1,xMax){
				if(i == 1) arr[z] = pref[z][j];
				else arr[z] = pref[z][j] - pref[z][i-1];
			}
 
			start = 1;
			sum = 0;
			
			rep(z,1,xMax){
				sum += arr[z];
 
				while(sum >= k && start <= z){
					if(area == -1 || (j-i)*(z-start) < area) area = (j-i)*(z-start);
					sum -= arr[start];
					start++;
				}
 
				if(sum >= k && start == z){
					if(area == -1 || (j-i)*(z-start) < area) area = (j-i)*(z-start);
				}
			}
		}
	}
 
	cout << area << endl;
}
return 0;
} 