#include <bits/stdc++.h>
using namespace std;

 int  n , m , d;
int v[1000005];
int main(){
 
 cin >> n >> m >> d;
 for(int i=0;i<n*m;i++) cin >> v[i];
  sort(v,v+(n*m));

  int res = 1e9 ;
  int  have = 0;
 for(int i=0;i<n*m;i++){
   have = 0;
   for(int j=0;j<n*m;j++)
    if(i!=j){
     if(abs(v[i]-v[j])%d == 0){
      have += (abs(v[i]-v[j])/d);
     }else{
      cout<<"-1";
      return 0;
     }
    }
    if(have <=  res){
     res = have;
    }else break;
 }
 cout<<res;
 return 0;
}