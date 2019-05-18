#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> v;
int freq[300005];
int main(){
scanf("%d",&n);
v.resize(n);
for(int i=0;i<n;i++)
 scanf("%d",&v[i]);
long long int res = 0;
sort(v.begin(),v.end());
for(int i=0;i<n;i++)
res += abs((i+1)-v[i]);
printf("%lld",res);
}