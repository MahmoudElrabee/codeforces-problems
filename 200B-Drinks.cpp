#include <bits/stdc++.h>

using namespace std;

int main(){
  long long int n;
  cin >> n;
  long long int sum = 0;
  for(int i=0 , test;i<n;i++){
    cin >> test;
    sum+=test;
  }
  cout<<setprecision(12)<<fixed<<((sum*1.0)/(n*1ll*100))*100;
  return 0;
}