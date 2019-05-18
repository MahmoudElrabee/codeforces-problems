#include <bits/stdc++.h>

using namespace std;
int n , mn = 1e9 , number;
vector<int> v;
int main(){
  cin >> n;
  v.resize(10);
for(int i=0;i<9;i++) {cin >> v[i];
    if(mn>=v[i]) mn=v[i],number=i+1;
  } 
  vector<int> ans;
  while(n >= mn)
    ans.push_back(number) , n-=mn;
  if(!ans.size()) return cout<<-1,0;
  for(int i=0;i<ans.size();i++){
    int can = n + mn;
    for(int j=8;j>=ans[i];j--)
      if(v[j] <= can){
        ans[i] = j+1;
        n -= (v[j]-mn);
        break;
      }
  }
  for(int i=0;i<ans.size();i++) cout<<ans[i];
  return 0;
}