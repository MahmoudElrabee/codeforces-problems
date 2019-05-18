#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v , fp , lp;
map<int,pair<int,vector<int> > > mp;
void print(){

 for(int i=0;i<fp.size();i++)
  cout<<fp[i]<<" ";
 cout<<endl;
 for(int i=0;i<lp.size();i++)
  cout<<lp[i]<<" ";
 
}
int main(){
 cin >> n;
 v.resize(n);
 for (int i = 0; i < n; ++i){
  cin >> v[i];
  mp[v[i]].second.push_back(i);
  mp[v[i]].first = 0;
 }

 sort(v.begin(),v.end());
 int first = 0 , last = 0 , mx = 0;
 for(int i=0;i<n/2;i++){
  lp.push_back(v[i]);
  last+=v[i];
  mx=max(mx,v[i]);
 }
 for (int i = lp.size(); i < lp.size() + (n/2+(n&1)); ++i){
  fp.push_back(v[i]);
  first+=v[i];
  mx=max(mx,v[i]);
 }
 reverse(fp.begin(),fp.end());
    int l  = 0 , r = 0;
    while(abs(first-last) > mx){
  
        first -= fp[l]-lp[r];
        last += fp[l]-lp[r];
        swap(lp[l],fp[r]);
        r++,l++;
      
    }
    cout<<n/2+(n&1)<<endl;
    for(int i=0;i<fp.size();i++){
        cout<<mp[fp[i]].second[mp[fp[i]].first]+1<<" ";
        mp[fp[i]].first++;
    }
    cout<<endl<<n/2<<endl;
    for(int i=0;i<lp.size();i++){
        cout<<mp[lp[i]].second[mp[lp[i]].first]+1<<" ";
        mp[lp[i]].first++;
    }
 return 0;
}