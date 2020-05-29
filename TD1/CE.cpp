#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

string expr;

int pow10(int n){
	if(n == 0) return 1;

	int x = 1;

	rep(i,1,n) x *= 10;

	return x;
}

int main(){
fio

rep(j,1,99){
	cin >> expr;

	string num1, num2;

	int sz = (int)expr.size(), op;

	rep(i,0,sz-1){
		if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*'){
			op = i;
			break;
		}
	}

	rep(i,0,op-1) num1.push_back(expr[i]);
	rep(i,op+1,sz-1) num2.push_back(expr[i]);

	int n1 = 0, n2 = 0;
	int sz1 = (int)num1.size(), sz2 = (int)num2.size();

	repi(i,sz1-1,0) n1 += ((int)(num1[i] - '0'))*(pow10(sz1-1-i));
	repi(i,sz2-1,0) n2 += ((int)(num2[i] - '0'))*(pow10(sz2-1-i));

	if(expr[op] == '+') cout << n1+n2 << endl;
	else if(expr[op] == '-') cout << n1-n2 << endl;
	else cout << n1*n2 << endl;
}
return 0;
}