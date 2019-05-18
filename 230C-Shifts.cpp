 #include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n , m;
char grid[110][10010];
vector<vector<ll> > nxt;
void isexit(){
 bool flg = false;
 for(int i=1;i<=n;i++)
  if(nxt[i].size()==0)
   flg = true;
 if(flg){
  puts("-1");
  exit(0);
 }
}
ll getright(ll row,ll idx){
 if(grid[row][idx]=='1')
  return idx;
 ll l = 0 , r = nxt[row].size()-1 , mid , ans=2e9;
 while(l<=r){
  mid=(l+r)/2;
  if(nxt[row][mid] > idx){
   ans=min(nxt[row][mid],ans);
   r=mid-1;
  }else l=mid+1;
 }
 return ((ans!=2e9)?ans:-1);
}
ll getleft(ll row,ll idx){
 if(grid[row][idx]=='1')
  return idx;
 ll l = 0 , r=nxt[row].size()-1 , mid , ans=-2e9;
 while(l<=r){
  mid=(l+r)/2;
  if(nxt[row][mid] < idx){
   ans=max(ans,nxt[row][mid]);
   l=mid+1;
  }else r=mid-1;
 }
 return ((ans!=-2e9)?ans:-1);
}
ll get(ll idx){
 ll result = 0;
 for(int i=1;i<=n;i++){
  ll right = getright(i,idx) , left = getleft(i,idx);
  ll firstchose = min(right-idx,(m-right)+idx);
  ll secondchose = min(idx-left,(left-1)+(m-idx+1));
  ll theardcose = min(nxt[i][nxt[i].size()-1]-idx,(m-nxt[i][nxt[i].size()-1])+idx);
  ll fourthcose = min(idx-nxt[i][0],(nxt[i][0]-1)+(m-idx+1));
  bool flg1=true , flg2=true;
  if(nxt[i][0] > idx)
   flg2=false;
  if(nxt[i][nxt[i].size()-1] < idx)
   flg1=false;
  ll reshere = 2e9;
  if(flg1&&flg2)
   reshere=min(theardcose,secondchose);
  else if(flg1&&(!flg2))
   reshere=theardcose;
  else if(flg2&&(!flg1))
   reshere=fourthcose;
  if(right!=-1&&left==-1)
   result+=min(firstchose,reshere);
  if(left!=-1&&right==-1)
   result+=min(secondchose,reshere);
  if(left!=-1&&right!=-1)
   result+=min(reshere,min(secondchose,firstchose));
 }
 return result;
}
int main(){
 cin>>n>>m;
 nxt.resize(n+10);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++){
   cin>>grid[i][j];
   if(grid[i][j]=='1')
    nxt[i].push_back(j);
  }
 isexit();
 ll ans = 2e9;
 for(int i=1;i<=m;i++)
  ans=min(ans,get(i));
 cout<<ans;
 return 0;
}