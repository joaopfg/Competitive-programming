#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int t;
int expTen[] = {1000,100,10,1};

bool isPrime(int x){
	if(x == 0 || x == 1)
		return false;

	for(int i=2;i*i<=x;i++){
		if(x%i == 0) return false;
	}

	return true;
}

int num(string (&s)){
	int n = 0;

	rep(i,0,3) n += expTen[i]*((int)(s[i] - '0'));

	return n;
}

int main(){
fio

cin >> t;

while(t--){
queue<string> q;
vector<int> d(10000,0);
vector<char> visit(10000,false);
string p1, p2;

cin >> p1 >> p2;

visit[num(p1)] = true;
d[num(p1)] = 0;
q.push(p1);

string cur;
bool found = false;
int steps;

while(!q.empty()){
	cur = q.front();

	if(num(cur) == num(p2)){
		found = true;
		steps = d[num(cur)];
		break;
	}

	q.pop();

	rep(i,0,3){
		for(char c: {'0','1','2','3','4','5','6','7','8','9'}){
			    if(i == 0 && c == '0') continue;
				string aux = cur;
			    aux[i] = c;
			    int neighbor = num(aux);
				if(!visit[neighbor] && isPrime(neighbor)){
					visit[neighbor] = true;
					d[neighbor] = d[num(cur)] + 1;
					q.push(aux);
				}
			}
		}
	}

if(found) cout << steps << endl;
else cout <<  "Impossible" << endl; 
}
return 0;
}