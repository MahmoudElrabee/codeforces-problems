#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const int N = 1e5;
ll n , m , seg[25][N*4] ;
int lazy[25][N*4];
vector<int> v;
void build(int p,int bit,int l,int r,int idx){
  if(l==r){
    seg[bit][p] = 1;
    return ;
  }
  int mid = (l+r)/2;
  if(idx <= mid)
    build(p*2,bit,l,mid,idx);
  else
    build(p*2+1,bit,mid+1,r,idx);
  seg[bit][p]=seg[bit][p*2]+seg[bit][p*2+1];
}
void pro(int p,int bit,int l,int r){
  int len = (r-l+1) , need = len-seg[bit][p];
  seg[bit][p]+=need-seg[bit][p];
  if(l!=r)
    lazy[bit][p*2]=!lazy[bit][p*2],lazy[bit][p*2+1]=!lazy[bit][p*2+1];
  lazy[bit][p]=0;
}
void update(int p,int bit,int l,int r,int s,int e){
  if(lazy[bit][p]!=0) pro(p,bit,l,r);
  if(l>e||r<s) return;
  if(l>=s&&r<=e){
    int len = (r-l+1) , need = len-seg[bit][p];
    if(l!=r)
      lazy[bit][p*2]=!lazy[bit][p*2],lazy[bit][p*2+1]=!lazy[bit][p*2+1];
    seg[bit][p]+=need-seg[bit][p];
    return ;
  }
  int mid = (l+r)/2;
  update(p*2,bit,l,mid,s,e),update(p*2+1,bit,mid+1,r,s,e);
  seg[bit][p]=seg[bit][p*2]+seg[bit][p*2+1];
}

ll get(int p,int bit,int l,int r,int s,int e){
  if(lazy[bit][p]!=0) pro(p,bit,l,r);
  int len = (r-l+1);
  if(l>e||r<s) return 0;
  if(l>=s&&r<=e) return seg[bit][p];
  int mid = (l+r)/2;
  ll have= get(p*2,bit,l,mid,s,e)+get(p*2+1,bit,mid+1,r,s,e);
  return have;
}
int main(){
  cin>>n; v.resize(n);
  for(int i=0,t;i<n;i++){
    cin>>v[i];
    t=v[i];
    int idx = 0;
    while(t){
      if(t&1) build(1,idx,0,n-1,i);
      t=t>>1;
      idx++;
    }
  }
  cin>>m;
  while(m--){
    int type,l,r,x;
    cin>>type>>l>>r;
    l--,r--;
    if(type==2){
      cin>>x;
      int idx = 0;
      while(x){
        if(x&1) update(1,idx,0,n-1,l,r);
        x=x>>1;
        idx++;
      }
    }else{
      ll ans = 0 , carry = 0;
      for(int i=0;i<20;i++){ 
        int _get = get(1,i,0,n-1,l,r)+carry;
        if(_get&1) ans += (pow(2,i));
        carry = _get/2;
      }
      int idx = 20;
      while(carry){
        if(carry&1) ans += pow(2,idx);
        carry/=2;
        idx++;
      }
      cout<<ans<<endl;
    }
    
  }

  return 0;
}