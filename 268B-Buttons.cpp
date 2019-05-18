#include <bits/stdc++.h>
using namespace std;

long long int res = 0 , n;
int main(){
 scanf("%lld",&n);
 for(int i=1;i<=n;i++)
  res += ((n-i)*i);
 res += n;
 printf("%lld",res);
 return 0;
}