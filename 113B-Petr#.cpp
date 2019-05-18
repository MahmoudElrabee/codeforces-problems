#include <bits/stdc++.h>

using namespace std;
const int N = 2222;
string t , a , b;
vector<int> starts;
int e[N];
void getstart(){
  for(int i=0;i<t.size();i++){
    if(t.size()-i < a.size()) return ;
    int s = 0 , flg = false;
    for(int j=i;s<a.size();s++,j++)
      if(t[j]!=a[s]){flg=true;break;}
    if(!flg) starts.push_back(i);
  }
}
void getrends(){
  for(int i=0;i<t.size();i++){
    if(t.size()-i < b.size()) return ;
    int s = 0 , flg = false;
    for(int j=i;s<b.size();s++,j++)
      if(t[j]!=b[s]) flg=true;
    if(!flg) e[i+(b.size()-1)]=1;
  }
}
vector<vector<int> > v;
int node , ans;
void insert(int l,int idxS,int idxE){
  if(v[node][l]==-1){
    if(e[idxE] && ((idxE-idxS+1)>=a.size() && (idxE-idxS+1)>=b.size())) ans++;
    v[node][l] = v.size();
    v.push_back(vector<int>(26,-1));
  }
  node = v[node][l];
}
int main(){
  cin>>t>>a>>b;
  v.resize(1);
  v[0].resize(26,-1);
  getstart() , getrends();
  for(int i=0;i<starts.size();i++){
    node = 0;
    for(int j=starts[i];j<t.size();j++)
      insert(t[j]-'a',starts[i],j);
  }
  cout<<ans;
  return 0;
}