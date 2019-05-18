#include <bits/stdc++.h>
using namespace std;
int n , ans;
vector<vector<pair<int,int> > > graph;
vector<int> path;
bool dfs(int u,int p){
  bool state = 0;
  int perantidx = -1;
  for(int i=0;i<graph[u].size();i++){
    int v = graph[u][i].first;
    if(v!=p)
      state |= dfs(v,u);
    else
      perantidx = i;
  }
  if((!state) && (graph[u][perantidx].second==2))
    state=1,path.push_back(u+1);
  return state;
}
int main(){
  cin >> n;
  graph.resize(n);
  for(int i=0;i<n-1;i++){
    int from , to , state;
    cin>>from>>to>>state;
    from--,to--;
    graph[from].push_back(make_pair(to,state));
    graph[to].push_back(make_pair(from,state));
  }
  dfs(0,-1);
  cout<<path.size()<<endl;
  sort(path.rbegin(),path.rend());
  for(int i=0;i<path.size();i++)
    cout<<path[i]<<" ";
  return 0;
}