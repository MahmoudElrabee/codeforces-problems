#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+100;
int n,k,dp[N][50];
char s[N];
int calc(int idx,int back){
 if(idx==n) return 0;
 if(dp[idx][back]!=-1) return dp[idx][back];
 int ret = 1e9;
 for(int i=0;i<k;i++)
  if(i!=back)
   ret=min(ret,(i!=(s[idx]-'A'))+calc(idx+1,i));
 return dp[idx][back]=ret;
}
string ans = "";
void buildway(int idx,int back){
  if(idx==n) return;
  for(int i=0;i<k;i++)
    if(i!=back){
      if(dp[idx][back]==((i!=(s[idx]-'A'))+calc(idx+1,i))){
        ans+=((char)('A'+i));
        buildway(idx+1,i);
        return ;
      }
    }
}
int main(){
  memset(dp,-1,sizeof(dp));
 scanf("%d%d",&n,&k);
  scanf("%s",s);
  printf("%d\n",calc(0,30));
  buildway(0,30);
  printf("%s",ans.c_str());
 return 0;
}