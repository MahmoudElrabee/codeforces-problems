#include <bits/stdc++.h>

using namespace std;
int n , m , Visted[1000005] , freq;

vector<int> v;

bool found = false; // number status

///////// if not found i wanna to use this var////////////////
int moreThen , lessThen;




int main(){
  
  cin >> n >> m;
  v.resize(n);
  //////////////// make sure if the number is found
  for(int i=0;i<n;i++){
  cin >> v[i];
  if(v[i] == m) {found=1; freq++;}
  }
  sort(v.begin(),v.end());
  
  int res = 0;
  if(!found){ ////////// not found
    
  for(int i=0;i<n;i++){ 
    if(v[i] < m) lessThen++;
    else if(v[i] > m) moreThen++;
  }
  
  int mypos = lessThen+1;
  
  if((lessThen+moreThen+2)/2 == mypos) res = 1;
  else{
    
    if(moreThen-1 == lessThen) res = 1;
    else if(lessThen > moreThen) res = lessThen-moreThen+1;
    else if(moreThen==lessThen) res = 1;
    else if(moreThen > lessThen) res = moreThen-lessThen;
    
  }
  
  
  }else{
    int Endres = 1e9;
    while(freq--){
    int mypos = 1e9;
    
    for(int i=0;i<n;i++){ 
    if(m==v[i] && mypos==1e9 && !Visted[i]) {mypos=i+1; Visted[i]=1;
      moreThen = n - mypos;
      lessThen = i;
      break;
    }
    }
    
    
    if((n+1)/2 == mypos) res = 0;
    else{
      
  
    if(lessThen > moreThen) res = lessThen-moreThen;
    else if(moreThen > lessThen) res = moreThen-lessThen-1;
    
    }
      Endres = min(res,Endres);
      res = 0;
      lessThen = 0 , moreThen = 0;
    }
    res = Endres;
  }
  
  cout<<res;
 return 0;
}