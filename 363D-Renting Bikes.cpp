#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ;
ll n , m , bouns;
vector<ll> vn , vm;
bool check(ll mid){
  ll cant = 0;
  for(int i=0;i<mid;i++)
    if(vn[i] < vm[mid-i-1]) cant+=vm[mid-1-i]-vn[i];
  if(cant <= bouns) return true;
  return false;
}
int main(){
  cin>>n>>m>>bouns;
  vn.resize(n) , vm.resize(m);
  for(int i=0;i<n;i++) cin>>vn[i];
  for(int j=0;j<m;j++) cin>>vm[j];
  sort(vn.rbegin(),vn.rend());
  sort(vm.begin(),vm.end());
  ll l = 0 , r = min(n,m) , ans = 0 , mid , mn = 0 , sum = 0;
  while(l<=r){
    mid=(l+r)/2;
    if(check(mid)){
      ans=mid;
      l=mid+1;
    }else r=mid-1;
  }
  for(int i=0;i<ans;i++){
    if(vn[i] < vm[ans-i-1]) mn+=vm[ans-1-i]-vn[i],sum+=vn[i];
    else sum+=vm[ans-i-1];
  }
  cout<<ans<<" "<<max((ll)0,sum - (bouns-mn))<<endl;
  return 0;
}