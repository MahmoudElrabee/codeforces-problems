#include <bits/stdc++.h>

using namespace std;


long long int where , how;
long long int n;
vector<long long int> v;
int main(){
scanf("%lld",&n);
v.resize(n);
for(int i=0;i<n;i++) scanf("%lld",v.begin()+i);
long long int m;
scanf("%lld",&m);
for(int i=0;i<m;i++){

 long long int x , y;
 scanf("%lld%lld",&x,&y);
 if(i==0){
  cout<<v[x-1]<<endl;
  where = x , how = y+v[x-1];
 }else{
  if(where >= x){
   cout<<how<<endl;
   where = x , how += y;
  }else{
   if(how >= v[x-1]){
    cout<<how<<endl;
    where = x , how += y;
   }else{
    cout<<v[x-1]<<endl;
    where = x , how = v[x-1]+y;
   }
  }
 }

}
 return 0;
}