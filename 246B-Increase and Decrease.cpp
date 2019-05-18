#include <bits/stdc++.h>

using namespace std;

long long int n;
vector<long long int> v;

int main(){
 cin >> n;
 v.resize(n);
 for(int i=0;i<n;i++) cin >> v[i];
  long long int have = 0;
 for(int i=0;i<n;i++){
  if(i == n-1) v[i] += have;
  else if(v[i] > 2) have += v[i]-2;
  else if(v[i] < 2) have -= 2-v[i]; 
 }
 
 bool can = false;


 if(v[n-1] > 2){
  for(int i=1;i<v[n-1];i++){
   long long int num = v[n-1]-(i*(n-1));
   if(2+i == num){
    can = true;
    break;
   }
  }
 }else if(v[n-1] < 2){
  for(int i=1;i<2-v[n-1];i++){
   long long int num = ((n-1)*i)+v[n-1];
   if(num > 2-i)
    break;
   else if(num == 2-i) can = true;
  }
 }else if(v[n-1] == 2)
 can = true;

 cout<<(n-1)+can;

 return 0;
}