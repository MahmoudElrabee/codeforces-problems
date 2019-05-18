#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;



#define mp make_pair
#define pb push_back
#define graph vector<vector<int> >
#define pf first
#define ps second
const int N = 1e5+1000;
const int l = 18;

int n , dp[N][l+1] , m , depth[N] , sz[N];
graph tree;

int getk(int u,int k){
    for(int j=l;j>=0;j--)
        if(dp[u][j]!=-1 && k!=0 && pow(2,j)<=k) u=dp[u][j],k-=pow(2,j);
    return (!k)?u:-1;
}

void build(){
    for(int j=1;j<=l;j++)
        for(int i=0;i<n;i++)
            dp[i][j] = (dp[i][j-1]!=-1)?dp[dp[i][j-1]][j-1]:-1;
}

vector<int> q[N];
map<pair<int,int>,int> ans;
vector<pair<int,int> > query;

void getsz(int u,int p,int d){
    sz[u]=1;
    depth[u]=d;
    for(auto i:tree[u])
        if(i!=p)
            getsz(i,u,d+1),sz[u]+=sz[i];
}

vector<int> *cnt[N];
int da[N];
void dfs(int u,int p,bool keep){
    int mx = -1 , bigchilde = -1;
    
    for(auto i:tree[u])
        if(sz[i]>mx && p!=i) mx=sz[i],bigchilde=i;
    
    for(auto i:tree[u])
        if(i!=bigchilde && i!=p) dfs(i,u,0);

    if(bigchilde!=-1)
        dfs(bigchilde,u,1) , cnt[u]=cnt[bigchilde];
    else
        cnt[u] = new vector<int> ();

    cnt[u]->pb(u);
    da[depth[u]]++;

    for(auto i:tree[u])
        if(i!=p&&i!=bigchilde)
            for(auto j: *cnt[i])
                cnt[u]->pb(j) , da[depth[j]]++;

    //here we go
    for(auto i:q[u])
        ans[mp(u,i)]=da[i]-1;
    

    if(!keep)
        for(auto i:*cnt[u])
            da[depth[i]]--;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(dp,-1,sizeof(dp));
    cin >> n;
    tree.resize(n);
    vector<int> root;
    for(int i=0;i<n;i++){
        int per;
        cin >> per;
        per--;
        if(per>=0) tree[per].pb(i) , tree[i].pb(per) , dp[i][0]=per;
        else root.pb(i);
    }
    build();
    for(auto i:root)
        getsz(i,-1,0);
    cin >> m;
    query.resize(m);
    for(int i=0;i<m;i++){
        int node , per;
        cin >> node >> per;
        node--;
        int kper = getk(node,per);
        if(kper!=-1) q[kper].pb(per+depth[kper]);
        query[i].pf = kper , query[i].ps = per+depth[kper];
    }
    for(auto i:root)
        dfs(i,-1,0);
    for(int i=0;i<m;i++)
        cout<<ans[mp(query[i].pf,query[i].ps)]<<" ";

    return 0;
}