#include <bits/stdc++.h>

using namespace std;
 
 string s ,  res  = "";
 bool at = false;
int main(){

 cin >> s;
 res+=s[0];
 for(int i=1;i<s.size();i++){
  if(s[i] == 'a' && i+1 < s.size() && !at && s[i+1] == 't' && i+2!=s.size()){
   at = 1;
   res+='@';
   i++;
  }else if(s[i]=='d' && i+2 < s.size() && s[i+1] =='o'&&s[i+2]=='t' && i+3!=s.size()){
   res+='.';
   i+=2;
  }else res+=s[i];
 }
 cout<<res;

 return 0;
}