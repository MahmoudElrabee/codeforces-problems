#include <bits/stdc++.h>
using namespace std;
int n ,realCmp,vis[111];
struct point{
  int x, y;
  point(){
    x=y=0;
  }
};
point points[111];
vector<vector<int> > g;
void dfs(int u){
  vis[u]=1;
  for(int i=0;i<g[u].size();i++)
    if(!vis[g[u][i]])
      dfs(g[u][i]);
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>points[i].x>>points[i].y;
  g.resize(n);
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      if(points[i].x==points[j].x||points[i].y==points[j].y)
        g[i].push_back(j),g[j].push_back(i);
    
  for(int i=0;i<n;i++)
    if(!vis[i])
      dfs(i),realCmp++;
  cout<<realCmp-1;
  return 0;
}