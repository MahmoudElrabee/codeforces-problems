#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n;
vector<pair<ll,string> > v;
vector<pair<ll,ll> > item;
map<ll,ll> mp;
map<ll,stack<string> > prnt;
int main(){
 cin >> n;
 v.resize(n) , item.resize(n);
 for(int i=0;i<n;i++){
  cin>>v[i].second>>v[i].first;
  prnt[v[i].first].push(v[i].second);
 }
 sort(v.begin(),v.end());
 ll have = 1 , cur = 3001;
 item[0].first=3001;
 item[0].second=0;
 if(v[0].first > 0){
  cout<<"-1";
  return 0;
 }
 for(int i=1;i<n;i++){
  if(v[i].first > have){
   cout<<"-1";
   return 0;
  }
  have++;
  for(int j=n-2;j>=v[i].first;j--)
   item[j+1]=item[j];
  if(v[i].first!=0){
   cur--;
   item[v[i].first].first=cur;
   item[v[i].first].second=v[i].first;
  }else{
   item[0].first=3001;
   item[0].second=0;
  }
 }
 
 for(int i=0;i<n;i++){
  cout<<prnt[item[i].second].top()<<" "<<item[i].first<<endl;
  prnt[item[i].second].pop();
 }
 
return 0;
}