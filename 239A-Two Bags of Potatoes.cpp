#include <bits/stdc++.h>

using namespace std;

int n , m ,k;
int main(){
 cin >> n >> k >> m;
 int MOD = k-n%k;
 bool flg = true;
 if(MOD == k && m == n){
  cout<<-1;
  return 0;
 }
 while(MOD+n <= m){
  flg = false;
  cout<<MOD<<" ";
  MOD+=k;
 }
 if(flg)
  cout<<-1;
 return 0;
}