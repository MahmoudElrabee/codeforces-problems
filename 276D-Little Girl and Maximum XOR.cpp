#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 60;
int LeftBits[N] , RightBits[N];
ll l , r;
int main(){
  cin >> l >> r;
  ll have = l , idx = 0;
  while(have){
    if(have&1) LeftBits[idx]=1;
    have=have>>1;
    idx++;
  }
  have = r , idx = 0;
  while(have){
    if(have&1) RightBits[idx]=1;
    have=have>>1;
    idx++;
  }
  ll ans = 0;
  bool flg = false;
  for(int i=59;i>=0;i--){
    if(flg){ans+=(ll)pow(2,i); continue;}
    if(LeftBits[i]==RightBits[i]) continue;
    if(RightBits[i]!=LeftBits[i]){
      flg=true;
      ans+=(ll)pow(2,i);
    }
  }
  cout<<ans;
  return 0;
}