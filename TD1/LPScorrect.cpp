#include <bits/stdc++.h>
using namespace std;


typedef long long int ll;

ll n;
vector <ll> fHash(100005,0);
vector<ll> bHash(100005,0);
ll p=31;
ll mod=1e9+7;
vector<ll> p_pow(100005);

void findHash(string s){
    // ll n=s.length();    
    p_pow[0]=1;
    for(ll i=1;i<n;i++){
        p_pow[i]=(p_pow[i-1]*p)%mod;
    }
    //forward hash
    
    for(ll i=0;i<n;i++){
        fHash[i+1]=(fHash[i]+(s[i]-'a'+1)*p_pow[i])%mod;
    }
    //back hash
    // vector<ll> bHash(n+1,0);
    for(ll i=n-1;i>=0;i--){
        bHash[i]=(bHash[i+1]+(s[i]-'a'+1)*p_pow[n-i-1])%mod;
    }
}

bool isEqual(ll l,ll r){
    ll fs=(fHash[r+1]-fHash[l]+mod)%mod;
    ll ss=(bHash[l]-bHash[r+1]+mod)%mod;
    fs=(fs*p_pow[n-(r+1)])%mod;
    ss=(ss*p_pow[l])%mod;
    if(fs==ss){
        return true;
    }
    return false;
}


bool check(string s,ll d){
    for(ll i=0;i+d<=n;i++){
        if(isEqual(i,i+d-1)){
            return true;
        }
    }
    return false;
}

ll ans1=0;
ll ans2=0;
void oddBs(ll s,ll e,string st){
    while(s<=e){
        ll mid=(s+e)/2;
        ll x=2*mid+1;
        // cout<<mid<<" "<<x<<endl;
        if(check(st,x)){
            ans1=x;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
}



void evenBs(ll s,ll e,string st){
    while(s<=e){
        ll mid=(s+e)/2;
        ll x=2*mid;
        // cout<<mid<<" "<<x<<endl;
        if(check(st,x)){
            ans2=x;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
}



int main() {
    cin>>n;
    string s;
    cin>>s;
    n=s.length();
    findHash(s);
    if(n&1){
        oddBs(0,n/2,s);
        evenBs(0,n/2,s);
    }    
    else{
        oddBs(0,(n/2)-1,s);
        evenBs(0,n/2,s);
    }    
    cout<<max(ans1,ans2)<<endl;
}