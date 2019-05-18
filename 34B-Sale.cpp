#include <bits/stdc++.h>

using namespace std;

int n , m;
vector<int> v;
int main(){
scanf("%d%d",&n,&m);
v.resize(n);
for(int i=0;i<n;i++) scanf("%d",v.begin()+i);
sort(v.begin(),v.end());
int res = 0;
for(int i=0;i<m;i++)
 if(v[i] < 0) res += abs(v[i]);
printf("%d",res);
 return 0;
}