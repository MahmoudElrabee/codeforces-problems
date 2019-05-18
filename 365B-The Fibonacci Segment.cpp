#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int main(){

 cin >> n;
 if(n == 1){
  cout<<1;
  return 0;
 }
 v.resize(n);
 for(int i=0;i<n;i++) cin >> v[i];
 int l = 0 , r = 2 , ans = 2 , have = 2;
 for(r;r<n;r++){
  if(v[r] == v[r-1]+v[r-2]) {have++; ans = max(ans,have);}
  else have = 2;
 }
 cout<<ans;

 return 0;
}