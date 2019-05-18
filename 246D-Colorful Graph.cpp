#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+10;
int n , m , vis[N];
vector<vector<int> > graph;
vector<int> color;
map<int,set<int> > mp;
void dfs(int u){
  vis[u]=1;
  for(int i=0;i<graph[u].size();i++){
    int v = graph[u][i];
    if(!vis[v]) dfs(v);
    if(color[v]!=color[u]) mp[color[u]].insert(color[v]);
  }
}
int main(){
  cin >> n >> m;
  graph.resize(n);
  color.resize(n);
  int ans = 1e9;
  for(int i=0;i<n;i++){cin>>color[i]; ans=min(ans,color[i]);}
  for(int i=0;i<m;i++){
    int from,to;
    cin>>from>>to;
    from--,to--;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  for(int i=0;i<n;i++)
    if(!vis[i]) dfs(i);
  int  can = 0;
  for(map<int,set<int> >::iterator it=mp.begin();it!=mp.end();it++)
    if(it->second.size() > can) ans=it->first,can=it->second.size();
    else if(it->second.size() == can && it->first < ans) ans=it->first;
  cout<<ans;
  return 0;
}