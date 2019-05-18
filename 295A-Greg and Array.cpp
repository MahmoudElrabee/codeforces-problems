#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll N = 1e5;
ll n , m , k , seg[N*4] , lazy[N*4];
struct operation{
  ll l , r , val;
  operation(){
    l=r=val=0;
  }
};
vector<operation> v;
vector<ll> arr , cum;

void pro(ll p,ll l,ll r){
  if (l != r) {
  lazy[p * 2] += lazy[p];
  lazy[p * 2 + 1] += lazy[p];
    lazy[p] = 0;
  }
}
void update(ll p,ll l,ll r,ll s,ll e,ll val){
  if(l>e || r<s)
    return ;
  if(l>=s && r<=e){
    lazy[p]+=val;
    pro(p,l,r);
    return;
  }
  ll mid = (l + r) / 2;
 update(p * 2, l, mid,s,e,val);
 update(p * 2 + 1, mid + 1, r,s,e,val);
}

void create(ll p,ll l,ll r){
  if(lazy[p]!=0 && l!=r)
    pro(p,l,r);
  else if(l==r){
    seg[p]+=lazy[p],arr[l]+=seg[p];
    return ;
  }
  ll mid = (l+r)/2;
  create(p*2,l,mid);
  create(p*2+1,mid+1,r);
}
int main(){

  scanf("%lld%lld%lld",&n,&m,&k);
  arr.resize(n) , v.resize(m) ,  cum.resize(m+1);
  for(int i=0;i<n;i++)
    scanf("%lld",&arr[i]);
  for(int i=0;i<m;i++){
    scanf("%lld%lld%lld",&v[i].l,&v[i].r,&v[i].val);
    v[i].l-- , v[i].r--;
  }
  for(int i=0;i<k;i++){
    ll from,to;
    scanf("%lld%lld",&from,&to);
    from--,to--;
    cum[from]+=1,cum[to+1]+=-1;
  }
  for(int i=0;i<m;i++){
    if(i!=0){
      cum[i] = cum[i]+cum[i-1];
      update(1,0,n-1,v[i].l,v[i].r,v[i].val*cum[i]);
    }else{
      cum[i] = cum[i];
      update(1,0,n-1,v[i].l,v[i].r,v[i].val*cum[i]);
    }
  }
  create(1,0,n-1);
  for(int i=0;i<n;i++)
      printf("%lld ",arr[i]);

    
  return 0;
}