#include <bits/stdc++.h>

using namespace std;

int n;
string s;
map<string,int> freq;

int main(){
 scanf("%d",&n);
 while(n--){
  cin >> s;
  if(freq[s] == 0) {freq[s]++; cout<<"OK"<<endl;}
  else {
   cout<<s<<freq[s]<<endl;
   freq[s]++;
  }
 }
 return 0;
}