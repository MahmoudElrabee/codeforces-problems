#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

#define p(V) for(int iiv=0;iiv<V.size();iiv++) cout<<V[iiv]<<" ";
#define mp make_pair
#define pb push_back
#define graph vector<vector<int> >
#define pf first
#define ps second
#define pq priority_queue
const int N = 2e5;
const int l = 18;
const double pi = acos(-1);

int n;
vector<int> v;
int main(){   
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin >> n;
    v.resize(n);
    int mx = 0;
    set<int> st;
    for(int i=0;i<n;i++) {cin >> v[i] , mx = v[i]>n ; if(v[i] <= n) st.insert(v[i]);}
    cout<<(n-(st.size()+mx))+mx;
    return 0;
}