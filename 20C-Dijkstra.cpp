#include <bits/stdc++.h>

using namespace std;


int n,m;
vector<vector<pair<int,int> > > g;
vector<long long> cost;
vector<int> vis;
vector<int> per;
void dijkstra(int strat){
    per.resize(1e6,-1);
    
    vis.resize(1e6,0);
    cost.resize(1e6,1e18);
    priority_queue<pair<long long,int> > q;
    //                  cost      node
    q.push(make_pair(0,strat));
    cost[1]=0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            long long c = -q.top().first , node = q.top().second;
            q.pop();
            if(vis[node]) continue;
            vis[node]=1;
            for(int i=0;i<g[node].size();i++){
                long long nc = c + g[node][i].second;
                if(nc < cost[g[node][i].first]){
                    cost[g[node][i].first] = nc;
                    q.push(make_pair(-nc,g[node][i].first));
                    per[g[node][i].first] = node;
                }
            }
        }
    }
}
int main(){
    cin >> n >> m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        
        int from , to , cost;
        cin >> from >> to >> cost;
        g[from].push_back(make_pair(to,cost));
        g[to].push_back(make_pair(from,cost));
        
    }
    
    dijkstra(1);
    
    if(cost[n] == 1e18) return cout<<-1,0;
    vector<int> path;
    while(per[n]!=-1) path.push_back(n),n=per[n];
    reverse(path.begin(),path.end());
    cout<<1<<" ";
    for(auto x : path) cout<<x<<" ";
    
    return 0;
}