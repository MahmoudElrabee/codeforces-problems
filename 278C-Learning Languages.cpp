#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > p , l , forNewSol;
int n , m;
int VistedP[1000];
void dfs(int u){
  VistedP[u]=1;
  for(int i=0;i<forNewSol[u].size();i++)
  if(!VistedP[forNewSol[u][i]]) dfs(forNewSol[u][i]);
}
int main(){
  int zero = 0;
  
  cin >> n >> m;
  p.resize(n+1);
  l.resize(m+1);
  for(int i=1,num;i<=n;i++){
    cin >> num;
    if(num==0) zero++;
    for(int j=0,test;j<num;j++){
      cin >> test;
      p[i].push_back(test);
      l[test].push_back(i);
    }
  }
  forNewSol.resize(n+1);
  for(int i=1;i<=n;i++){
    for(int j=0;j<p[i].size();j++){
      for(int z=0;z<l[p[i][j]].size();z++){
         forNewSol[i].push_back(l[p[i][j]][z]);
      }
    }
  }
  
  
  p.clear() , l.clear();
  int res = 0;
  for(int i=1;i<=n;i++){
    if(!VistedP[i]&&forNewSol[i].size()>0){
      res++;
      dfs(i);
    }
  }
  if(res!=0)
  cout<<res-1+zero;
  else cout<<zero;
return 0;
}