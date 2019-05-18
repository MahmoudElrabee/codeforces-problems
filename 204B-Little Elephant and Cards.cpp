#include <bits/stdc++.h>

using namespace std;
int n , mn = 1e9;
map<int,int> Front,Back;
vector<int> color;
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    int front , back;
    cin>>front>>back;
    Front[front]++;
    if(front!=back) Back[back]++;
    color.push_back(front);
    color.push_back(back);
  }
  int hulfe = n/2+(n&1);
  for(int i=0;i<color.size();i++){
    int c = color[i];
    if(Front[c] >= hulfe) mn=0;
    else if((Front[c]+Back[c]) >= hulfe) mn=min(mn,hulfe-Front[c]);
  }
  cout<<((mn!=1e9)?mn:-1)<<endl;
  return 0;
}