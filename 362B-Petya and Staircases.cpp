#include <bits/stdc++.h>

using namespace std;

long long int n , m;
vector<long long int> v;
int main(){
 cin >> n >> m;
 v.resize(m);
 for(int i=0;i<m;i++) {cin>>v[i]; if(v[i]==1||v[i]==n){
  cout<<"NO";
  return 0;
 }}
 sort(v.begin(),v.end());
 long long int count = 0;
 for(int i=1;i<v.size();i++){
   if(v[i]-1 == v[i-1]) count++;
   else count = 0;
   if(count >= 2){
    cout<<"NO";
    return 0;
   }
  }
  cout<<"YES";
 return 0;
}