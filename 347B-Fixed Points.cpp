#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
int n;
vector<int> v;
int main(){
 #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
 #endif
 cin >> n;
 v.resize(n);
 int ans = 0;
 for(int i=0;i<n;i++) cin >> v[i] , ans += v[i]==i;
 if(ans != n) ans++;
 for(int i=0;i<n;i++) if(i!=v[i] && v[v[i]]==i) {ans++; break;}
 cout<<ans; 
 return 0;
 
}