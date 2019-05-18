#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> dots;
vector<int> result;
void getpos(){
 for(int i=0;i<s.size();i++)
  if(s[i]=='.') dots.push_back(i);
}


int main(){
 cin >> s;
 getpos();
 for(int i=s.size()-1,cont=0;i>=0;i--){
  if(s[i]!='.') 
   cont++;
  if(s[i]=='.') {
   if(cont >= 4 || cont < 1){
   cout<<"NO";
   return 0;
  }
  break;
  }
 }
 for(int i=0,cont=0;i<s.size();i++){
  if(s[i]!='.') 
   cont++;
  if(s[i]=='.') {
   if(cont >= 9 || cont < 1){
   cout<<"NO";
   return 0;
  }
   break;}
 }
 if(dots.size()==1){
  cout<<"YES"<<endl<<s;
  return 0;
 }else if(dots.size()==0){
  cout<<"NO";
  return 0;
 }
 for(int i=0;i<dots.size()-1;i++){
  int g = dots[i+1]-dots[i];
  g--;
  if(g >= 2 && g <= 11){
   if(g-1 <= 8) result.push_back(dots[i]+1);
   else if(g-2 <= 8) result.push_back(dots[i]+2);
   else if(g-3 <= 8) result.push_back(dots[i]+3);
  }else{
   cout<<"NO";
   return 0;
  }
 }
 cout<<"YES"<<endl;
 for(int i=0,cont=0;i<dots[dots.size()-1];i++){
  cout<<s[i];
  if(i==result[cont]) {cout<<endl; cont++;}
 }
 for(int i=dots[dots.size()-1];i<s.size();i++){
  cout<<s[i];
 }
 return 0;
}