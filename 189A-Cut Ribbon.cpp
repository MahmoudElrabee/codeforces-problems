#include <bits/stdc++.h>

using namespace std;
int dp[10000000];
int a , b , c , need;
int rec(int sum){
  if(sum < 0) return -1e9;
  if(sum == 0) return 0;
  if(dp[sum]!=-1) return dp[sum];
  int r1,r2,r3;
  r1 = 1+rec(sum-a);
  r2 = 1+rec(sum-b);
  r3 = 1+rec(sum-c);
  dp[sum] =max(r1,max(r2,r3)); 
  return dp[sum];
}

int main(){

  memset(dp,-1,sizeof dp);
  cin >> need >> a >> b >> c;
  cout<<rec(need)<<endl;

  return 0;
}