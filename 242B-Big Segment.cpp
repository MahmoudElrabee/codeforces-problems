#include <bits/stdc++.h>

using namespace std;

int n , mn = 1e9+10 , mx = -1e9-10 , pos=-1;
vector<pair<int,int> > v;
int main(){
 scanf("%d",&n);
 for(int i=0,x,y;i<n;i++){
  scanf("%d%d",&x,&y);
  v.push_back({x,y});
  mn = min(x,mn);
  mx = max(y,mx);
 }
 for(int i=0;i<n;i++)
  if(v[i].first <= mn && v[i].second >= mx){
   pos = i+1;
   break;
  }
 printf("%d",pos);
 return 0;
}