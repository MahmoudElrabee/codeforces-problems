#include <bits/stdc++.h>

using namespace std;

int n;
int main(){
 cin >> n;
 cout<<n<<" ";
 while(n >= 2){
  for(int i=2;;i++)
   if(n%i==0){
    cout<<n/i<<" ";
    n/=i;
    break;
   }
 }
 return 0;
}