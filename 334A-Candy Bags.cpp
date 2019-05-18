#include <bits/stdc++.h>

using namespace std;

int n , l ,r;

int main(){
  cin >> n;
  l = 1, r = n*n;
  if(n&1) return cout<<1,0;
  for(int i=0;i<n;i++){
    for(int j=1;j<=n/2;j++)
      cout<<l<<" "<<r<<" ",l++,r--;
    cout<<endl;
  }
  return 0;
}