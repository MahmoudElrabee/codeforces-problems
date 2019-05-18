#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
 
ll n;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll findlcm(ll arr[], int n){
    ll ans = arr[0];
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) / (gcd(arr[i], ans))); 
    return ans;
}

int main(){
 cin >> n;
 ll result = 0;
 ll n1 , n2 , n3 , r;
 if(n > 50)
  r=n-50;
 else
  r=1;
 for(int i=r;i<=n;i++)
  for(int j=r;j<=n;j++)
   for(int z=r;z<=n;z++){
    ll arr[] = {i,j,z};
    if(result < findlcm(arr,3)){
     result = findlcm(arr,3);
     n1=i,n2=j,n3=z;
    }
   }
 cout<<result;
 return 0;
}