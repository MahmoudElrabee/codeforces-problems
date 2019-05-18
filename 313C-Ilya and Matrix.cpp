#include <bits/stdc++.h>

using namespace std;
vector<long long int> arr;
int main(){
  long long int sum = 0;
  long long int n; scanf("%lld",&n);
  arr.resize(n);
  for(long long int i=0;i<n;i++){
  scanf("%lld",&arr[i]);
  sum+=arr[i];
  }
  sort(arr.rbegin(),arr.rend());
  for(long long int i=n/4;i>1;i/=4){
    for(long long int j=0;j<i;j++)
    sum+=arr[j];
  }
  if(n!=1) sum+=arr[0];
  printf("%lld",sum);
  return 0;
}