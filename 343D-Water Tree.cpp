#include <bits/stdc++.h>

using namespace std;
const int MAX = 500000+10;
int n , In[MAX],out[MAX],seg[4*MAX],id,rev[MAX],q,perant[MAX],lazy[4*MAX];
vector<vector<int> > g;
void dfs(int u,int p){
   perant[u]=p;
    In[u]=id;
    rev[id]=u;
    ++id;
    for(int i=0;i<g[u].size();i++)
     if(g[u][i]!=p)
         dfs(g[u][i],u);
    out[u]=id-1;
}
void pro(int p,int l,int r){
 seg[p]=1;
 if(l!=r)
  lazy[p*2]=1,lazy[p*2+1]=1;
 lazy[p]=0;
}

bool get(int p,int l,int r,int s,int e){
 if(lazy[p]!=0) pro(p,l,r);
 if(l>=s&&r<=e) return seg[p];
 int mid=(l+r)/2;
  int first = true , last = true;
  if(!(l>e||mid<s)) first = get(p*2,l,mid,s,e);
 if(!((mid+1)>e||r<s)) last = get(p*2+1,mid+1,r,s,e);
  return first&&last;
}

void updateMins(int p,int l,int r,int idx){
  if(lazy[p]!=0) pro(p,l,r);
 if(l==r){
  seg[p]=0;
  return ;
 }
 int mid=(l+r)/2;
 if(idx <= mid){
  updateMins(p*2,l,mid,idx);
  }else 
  updateMins(p*2+1,mid+1,r,idx);
  if(l!=r)
    seg[p]=seg[p*2]&&seg[p*2+1];
}

void updatePlus(int p,int l,int r,int s,int e){
 if(lazy[p]!=0) pro(p,l,r);
 if(l>e||r<s) return ;
 if(l>=s&&r<=e){
    lazy[p]=1;
  pro(p,l,r);
  return ;
 }
 int mid=(l+r)/2;
 updatePlus(p*2,l,mid,s,e),updatePlus(p*2+1,mid+1,r,s,e);
  if(l!=r)
    seg[p]=seg[p*2]&&seg[p*2+1];
}

int main(){
 cin >> n;
 g.resize(n);
 for(int i=0;i<n-1;i++){
  int from,to;
  cin>>from>>to;
  from--,to--;
  g[from].push_back(to);
  g[to].push_back(from);
 }
 dfs(0,-1);
 perant[0]=0;
  cin>>q;
  
 while(q--){
  int type , node;
  cin>>type >>node;
  node--;
  if(type == 3){
   int sum = get(1,0,n-1,In[node],out[node]);
   printf("%d\n",sum==1);
  }else if(type == 2) updateMins(1,0,n-1,In[node]);
  else {
      if(!get(1,0,n-1,In[node],out[node])) 
        updateMins(1,0,n-1,In[perant[node]]);
      updatePlus(1,0,n-1,In[node],out[node]);
    }
 }
  
 return 0;
}