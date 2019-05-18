#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 50;
int n , m , q , dp[N][N] , DP[N][N][N][N] , node[N][N], grid[N][N];
bool valid(int x,int y){
  return x>=0&&y>=0&&x<n&&y<m;
}
void createdp(){
  for(int i=m-1;i>=0;i--)
    for(int j=n-1;j>=0;j--){
      int Right = 0 , down = 0 , digonal = 0;
      if(valid(j,i+1)) Right = dp[j][i+1];
      if(valid(j+1,i)) down = dp[j+1][i];
      if(valid(j+1,i+1)) digonal = dp[j+1][i+1];
      dp[j][i] = Right+down-digonal;
      if(grid[j][i]) continue;
      int mn = n;
      for(int col=i;col<m;col++)
        for(int row=j;row<mn;row++)
          if(grid[row][col]){
            mn=min(mn,row);
            break;
          }else node[j][i]++;
      dp[j][i]+=node[j][i];
    }
}
void creatanotherdp(){
  for(int i=m-1;i>=0;i--)
    for(int j=n-1;j>=0;j--){
      int mn = n;
      for(int col=i;col<m;col++)
        for(int row=j;row<mn;row++)
          if(grid[row][col]){
            mn=min(mn,row);
            break;
          }else DP[j][i][row][col]++;
      for(int col=0;col<m;col++)
        for(int row=n-2;row>=0;row--)
          DP[j][i][row][col]+=DP[j][i][row+1][col];
      for(int row=0;row<n;row++)
        for(int col=m-2;col>=0;col--)
          DP[j][i][row][col]+=DP[j][i][row][col+1];
    }
}
int main(){
  scanf("%d%d%d",&n,&m,&q);
  string s;
  for(int i=0;i<n;i++){
    cin>>s;
    for(int j=0;j<m;j++) 
      grid[i][j]=(s[j]-'0');
  }
  createdp();
  creatanotherdp();
  while(q--){
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    int ans = dp[x1-1][y1-1];
    ans -= dp[x1-1][y2];
    ans -= dp[x2][y1-1];
    ans += dp[x2][y2];
    int nodes = 0;
    for(int i=x1-1;i<x2;i++)
      for(int j=y1-1;j<y2;j++)
        nodes += DP[i][j][x1-1][y2]+DP[i][j][x2][y1-1]-DP[i][j][x2][y2];
    ans -= nodes;
    printf("%d\n",ans);
  }
  return 0;
}