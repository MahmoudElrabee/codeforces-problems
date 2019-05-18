#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll MOD = 1e9+7;
ll POW(ll b,ll p){
        if(p==0)return 1;
    if(p==1)return b;
    ll m=POW(b,p/2);
    m=1ll*m*m%MOD;
    if(p&1)m=1ll*m*b%MOD;
    return m;
}
ll n;
int main(){
  
  cin >> n;
  cout<<(POW(2,n)*(POW(2,n)+1)/2)%MOD<<endl;
  
  return 0;
}