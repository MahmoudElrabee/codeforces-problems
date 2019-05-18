#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n , mx , gcd;
int main(){
 #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
 #endif
    cin >> n;
    for(int i=0,item;i<n;i++) cin >> item,gcd=((i!=0)?__gcd(gcd,item):item),mx=max(mx,item);
    cout<<(((mx/gcd-n)&1)?"Alice":"Bob");    
    return 0; 
}