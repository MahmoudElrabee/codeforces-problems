#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v , dev;

bool check(int number){
 int last = -1e9;
 for(int i=1;i<=n;i++){
  if(v[i]==0 || i<last || (n-number)%number!=0) continue; 
  int j,q;
  for(j=i,q=0;q <= number;q++){
   int pos = j%n;
   if(j<n) last=max(last,j);
   if(pos == 0) pos = n;
   if(pos == i && q!=0) return true;
   if(v[pos] == 0) break;
   j+=((n-number)/number)+1;
  }
 }
 return false;
}

int main(){

 bool flg = 1;
 cin >> n;
 v.resize(n+1);
 for(int i=1;i<=n;i++) {
  cin >>v[i];
  if(v[i]==0) flg = 0;
 }
 if(flg){
  cout<<"YES";
  return 0;
 }
 for(int i = 1; i * i <= n; ++i)
 if(n % i == 0) {
  dev.push_back(i);
  if(n / i != i)
   dev.push_back(n / i);
 }


 for(int i=0;i<dev.size();i++)
  if(dev[i]!=n&&dev[i]>=3&&check(dev[i])){
   cout<<"YES";
   return 0;
  }


 cout<<"NO";
 return 0;
}