#include <bits/stdc++.h>

using namespace std;

int n , k;
vector<pair<int,int> > v;
map<pair<int,int> ,int> fr;
int main(){
  cin>>n>>k;
  k--;
  v.resize(n);
  for(int i=0;i<n;i++){
    cin>>v[i].first>>v[i].second;
    v[i].second=-v[i].second;
    fr[{v[i].first,v[i].second}]++;
  }
  sort(v.rbegin(),v.rend());
  cout<<fr[{v[k].first,v[k].second}];
  return 0;
}