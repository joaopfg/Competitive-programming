#include <bits/stdc++.h>
 
#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 
typedef pair<int,int> ii;
typedef vector<ii> vii;
 
int n;
 
int Ceil(int num, int den){
	return (num+den-1)/den;
}
 
int gcd(int a, int b, int& x, int& y)
{
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
 
bool sol(int a, int b, int c, int& x0, int& y0, int& g)
{
    g = gcd(abs(a), abs(b), x0, y0);
 
    if (c % g != 0)
        return false;
 
    x0 *= c / g;
    y0 *= c / g;
 
    if (a < 0)
        x0 = -x0;
 
    if (b < 0)
        y0 = -y0;
 
    return true;
}
 
bool adj(int curs, int els, int elf, int curf, int f){
	int a = curs, b = -els, c = elf - curf;
	int x0, y0, g;
 
	if(!sol(a,b,c,x0,y0,g)) return false;
 
	int kx,ky, x, y;
	if(x0 < 0 && y0 < 0){
		kx = -Ceil(abs(x0),els/g);
		ky = -Ceil(abs(y0),curs/g);
	}
	else if(x0 >= 0 && y0 >= 0){
		kx = x0/(els/g);
		ky = y0/(curs/g);
	}
	else if(x0 >= 0 && y0 < 0){
		kx = x0/(els/g);
		ky = -Ceil(abs(y0),curs/g);
	}
	else if(x0 < 0 && y0 >= 0){
		kx = -Ceil(abs(x0),els/g);
		ky = y0/(curs/g);
	}
 
	x = x0 - kx*(els/g);
	y = y0 - ky*(curs/g);
 
	if((curf + x*curs < f) || (elf + y*els < f)) return true;
 
	return false;
}
 
int main(){
fio
 
cin >> n;
 
while(n--){
	int f,e,a,b;
	bool entryA = false;
	vii el;
	queue<ii> q;
 
	cin >> f >> e >> a >> b;
 
	vector<char> visit(e+1,false);
 
	int x,y;
	rep(i,0,e-1){
		cin >> x >> y;
		el.push_back(make_pair(y,x));
		if(y <= a && (a-y)%x == 0){
			q.push(make_pair(y,x));
			visit[i] = true;
			entryA = true;
		} 
	}
	
	if(a == b) cout << "It is possible to move the furniture." << endl; 
	else if(!entryA) cout << "The furniture cannot be moved." << endl;
	else{
		ii cur;
		bool found = false;
 
		while(!q.empty()){
			cur = q.front();
			q.pop();
 
			if(cur.first <= b && (b - cur.first)%cur.second == 0){
				found = true;
				break;
			}
 
			rep(i,0,e-1){
				if(!visit[i]){
					if(adj(cur.second,
						el[i].second,
						el[i].first,
						cur.first,f)){
						visit[i] = true;
						q.push(el[i]);
					}
				}
			}
		}
 
		if(found) cout << "It is possible to move the furniture." << endl;
		else cout << "The furniture cannot be moved." << endl;
	} 
}
return 0;
} 