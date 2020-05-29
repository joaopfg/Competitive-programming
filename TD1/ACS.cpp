#include <bits/stdc++.h>
 
#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 
typedef pair<int,int> ii;
 
int m[1235][5679];
vector<ii> pos(1234*5678 + 1);
 
int main(){
fio
 
rep(i,1,1234){
	rep(j,1,5678){
		m[i][j] = j + (i-1)*5678;
		pos[j+(i-1)*5678] = {i,j};
	} 
}
 
char op;
int x,y,z;
 
while(cin >> op){
	if(op == 'Q'){
		cin >> x >> y;
		cout << m[x][y] << endl;
	} 
	else if(op == 'W'){
		cin >> z;
		cout << pos[z].first << " " << pos[z].second << endl; 
	}
	else if(op == 'R'){
		cin >> x >> y;
 
		rep(j,1,5678){
			int tmp = m[x][j];
			ii tmp2 = pos[m[x][j]];
			pos[m[x][j]] = pos[m[y][j]];
			m[x][j] = m[y][j];
			pos[m[y][j]] = tmp2;
			m[y][j] = tmp;
		}
	}
	else if(op == 'C'){
		cin >> x >> y;
 
		rep(i,1,1234){
			int tmp = m[i][x];
			ii tmp2 = pos[m[i][x]];
			pos[m[i][x]] = pos[m[i][y]];
			m[i][x] = m[i][y];
			pos[m[i][y]] = tmp2;
			m[i][y] = tmp;
		}
	}
}
return 0;
} 

