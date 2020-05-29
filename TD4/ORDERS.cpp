#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 200001

int cases;
int arr[MAXN], ans[MAXN], segTree[4*MAXN];

void updateSegTree(int index, int delta, int pos, int l, int r){
	if(index < l || index > r) return;

	if(l == r){
		segTree[pos] += delta;
		return;
	}

	int mid = (l+r)/2;

	updateSegTree(index,delta,2*pos+1,l,mid);
	updateSegTree(index,delta,2*pos+2,mid+1,r);

	segTree[pos] = segTree[2*pos+1] + segTree[2*pos+2];
}

int query(int k, int pos, int l, int r){
	if(l == r) return l;

	int mid = (l+r)/2;

	if(mid - l + 1 - segTree[2*pos+1] >=  k) return query(k,2*pos+1,l,mid);
	return query(k-mid+l-1+segTree[2*pos+1],2*pos+2,mid+1,r);
}

int main(){
fio

cin >> cases;

while(cases--){
int n;

cin >> n;

rep(i,0,n-1) cin >> arr[i];

memset(segTree,0,sizeof(segTree));

repi(i,n-1,0){
	int entry = query(i+1-arr[i],0,0,n-1);
	ans[i] = entry+1;
	updateSegTree(entry,1,0,0,n-1);
}

rep(i,0,n-1) cout << ans[i] << " ";
cout << endl;
}
return 0;
}