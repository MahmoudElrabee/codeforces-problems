#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+10;
int n , ans = 0 , perant[N] , seg[4*N] , die[N];
vector<int> v;
priority_queue<int> q;
void update(int p,int l,int r,int idx,int val){
 if(l==r){
  seg[p]=val;
  return ;
 }
 int mid = (l+r)/2;
 if(idx <= mid)
  update(p*2,l,mid,idx,val);
 else
  update(p*2+1,mid+1,r,idx,val);
 seg[p] = max(seg[p*2],seg[p*2+1]);
}
int get(int p,int l,int r,int s,int e){
 if(l>e||r<s) return 0;
 if(l>=s&&r<=e) return seg[p];
 int mid = (l+r)/2;
 return max(get(p*2,l,mid,s,e),get(p*2+1,mid+1,r,s,e));
}
int main(){
 memset(perant,-1,sizeof(perant));
 scanf("%d",&n);
 v.resize(n);
 for(int i=0;i<n;i++)
  scanf("%d",&v[i]);
 for(int i=v.size()-1;i>=0;i--){
  while((!q.empty())&&(-q.top())<v[i])
   perant[-q.top()]=i,q.pop();
  q.push(-v[i]);
 }
 die[0]=N;
 update(1,0,n-1,0,N);
 int mx = v[0];
 for(int i=1;i<n;i++){
  mx=max(mx,v[i]);
  if(mx == v[i]){
   die[i]=N;
   update(1,0,n-1,i,N);
   continue;
  }else if(perant[v[i]] == i-1){
   ans=max(ans,1);
   update(1,0,n-1,i,1);
  }else{
   int prnt = perant[v[i]];
   while(true){
    int have = get(1,0,n-1,prnt+1,i-1);
    if(have < die[prnt]){
     die[i]=have+1;
     update(1,0,n-1,i,have+1);
     break;
    }else prnt=perant[v[prnt]];
   }
  }
  if(die[i]!=N)
   ans=max(die[i],ans);
 }
 printf("%d",ans);
 return 0;
}
   