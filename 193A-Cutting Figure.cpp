#include <bits/stdc++.h>
using namespace std;
int n , m , c;
char grid[55][55];
bool valid(int x,int y){
  return (x>=0&&y>=0&&x<n&&y<m&&grid[x][y]=='#');
}
bool vis[55][55];
int dx[]={1,-1,0,0} , dy[]={0,0,1,-1};
void dfs(int x,int y){
  vis[x][y]=1;
  for(int i=0;i<4;i++){
    int dx_ = dx[i]+x , dy_ = dy[i]+y;
    if((!vis[dx_][dy_])&&valid(dx_,dy_))
      dfs(dx_,dy_);
  }
}
void check(int x,int y){
  memset(vis,0,sizeof(vis));
  int cmp = 0;
  vis[x][y]=1;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(!vis[i][j]&&grid[i][j]=='#')
        cmp++,dfs(i,j);
  if(cmp>1)
    cout<<1,exit(0);
}
int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
      cin>>grid[i][j];
      c+=grid[i][j]=='#';
    }
  if(c==1) return cout<<-1,0; 
  else if(c==2){
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(grid[i][j]=='#'){
          if(valid(i+1,j) && grid[i+1][j]=='#')
            return cout<<-1,0;
          else if(valid(i-1,j) && grid[i-1][j]=='#')
            return cout<<-1,0;
          else if(valid(i,j+1) && grid[i][j+1]=='#')
            return cout<<-1,0;
          else if(valid(i,j-1) && grid[i][j-1]=='#')
            return cout<<-1,0;
        }
    return cout<<0,0;
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
     if(grid[i][j]=='#')
      check(i,j);
  int ans = 1e9;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(grid[i][j]=='#'){
        int how = (valid(i+1,j)&&grid[i+1][j]=='#');
        how += (valid(i-1,j)&&grid[i-1][j]=='#');
        how += (valid(i,j-1)&&grid[i][j-1]=='#');
        how += (valid(i,j+1)&&grid[i][1+j]=='#');
        if(how+1 < c)
          ans=min(ans,how);
      }
  cout<<((ans!=1e9)?ans:-1);
  return 0;
}