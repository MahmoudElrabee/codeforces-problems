#include <bits/stdc++.h>
using namespace std;

int a , x , y;
pair<int,int> res[1000005];
int main(){ 
 for(int i=0,q = 2;i<1000005;i++){
  if(i == 0) res[i].first = 1;
  else if(i&1) {
   res[i].first = q;
   q++;
  }else{
   res[i].first = q;
   q++;
   res[i].second = q;
   q++;
  }
 }
  cin >> a >> x >> y;
 if(y%a == 0){
  cout<<-1;
  return 0;
 }

 int posY = y / a;
 

 if((!(posY&1))&&(posY!=0)){

  if(x < a && x > 0){
   cout<<res[posY].second;
   return 0;
  }else if(abs(x) < a && x < 0){
   cout<<res[posY].first;
   return 0;
  }

 }else if(posY==0||(posY&1)){
   if(x >= 0 && x < a/2.0){
    cout<<res[posY].first;
    return 0;
   }else if(x <= 0 && abs(x) < a/2.0){
    cout<<res[posY].first;
    return 0;
   }
 }
 cout<<-1;
 return 0;
}