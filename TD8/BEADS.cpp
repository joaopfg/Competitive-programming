#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

int cases;

vector<int> sort_cyclic_shifts(string (&s)){
	int n = (int)s.size();
	int alf = 256;

	vector<int> p(n), c(n), cnt(max(alf,n),0);

	rep(i,0,n-1) cnt[s[i]]++;

	rep(i,1,alf-1) cnt[i] += cnt[i-1];

	repi(i,n-1,0) p[--cnt[s[i]]] = i;

	c[p[0]] = 0;
	int classes = 1;

	rep(i,1,n-1){
		if(s[p[i]] != s[p[i-1]]) classes++;

		c[p[i]] = classes-1;
	}

	vector<int> pn(n), cn(n);

	for(int h=0; (1<<h) < n; h++){
		rep(i,0,n-1){
			pn[i] = p[i] - (1<<h);

			if(pn[i] < 0) pn[i] += n;
		}

		fill(cnt.begin(),cnt.begin() + classes,0);

		rep(i,0,n-1) cnt[c[pn[i]]]++;

		rep(i,1,n-1) cnt[i] += cnt[i-1];

		repi(i,n-1,0) p[--cnt[c[pn[i]]]] = pn[i];

		cn[p[0]] = 0;
		classes = 1;

		rep(i,1,n-1){
			ii cur = {c[p[i]],c[(p[i] + (1<<h))%n]};
			ii prev = {c[p[i-1]],c[(p[i-1] + (1<<h))%n]};

			if(cur != prev) classes++;

			cn[p[i]] = classes-1;
		}

		c.swap(cn); 
	}

	return c;
}

int main(){
fio

cin >> cases;

int n;
string s;

while(cases--){
	cin >> s;
	n = (int)s.size();
	
	vector<int> c = sort_cyclic_shifts(s);

	int ans = -1;

	rep(i,0,n-1){
		if(c[i] == 0){
			cout << i << endl;
			break;
		}
	}
}
return 0;
}