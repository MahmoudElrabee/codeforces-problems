#include <bits/stdc++.h>

using namespace std;
string s;
int main(){
  cin>>s;
  int pos = -1;
  for(int i=0;i<s.size();i++)
    if(s[i]=='0'){
      pos=i;
      break;
    }
  if(pos!=-1){
    for(int i=0;i<s.size();i++)
      if(i!=pos) cout<<s[i];
    return 0;
  }
  for(int i=1;i<s.size();i++)
    cout<<s[i];
  return 0;
}