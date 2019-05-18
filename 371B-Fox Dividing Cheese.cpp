#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
map<pair<long long,long long> , long long> mp;
ll calc(ll x , ll y){
    if(x==y) return 0;
    if(((x%2!=0)&&(x%3!=0)&&(x%5!=0))&&((y%2!=0)&&(y%3!=0)&&(y%5!=0)))
        return 1e10;
    if(mp[{x,y}]!=0) return mp[{x,y}];
    ll ret=1e10;
  
    
    if((x%3==0)) ret=min(ret,1+calc(x/3,y));
    if((x%2==0)) ret=min(ret,1+calc(x/2,y));
    if((x%5==0)) ret=min(ret,1+calc(x/5,y));
    
    
    if((y%3==0)) ret=min(ret,1+calc(x,y/3));
    if((y%2==0)) ret=min(ret,1+calc(x,y/2));
    if((y%5==0)) ret=min(ret,1+calc(x,y/5));
    
    return mp[{x,y}]=ret;
}
ll a , b;
int main(){
    cin >> a >> b;
    if(a==b){
        cout<<0;
        return 0;
    }
    ll res = calc(a,b);
    if(res >= 1e10) cout<<-1;
    else cout<<res;
    return 0;
}