#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll s , e;
ll dp[20][11][2][2][2][2];
vector<int> S,E;
ll calc(int idx,int first,bool sml,bool bg,bool larg,bool Sbg){
  if(idx == E.size()) return 0;
  if(dp[idx][first][sml][bg][larg][Sbg]!=-1) return dp[idx][first][sml][bg][larg][Sbg];
  ll ret = 0;
  int forWhat = 9;
  if(((Sbg)||((!Sbg)&&(!larg))) && ((idx+1)==E.size())) forWhat=E[idx];
  for(int i=((idx!=0)?0:1);i<=forWhat;i++){
    if(Sbg&&(idx+1==E.size())) return 0;
    if(bg&&((idx+1)==S.size())&&i==first) ret++;
    if((!sml)&&(!bg)&&((idx+1)==S.size())&&((first==i||idx==0)&&(i>=S[idx]))) ret++;
    if((idx>=S.size())&&(i==first)) ret++;
    ret += calc(idx+1,((idx==0)?i:first),(bg)?0:((idx<S.size())?i<S[idx]:0)||sml,(sml)?0:((idx<S.size())?i>S[idx]:0)||bg,((Sbg)?0:i<E[idx])||larg,((larg)?0:i>E[idx])||Sbg);
  }
  return dp[idx][first][sml][bg][larg][Sbg]=ret;
}
int main(){
  memset(dp,-1,sizeof(dp));
  cin>>s>>e;
  while(s){
    S.push_back(s%10);
    s/=10;
  }
  while(e){
    E.push_back(e%10);
    e/=10;
  }
  reverse(S.begin(),S.end());
  reverse(E.begin(),E.end());
  cout<<calc(0,10,0,0,0,0);
  return 0;
}