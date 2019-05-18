#include <bits/stdc++.h>

using namespace std;
int n,m;
int dp[111][10111];
//    floor amount  
vector<vector<int> > shelves , forDp , LC , RC;
int calc(int Floor,int Amount){
  if(Floor == n || Amount <= 0){
    if(Amount == 0) return 0;
    else return -1e9;
  }
  if(dp[Floor][Amount]!=-1) return dp[Floor][Amount];
  int ret = calc(Floor+1,Amount);
  for(int i=1;i<=shelves[Floor].size();i++)
    ret = max(ret,forDp[Floor][i]+calc(Floor+1,Amount-i));
  return dp[Floor][Amount]=ret;
}
int main(){
 cin>>n>>m;
 shelves.resize(n),forDp.resize(n),LC.resize(n),RC.resize(n);
 for(int i=0;i<n;i++){
  int sz;
  cin>>sz;
  shelves[i].resize(sz),LC[i].resize(sz),RC[i].resize(sz),forDp[i].resize(sz+10);
   for(int j=0;j<sz;j++) cin>>shelves[i][j];
    //Left Cum
   LC[i][0] = shelves[i][0];
  for(int j=1;j<sz;j++) LC[i][j]=shelves[i][j]+LC[i][j-1];
  //Right Cum
    RC[i][sz-1] = shelves[i][sz-1];
  for(int j=sz-2;j>=0;j--) RC[i][j]=shelves[i][j]+RC[i][j+1];
  //ForDp
    for(int j=1;j<=sz;j++){
      for(int l = 0 ; l <= j; l++){
        int r = j-l;
        if(r>0 && l>0)
          forDp[i][j]=max(forDp[i][j],LC[i][l-1]+RC[i][sz-r]);
        if(l>0 && r==0)
          forDp[i][j]=max(forDp[i][j],LC[i][l-1]);
        if(r>0 && l==0)
          forDp[i][j]=max(forDp[i][j],RC[i][sz-r]);
      }
    }
 }
  memset(dp,-1,sizeof(dp));
  cout<<calc(0,m)<<endl;
 return 0;
}