#include <bits/stdc++.h>

using namespace std;

int n , five , zero;

int main(){
  cin >> n;
  for(int i=0;i<n;i++){
    int test;
    cin>>test;
    if(!test) zero++;
    else five++;
  }
  int fives = 0 , sum = 0;
  for(int i=0;i<five;i++)
    sum+=5,fives=max(fives,((sum/5)*(sum%9==0)));
  if(zero&&(!fives)) return cout<<0,0;
  if(!zero || !five || !fives) return cout<<-1,0;
  while(fives--) cout<<5;
  while(zero--) cout<<0;
  return 0;
}