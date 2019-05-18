#include <bits/stdc++.h>

using namespace std;

long long n , k , l , r , sall , sk;
vector<long long> v;


int main(){
  
  
  cin >> n >> k >> l >> r >> sall >> sk;
  long long Mod = sk % k;
  long long Res = sk/k;
  for(int i=0;i<k;i++)
    v.push_back(Res);
    
      for(int i = 0; i<Mod;i++)
      v[i]++;
    
  
  

  
  long long Mod1 = 0 , Res1 = 0;
  if((n-k) != 0){
  Mod1 = (sall - sk) % (n-k);
  Res1 = (sall - sk) / (n-k);
  }
  for(int i=0;i<(n-k);i++)
    v.push_back(Res1);
  
    
      for(int i = k; i<k+Mod1;i++)
      v[i]++;
    
  
  
  for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
  
return 0;
}