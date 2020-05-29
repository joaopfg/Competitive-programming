#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

typedef long long int lli;

lli input[MAXN];
lli segTree[4*MAXN];
lli lazy[4*MAXN];

void renewSegTree(int n){
for(int i=0;i<4*n;i++){
    segTree[i] = 0;
    lazy[i] = 0;
}
}

void constructSegTree(int low,int high,int pos){
if(low == high){
    segTree[pos] = input[low];
    return;
}

int mid = (low + high)/2;
constructSegTree(low,mid,2*pos+1);
constructSegTree(mid+1,high,2*pos+2);
segTree[pos] = segTree[2*pos+1] + segTree[2*pos+2];
}

void updateSegTreeRangeLazyAux(int startRange,int endRange,lli delta,int low,int high,int pos){
if(low > high) return;

if(lazy[pos] != 0){
    segTree[pos]+=(high-low+1)*lazy[pos];
    if(low != high){
        lazy[2*pos+1] += lazy[pos];
        lazy[2*pos+2] += lazy[pos];
    }
    lazy[pos] = 0;
}

if(startRange > high || endRange < low) return;

if(startRange <= low && endRange >= high){
    segTree[pos] += (high-low+1)*delta;
    if(low != high){
        lazy[2*pos+1] += delta;
        lazy[2*pos+2] += delta;
    }
    return;
}

int mid = (low + high)/2;
updateSegTreeRangeLazyAux(startRange,endRange,delta,low,mid,2*pos+1);
updateSegTreeRangeLazyAux(startRange,endRange,delta,mid+1,high,2*pos+2);
segTree[pos] = segTree[2*pos+1] + segTree[2*pos+2];
}

lli SumQueryLazyAux(int qlow,int qhigh,int low,int high,int pos){
if(low > high) return 0;

if(lazy[pos] != 0){
    segTree[pos] += (high-low+1)*lazy[pos];
    if(low != high){
        lazy[2*pos+1] += lazy[pos];
        lazy[2*pos+2] += lazy[pos];
    }
    lazy[pos] = 0;
}

if(qlow > high || qhigh < low) return 0;

if(qlow <= low && qhigh >= high) return segTree[pos];

int mid = (low + high)/2;
return SumQueryLazyAux(qlow,qhigh,low,mid,2*pos+1) + SumQueryLazyAux(qlow,qhigh,mid+1,high,2*pos+2);
}

void createSegmentTree(int n){
constructSegTree(0,n-1,0);
}

void updateSegTreeRangeLazy(int startRange,int endRange,lli delta,int n){
updateSegTreeRangeLazyAux(startRange,endRange,delta,0,n-1,0);
}

lli SumQueryLazy(int qlow,int qhigh,int len){
return SumQueryLazyAux(qlow,qhigh,0,len-1,0);
}

int main(){
        int t,n,c,Q,p,q;
        lli v;

        scanf("%d",&t);

        for(int i=1;i<=t;i++){
            scanf("%d%d",&n,&c);

            if(i!=1) renewSegTree(n);

            for(int j=0;j<n;j++) input[j] = 0;

            createSegmentTree(n);

            for(int j=1;j<=c;j++){
                scanf("%d",&Q);

                if(Q == 0){
                    scanf("%d%d%lld",&p,&q,&v);
                    updateSegTreeRangeLazy(p-1, q-1, v,n);
                }
                else{
                    scanf("%d%d",&p,&q);
                    printf("%lld\n",SumQueryLazy(p-1,q-1,n));
                }
            }
        }
return 0;
}