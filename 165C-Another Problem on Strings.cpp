#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int k;
string s;
vector<int> cumSum;
int freq[1000005];
int main(){

 cin >> k ;
 cin >> s;
 cumSum.resize(s.size());
 for(int i=0;i<s.size();i++){
  if(i==0){
   if(s[i]=='1') cumSum[0]=1;
  }else{
   if(s[i]=='1'){
    cumSum[i]=cumSum[i-1]+1;
   }else cumSum[i]=cumSum[i-1];
  }
 }
 ll res = 0;
 for(int i=0;i<cumSum.size();i++){
  if(cumSum[i]==k) res++;
  if(cumSum[i]-k >= 0)
  res += freq[cumSum[i]-k];
  freq[cumSum[i]]++;
 }
 cout<<res;
 return 0;
}