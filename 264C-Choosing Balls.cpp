#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const int N = 1e5+100;
ll n , q , a , b;
bool vis[N];
ll best[N] , mxT = -1,smxT = -1,result;
vector<ll> v , c;
int main(){
  cin>>n>>q;
  v.resize(n),c.resize(n);
  for(int i=0;i<n;i++) cin>>v[i];
  for(int i=0;i<n;i++) cin>>c[i];
  while(q--){
    cin>>a>>b;
    memset(best,0,sizeof(best)),memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
      ll alone = v[i]*b;
      ll likeMe = v[i]*a + best[c[i]];
      if(!vis[c[i]]) likeMe = -3e18;
      ll withSomOne = -3e18;
      if(mxT != -1 && mxT != c[i]) withSomOne = best[mxT]+v[i]*b;
      if(smxT != -1 && smxT != c[i]) withSomOne = max(withSomOne,best[smxT]+v[i]*b);
      ll finall = max(alone,max(likeMe,withSomOne));
      if(vis[c[i]]) best[c[i]]=max(best[c[i]],finall);
      else best[c[i]]=finall;
      vis[c[i]]=1;
      result=max(result,finall);
      if(mxT==c[i]) continue;
      else if(smxT==c[i]){
        if(best[smxT]>best[mxT])
          swap(mxT,smxT);
        continue;
      }else{
        if(mxT==-1){mxT=c[i];continue;}
        if(best[mxT] < best[c[i]]){smxT=mxT;mxT=c[i];continue;}
        if(smxT==-1){smxT=c[i];continue;}
        if(best[smxT] < best[c[i]]) smxT=c[i]; 
      }
    }
    cout<<result<<endl;
    mxT = -1,smxT = -1,result=1LL*0;
  }
  return 0;
}