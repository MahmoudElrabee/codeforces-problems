#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > points;
int main(){
  cin >> n ;
  points.resize(n);
  for(int i=0;i<n;i++)
  cin >> points[i].first >> points[i].second;
  sort(points.begin(),points.end());
  int mx = -1e9 , res = 0;
  for(int i=0;i<n;i++){
    if(points[i].second < mx){
      res++;
    }else mx = points[i].second;
  }
  cout<<res<<endl;
  return 0;
}