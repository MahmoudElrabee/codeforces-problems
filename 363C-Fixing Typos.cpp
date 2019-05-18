#include <bits/stdc++.h>

using namespace std;
string s;

int main(){
  cin >> s;
  string ans = "";
  for(int i=0;i<s.size();i++){
    if(ans.size()>=2 && s[i]==ans[ans.size()-1] && s[i]==ans[ans.size()-2]) continue;
    if(ans.size()>=3 && s[i]==ans[ans.size()-1] && ans[ans.size()-2]==ans[ans.size()-3]) continue;
    ans+=s[i];
  }
  cout<<ans;
  return 0;
}