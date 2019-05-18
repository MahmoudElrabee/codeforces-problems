#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


ll n , t ;
vector<ll> a , seg;
ll bulid(ll p , ll l , ll r,ll count){
 if(l==r){
  seg[p] = a[l];
  return 0;
 }
 ll mid = (l+r)/2;
 bulid(p*2,l,mid,count-1);
 bulid(p*2+1,mid+1,r,count-1);
 if(count&1) return seg[p]=seg[p*2]|seg[p*2+1];
 return seg[p]=seg[p*2]^seg[p*2+1];
}


void update(ll p ,ll l ,ll r ,ll idx ,ll val,ll count){
 if(l==r&&r==idx){
  a[idx]=val;
  seg[p]=val;
  return ;
 }
 ll mid=(l+r)/2;
 if(idx <= mid)
  update(p*2,l,mid,idx,val,count-1);
 else
  update(p*2+1,mid+1,r,idx,val,count-1);
 if(count&1)
  seg[p]=seg[p*2]|seg[p*2+1];
 else seg[p]=seg[p*2]^seg[p*2+1];
}

int main(){
 scanf("%lld%lld",&n,&t);
 n=pow(2,n);
 a.resize(n), seg.resize(n*4);
 for(int i=0;i<n;i++) 
  scanf("%lld",&a[i]);
 bulid(1,0,n-1,log2(n));

 while(t--){
  ll  e , v;
  scanf("%lld%lld",&e,&v);
  update(1,0,n-1,e-1,v,log2(n));
  printf("%lld\n",seg[1]);
 }
 return 0;
}