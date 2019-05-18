#include <bits/stdc++.h>

using namespace std;
const int N = 2e6;
string s;
int f[N];
vector<int> choss;
void kmp(){
 int len = 0;
 for(int i=0;i<s.size();i++){
  if((s.size()-1)==i){
   if(len==0&&s[i]==s[len]) choss.push_back(1);
   while(len > 0){
    if(s[i]==s[len]) choss.push_back(len+1);
    len=f[len-1];
    if(len==0&&s[i]==s[len]) choss.push_back(1);
   }
   return ;
  }
  while(len > 0 && s[i]!=s[len])
   len=f[len-1];
  if(s[i]==s[len])
   len++;
  if(s.size()==len)
   len=f[len-1];
 }
}
void build(int last){
 int len = 0 ; f[0]=0;
 for(int i=1;i<last;i++){
  while(len > 0 && s[i]!=s[len])
   len=f[len-1];
  if(s[i]==s[len])
   len++;
  f[i]=len;
 }
}
bool find(int l,int r,int mid){
    int len = 0;
    for(int i=l;i<=r;i++){
        while(len > 0 && s[i]!=s[len])
   len=f[len-1];
  if(s[i]==s[len])
   len++;
  if(mid==len)
   return true;
    }
    return false;
}
bool check(int mid){
    build(mid);
    return find(1,s.size()-2,mid);
}
int main(){
 cin >> s;
 build(s.size()),kmp();
 int l=0,r=choss.size()-1,ans=0,mid;
 while(l<=r){
     mid=(l+r)/2;
     if(check(choss[mid])){
         ans = choss[mid];
         r=mid-1;
     }else l=mid+1;
 }
 if(!ans) cout<<"Just a legend";
 else cout<<s.substr(0,ans);
 return 0;
}