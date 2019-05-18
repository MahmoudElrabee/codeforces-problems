#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll price , have;
string number;
vector<string> v;


void bulid(){

 for(int i=number.size()-1;i>0;i--){

  if(number[i]=='9') continue;
     number[i]='9';
  for(int j = i-1; j >= 0 ;j--){

   if(j==0){
    if(number[j]=='0'||number[j]=='1'){
     number.erase(number.begin());
     v.push_back(number);
     return ;
    }else{
     int n = number[j]-'0';
     n--;
     number[j]=to_string(n)[0];
     v.push_back(number); 
     break;
    }
   }else{
    if(number[j]=='0') number[j]='9';
    else{
     int n = number[j]-'0';
     n--;
     number[j]=to_string(n)[0];
     v.push_back(number);
     break;
    }
   }

  }

 }

}

int numberOfNine(string s){
  int res = 0;
  for(int i=s.size()-1;i>=0;i--) 
    if(s[i]=='9') res++;
    else break;
  return res;
}
bool can(ll num){
  if(price-num <= have) return true;
  return false;
}

int main(){ 

 cin >> price >> have;

 number = to_string(price);
  
  if(number.size() == 1){
    cout<<number;
    return 0;
  }
  
  if(price%10==9) v.push_back(number);
 bulid();
  
  int h = number[0]-'0';
  if(h!=9){
  for(int i=1;i<=h;i++){
    number[0]=to_string(i)[0];
    v.push_back(number);
  }
  number.erase(number.begin());
 v.push_back(number);
  }
  int mx = -1e9;
  bool flg = false;
  string EndRes;
  for(int i=0;i<v.size();i++){
    if(can(stoll(v[i]))&&numberOfNine(v[i])>mx){
      flg = true;
      mx = numberOfNine(v[i]);
      EndRes = v[i];
    }
  }
  if(flg) cout<<EndRes;
 else cout<<price;
  return 0;
}