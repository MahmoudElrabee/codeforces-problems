#include <bits/stdc++.h>

using namespace std;
const int N = 1e7;
int n , vis[N];
vector<int> bp[30];
int main(){
  cin>>n;
  for(int i=0;i<n;i++) {
    int idx = 0 , have;
    cin>>have;
    if(have==0) vis[have]=1;
    while(have){
      if(have&1) bp[idx].push_back(i);
      idx++;
      have=have>>1;
    }
  }
  for(int i=0;i<=25;i++)
    if(bp[i].size() > 0)
      sort(bp[i].begin(),bp[i].end());
  for(int i=0;i<n;i++){
    vector<pair<int,int> > access;
    for(int j=0;j<=25;j++){
      if(bp[j].size()==0) continue;
      int l = 0 , r = bp[j].size()-1 , mid , ans = -1;
      while(l<=r){
        mid=(l+r)/2;
        if(bp[j][mid] >= i){
          ans = bp[j][mid];
          r=mid-1;
        }else l=mid+1;
      }
      if(ans!=-1) access.push_back(make_pair(ans,j));
    }
    if(access.size() > 0)
      sort(access.begin(),access.end());
    if(access.size()==1){
      vis[(int)pow(2,access[0].second)]=1;
    }else if(access.size() > 0){
      int have = pow(2,access[0].second);
      for(int j=1;j<access.size();j++){
        int pos = access[j].first , bit = access[j].second;
        if(pos!=access[j-1].first) vis[have]=1;
        have+=pow(2,bit);
      }
      vis[have]=1;
    }
    access.clear();
  }
  int ans = 0;
  for(int i=0;i<1e7;i++) ans+=vis[i];
  cout<<ans;
  return 0;
}