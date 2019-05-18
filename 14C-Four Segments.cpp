#include <bits/stdc++.h>

using namespace std;


long double des(long long int point1, long long int point2 , long long int point3, long long int point4){
  return sqrt(pow(point3-point1,2)+pow(point4-point2,2));
}

map<pair<long long int,long long int>,long long int> freq;
map<string,long long int> fr;
map<long double,long long int> freqDes;

int main(){

  for(int i=0;i<4;i++){
    long long int x1 , y1 , x2 , y2;
    cin >> x1 >> y1 >> x2 >> y2;
    string s1 = "",s2 = "",newS="";
    s1+=to_string(x1);
    s1+=to_string(y1);
    s2+=to_string(x2);
    s2+=to_string(y2);
    if(s1 <= s2){
      newS+=s1;
      newS+=s2;
    }else{
      newS+=s2;
      newS+=s1;
    }
    fr[newS]++;
    freq[{x1,y1}]++ , freq[{x2,y2}]++;
    long double desAsDouble = des(x1,y1,x2,y2);
    if(desAsDouble != (long long int)desAsDouble){
      cout<<"NO";
      return 0;
    }
    freqDes[desAsDouble]++;
  }
  if(fr.size() != 4){
    cout<<"NO";
    return 0;
  }
  if(freqDes.size()!=1&&freqDes.size()!=2){
      cout<<"NO";
      return 0;
  }else if(freqDes.size() == 1){
    for(map<long double,long long int>::iterator it=freqDes.begin();it!=freqDes.end();it++){
      if(it->first <= 0 || it->first*it->first <= 0){
        cout<<"NO";
        return 0;
      }
    }
    for(map<pair<long long int,long long int>,long long int>::iterator it=freq.begin();it!=freq.end();it++)
    if(it->second != 2){
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
  }else if(freqDes.size() == 2){
      int A1 , A2 , q=0;
      for(map<long double,long long int>::iterator it=freqDes.begin();it!=freqDes.end();it++){
        if(q==0) A1 = it->first;
        else A2 = it->first;
        q++;
      }  

      for(map<pair<long long int,long long int>,long long int>::iterator it=freq.begin();it!=freq.end();it++)
    if(it->second != 2){
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
  }
  
  return 0;
}