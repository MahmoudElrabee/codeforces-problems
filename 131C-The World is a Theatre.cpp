#include <bits/stdc++.h>
//C(n, k) = n! ⁄ (k! (n−k)! ).
using namespace std;

long double fact(long double n){
  if(n==1||n==0) return 1;
  return n*fact(n-1);
}
int main(){
  
  long double n , m , t , res = 0;
  cin >> n >> m >> t;
  for(long double i=4;i<=n;i++){
    long double need = t-i;
    if(m>=need&&need>0){
      long double f = fact(n)/(fact(i)*fact(n-i)) , s = fact(m)/(fact(need)*fact(m-need));
      res += f*s;
    }
  }
  cout<<(long long)res;
  return 0;
}