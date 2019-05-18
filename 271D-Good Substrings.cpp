#include <bits/stdc++.h>

using namespace std;

char s[1505] , good[26];
int k , node = 0 , ans;
vector<vector<int> > v;
void insert(int l){
  if(v[node][l]==-1){
    ans++;
    v[node][l] = v.size();
    v.push_back(vector<int>(26,-1));
  }
  node = v[node][l];
}
int main(){
  v.resize(1);
  v[0].resize(26,-1);
  scanf("%s%s%d",&s,&good,&k);
  int len = strlen(s); 
  for(int i=0;i<len;i++){
    int K =0 ;
    node = 0;
    string sub = "";
    for(int j=i;j<len;j++){
      K += !(good[s[j]-'a']-'0');
      if(K > k) break;
      sub+=s[j];
      insert(s[j]-'a');
    }
  }
  printf("%d",ans);
  return 0;
}