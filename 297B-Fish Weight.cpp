#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mn = 0;
ll n , m , k;
map<ll,ll> alic,bob;
vector<ll> va,vb; 
bool can(ll have,ll explorer){
 ll pos = lower_bound(vb.begin(), vb.end(), explorer)-vb.begin();
 if(vb.size()-pos >= have) return false;
 return true;
}

int main(){
 scanf("%lld%lld%lld",&n,&m,&k);
 for(int i=0,test;i<n;i++){
  scanf("%lld",&test);
  va.push_back(test);
 }
 for(int i=0,test;i<m;i++){
  scanf("%lld",&test);
  vb.push_back(test);
 }
 sort(va.begin(),va.end());
 sort(vb.begin(),vb.end());
 for(int i=0;i<va.size();i++){
  if(can(va.size()-i,va[i])){
   cout<<"YES";
   return 0;
  }
 }
 cout<<"NO";
 return 0;
}