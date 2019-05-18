#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n , dp[200001];
vector<vector<pair<int,bool> > > graph;
int dfsone(int u,int parent){
 int amount = 0; 
 for(int i=0;i<graph[u].size();i++){
  int v = graph[u][i].first;
  bool state = !graph[u][i].second;
  if(v!=parent){
   amount+=state;
   amount+=dfsone(v,u);
  }
 }
 return amount;
}
void dfsall(int u,int parent){
 for(int i=0;i<graph[u].size();i++){
  int v = graph[u][i].first;
  bool state = graph[u][i].second;
  if(v!=parent){
   dp[v]=dp[u]+((state)?1:-1);
   dfsall(v,u);
  } 
 }
}
int main(){
 scanf("%d",&n);
 graph.resize(n+1);
 for(int i=0;i<n-1;i++){
  int from , to;
  scanf("%d%d",&from,&to);
  graph[from].push_back({to,1});
  graph[to].push_back({from,0});
 }
 dp[1] = dfsone(1,0);
 dfsall(1,0);
 int mn = 1e9;
 for(int i=1;i<=n;i++)
  mn=min(mn,dp[i]);
 printf("%d\n",mn);
 for(int i=1;i<=n;i++)
  if(dp[i]==mn)
   printf("%d ",i);
 return 0;
}