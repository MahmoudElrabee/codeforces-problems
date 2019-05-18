#include <bits/stdc++.h>

using namespace std;

long long int n,m;
vector<long long int> v,v2;
long long int res[1000000] , End[1000000] ,Visted[1000000];
vector<pair<long long int,long long int> > v1,q;
int main(){
  
  cin >> n >> m;
  v.resize(n);
  for(long long int i=0;i<n;i++)
  cin >> v[i];
  sort(v.rbegin(),v.rend());
  for(long long int i=0,x,y;i<m;i++){
    cin >> x >> y;
    x--,y--;
     q.push_back({x,y});
    res[x]++;
    res[y+1]--;
  }
  for(long long int i=1;i<n;i++)
  res[i]+=res[i-1];
  for(long long int i=0;i<n;i++)
  v1.push_back({res[i],i});
  sort(v1.rbegin(),v1.rend());
  for(long long int i=0;i<v1.size();i++){
  Visted[v1[i].second]=1;
  End[v1[i].second]=v[i];
  v[i]=-1;
  }
  sort(v.rbegin(),v.rend());
  for(long long int i=0,q=0;i<n;i++){
    if(!Visted[i]){End[i]=v[q];q++;}
  }
  for(long long int i=0;i<n;i++){
    if(i==0) res[i]=End[i];
    else res[i]=res[i-1]+End[i];
  }
  long long int sum = 0;
  for(long long int i=0;i<q.size();i++){
  if(q[i].first == 0) sum+=res[q[i].second];
  else sum+=res[q[i].second]-res[q[i].first-1];
  }
  cout<<sum;
  return 0;
}