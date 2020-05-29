#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int r,c;

void changeSee(int (&line), int mask){
	rep(i,0,c-1){
		if(i != 0 && i != c-1){
			if((1 << i) & mask){
				line ^= (1 << i);
				line ^= (1 << (i-1));
				line ^= (1 << (i+1));
			}
		}
		else if(i == 0){
			if((1 << i) & mask){
				line ^= (1 << i);
				if(c > 1) line ^= (1 << (i+1));
			}
		}
		else{
			if((1 << i) & mask){
				line ^= (1 << i);
				line ^= (1 << (i-1));
			}
		}
	}
}

void changeNeighbor(int (&line), int mask){
	rep(i,0,c-1){
		if((1 << i) & mask) line ^= (1 << i);
	}
}

int getMask(string(&s)){
	int mask = 0;
	int sz = (int)s.size();

	rep(i,0,sz-1){
		if(s[i] == 'X') mask += (1 << (sz-1-i));
	}

	return mask;
}

int main(){
fio

while(true){
	cin >> r >> c;

	if(r == 0 && c == 0) break;

	string s;
	vector<int> Lines(r+1);
	vector<int> LinesAux(r+1);

	rep(i,1,r){
		cin >> s;
		LinesAux[i] = getMask(s);
	}

	bool found = false;
	int min = -1, sum;

	rep(i,0,(1 << c) - 1){
		rep(j,1,r) Lines[j] = LinesAux[j];

		sum = __builtin_popcount(i);
		changeSee(Lines[1],i);
		if(r > 1) changeNeighbor(Lines[2],i);

		int mask;
		rep(j,1,r-2){
			mask = Lines[j];
			sum += __builtin_popcount(mask);
			changeNeighbor(Lines[j],mask);
			changeSee(Lines[j+1],mask);
			changeNeighbor(Lines[j+2],mask);
		}

		if(r > 1){
			mask = Lines[r-1];
			sum  += __builtin_popcount(mask);
			changeNeighbor(Lines[r-1],mask);
			changeSee(Lines[r],mask);
		}

		if(__builtin_popcount(Lines[r]) == 0){
			found = true;
			if(min == -1 || sum < min) min = sum;
		}	
	}

	if(found) cout << "You have to tap " << min << " tiles." << endl;
	else cout << "Damaged billboard." << endl;
} 
return 0;
}
