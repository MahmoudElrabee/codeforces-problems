#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;



#define mp make_pair
#define pb push_back
#define graph vector<vector<int> >
#define pf first
#define ps second
const int N = 5e5+1000;

int n , query;
vector<int> root , ans ;
vector<string> name;
vector<vector<pair<int,int> > > q;
graph tree;
unordered_map<int,unordered_map<string,bool> > fr[N];
int depth[N] , sz[N];



void dfs1(int u,int p,int d){
    depth[u]=d;
    sz[u]=1;
    for(auto i : tree[u])
        if(i!=p) dfs1(i,u,d+1),sz[u]+=sz[i];
}

void dfs(int u,int p){
    int mx = -1 , bigchilde = -1;
    
    for(auto i : tree[u])
        if(mx < sz[i]) mx=sz[i],bigchilde=i;

    for(auto i : tree[u])
        if(i!=p&&i!=bigchilde)
            dfs(i,u);

    
    if(bigchilde!=-1)
        dfs(bigchilde,u) , fr[u].swap(fr[bigchilde]);

    fr[u][depth[u]][name[u]]=1;

    for(auto i : tree[u])
        if(i!=p&&i!=bigchilde)
            for(auto it1=fr[i].begin();it1!=fr[i].end();it1++)
                for(auto it2=it1->ps.begin();it2!=it1->ps.end();it2++)
                    fr[u][it1->pf][it2->pf]=1;
    
    //here we go
    for(auto i : q[u])
        ans[i.ps]=fr[u][i.pf+depth[u]].size();
    

}
void clear(int u,int p){
    sz[u]=1;
    depth[u]=0;
    fr[u].clear();
    for(auto i : tree[u])
        if(i!=p) clear(i,u);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&n);
    tree.resize(n);
    name.resize(n);
    for(int i=0;i<n;i++){
        string name ;
        int per;
        cin >> name;
        scanf("%d",&per);
        per--;
        if(per == -1) root.pb(i);
        else tree[per].pb(i);
        ::name[i]=name;
    }
    scanf("%d",&query);
    ans.resize(query);
    q.resize(n);
    for(int i=0;i<query;i++){
        int node , d;
        scanf("%d%d",&node,&d);
        node--;
        q[node].pb(mp(d,i));
    }
    for(auto i : root){
        dfs1(i,-1,0);
        dfs(i,-1);
        clear(i,-1);
    }
    for(auto i : ans) printf("%d\n",i);
    return 0;
}