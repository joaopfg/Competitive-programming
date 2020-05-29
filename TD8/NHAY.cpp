#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n;
string needle, haystack;

vector<int> KMP(string (&s), string (&t)){
	int sSize = s.size();
	int tSize = t.size();

	vector<int> tPrefix(tSize);
	tPrefix[0] = 0;
	rep(i,1,tSize-1){
		int j = tPrefix[i-1];
		while(j > 0 && t[i] != t[j]) j = tPrefix[j-1];
		if(t[i] == t[j]) j++;
		tPrefix[i] = j;
	}

	vector<int> sPrefix(sSize);
	if(s[0] == t[0]) sPrefix[0] = 1;
	else sPrefix[0] = 0;
	rep(i,1,sSize-1){
		int j = sPrefix[i-1];
		if(j == tSize) j = tPrefix[j-1];
		while(j > 0 && s[i] != t[j]) j = tPrefix[j-1];
		if(s[i] == t[j]) j++;
		sPrefix[i] = j;
	}

	vector<int> occur;
	rep(i,0,sSize-1){
		if(sPrefix[i] == tSize) occur.push_back(i-tSize+1);
	}

	return occur;
}

int main(){
fio

while(cin >> n){
	cin >> needle >> haystack;
	vector<int> occur = KMP(haystack,needle);
	int occurSize = (int)occur.size();
	rep(i,0,occurSize-1) cout << occur[i] << endl;
	cout << endl;
}
return 0;
}