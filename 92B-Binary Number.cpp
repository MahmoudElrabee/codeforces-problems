#include <bits/stdc++.h>

using namespace std;
string str;
int main(){
cin >> str;
reverse(str.begin(),str.end());
long long int res = 0 , lastpos = 0;
for(int i=0;i<str.size();i++)
 if(str[i] == '0'){
  res++;
  lastpos++;
 }else break;

long long int One = 0;
if(lastpos != str.size()-1){
for(int i=lastpos;i<str.size();i++){
  
  if(str[i] == '1'){
   if(i == str.size()-1){
    res+=One+2;
    break;
   }else{
    One++;
   }
  }else{
   res += One+1;
   One=1; 
  }
 
}}
cout<<res;
 return 0;

}