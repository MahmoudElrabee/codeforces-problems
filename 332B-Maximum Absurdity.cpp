#include <bits/stdc++.h>

using namespace std;

long long int n , k;
vector<long long int> v , dp , mx;
vector<long long int> cum;
int main(){
  cin >> n >> k;
  v.resize(n) , dp.resize(n) , mx.resize(n) , cum.resize(n);
  for(int i=0,x;i<n;i++){
    cin >> x;
    if(i==0) cum[i]=x;
    else cum[i]= x+cum[i-1];
    if((i-k+1) < 0) continue;
    dp[i-k+1] = (((i-k+1)>0)?cum[i]-cum[i-k]:cum[i]);
  }
  mx[n-1]=dp[n-1];
  for(int i=n-2;i>=0;i--) mx[i]=max(mx[i+1],dp[i]);
  long long int ans = 0;
  long long int a , b , pos;
  int idx = n-k*2;
  for(int i=0;i<=idx;i++)
    if(ans < (dp[i]+mx[i+k]))
      a = dp[i],b = mx[i+k],ans=(dp[i]+mx[i+k]);
  
  for(int i=0;i<n;i++) if(dp[i]==a) {cout<<i+1<<" ";pos=i+k;break;}
  for(int i=pos;i<n;i++) if(dp[i]==b) {cout<<i+1;break;}
  return 0;
}