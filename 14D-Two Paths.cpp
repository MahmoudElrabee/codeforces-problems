#include <bits/stdc++.h>

using namespace std;
const int N = 201;
vector<int> path;
int n , ans , vis[N], mx;
vector<vector<int> > graph;
void getLen(int u,int len,int cant){
  vis[u]=1;
  mx=max(mx,len);
  for(int i=0;i<graph[u].size();i++){
    int v=graph[u][i];
    if(!vis[v] && v!=cant)
      getLen(v,len+1,cant);
  }
}
void dfs(int u,int cant){
  vis[u]=1;
  for(int i=0;i<graph[u].size();i++){
    mx=0;
    int v = graph[u][i];
    if(!vis[v] && v!=cant){
      getLen(v,1,cant);
      path.push_back(mx);
    }
  }
}
int main(){
  cin>>n;
  graph.resize(n);
  for(int i=0;i<n-1;i++){
    int from,to;
    cin>>from>>to;
    from--,to--;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  
  
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){
      memset(vis,0,sizeof(vis));
      path.clear();
      int first =0, second=0;
     // todo
      dfs(i,j);
      sort(path.rbegin(),path.rend());
      if(path.size()>1)
        first=path[0]+path[1];
      else if(path.size()==1)
        first=path[0];
      path.clear();
      dfs(j,i);
      sort(path.rbegin(),path.rend());
      if(path.size()>1)
        second=path[0]+path[1];
      else if(path.size()==1)
        second=path[0];
     //
      ans=max(ans,first*second);
    }
  cout<<ans;
  return 0;
}