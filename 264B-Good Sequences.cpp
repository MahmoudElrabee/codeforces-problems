#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n , dp[N];
bool vis[N];
vector<int> v;
vector<vector<int> > graph , Vdiv;
void Fdiv(int n){
  for(int i = 1; i * i <= n; ++i)
   if(n % i == 0) {
      if(i!=1)
      Vdiv[i].push_back(n);
    if(n / i != i && (n/i!=1))
     Vdiv[n/i].push_back(n);
   }
}
int dfs(int u){
  vis[u]=1;
  int can = 1;
  for(int i=0;i<graph[u].size();i++){
    int child = graph[u][i];
    if((!vis[child]) && (child>u)) can=max(can,1+dfs(child));
    else if(vis[child] && (child>u)) can=max(can,1+dp[child]);
  }
  return dp[u]=can;
}
int main(){
  graph.resize(N) , Vdiv.resize(N);
  scanf("%d",&n);
  v.resize(n);
  for(int i=0;i<n;i++){
    scanf("%d",&v[i]);
    Fdiv(v[i]);
  }
  for(int i=2;i<=1e5;i++)
    sort(Vdiv[i].begin(),Vdiv[i].end());
  for(int i=2;i<=1e5;i++)
    for(int j=1;j<Vdiv[i].size();j++)
      graph[Vdiv[i][j-1]].push_back(Vdiv[i][j]);
  
  int ans = 0;
  for(int i=0;i<v.size();i++){
    if(!vis[v[i]]) dfs(v[i]);
    ans=max(ans,dp[v[i]]);
  }
  printf("%d",ans);
  return 0;
}