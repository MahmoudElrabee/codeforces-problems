/*

        keep calm , i don't understand what I wrote

*/

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll a , b , aFirst , bFirst;
string str;
vector<pair<ll,ll> > moves;
void tackit(ll &x , ll &y , char sign , bool flg){
 if(!flg){
  if(sign == 'U') y--;
  else if(sign == 'R') x--;
  else if(sign == 'D') y++;
  else if(sign == 'L') x++;
 }else{
  if(sign == 'U') y++;
  else if(sign == 'R') x++;
  else if(sign == 'D') y--;
  else if(sign == 'L') x--;
 }
}
bool BS(ll x,ll def1,ll y ,ll def2){
 if((def1 < 0 && x > 0) || (def1 > 0 && x < 0)) return false;
 else if((def2 < 0 && y > 0) || (def2 > 0 && y < 0)) return false;
 ll l = 1 , r = 1e9 , mid;
 while(l<=r){ 
  mid=(l+r)/2;
  if(mid*def1 == x && mid*def2 == y) return true;
  else if(mid*def1 < x && x >= 0) l=mid+1;
  else if(mid*def1 > x && x < 0) l=mid+1;
  else if(mid*def2 < y && y >= 0) l=mid+1;
  else if(mid*def2 > y && y < 0) l=mid+1;
  else r=mid-1;
 }
 return false;
}
bool check(ll x , ll y){
 ll def1 = aFirst-0 , def2 = bFirst-0;
 if(BS(x,def1,y,def2)) return true;
 return false;
}
int main(){
 cin >> a >> b;
 cin >> str;
 for(int i=0;i<str.size();i++){
  if(a==aFirst&&b==bFirst){
   cout<<"Yes";
   return 0;
  }
  tackit(aFirst,bFirst,str[i],1);
  if(a==aFirst&&b==bFirst){
   cout<<"Yes";
   return 0;
  }
 }
 ll ha,hb;
 if(check(a,b)){
  cout<<"Yes";
  return 0;
 }
 for(int i=0;i<str.size();i++){
   ha=a,hb=b;
   for(int j=i;j>=0;j--)
    tackit(ha,hb,str[j],0);
   if(check(ha,hb)){
    cout<<"Yes";
    return 0;
   }
 }
 if(a==0&&b==0){
  cout<<"Yes";
  return 0;
 }
 cout<<"No";
 return 0;
}