#include <bits/stdc++.h>

using namespace std;

int n , m;
vector<int> books;
int main(){
 scanf("%d%d",&n,&m);
 books.resize(n);
 for(int i=0;i<n;i++) scanf("%d",books.begin()+i);
 int res = 0 , have = 0;
 for(int r=0,l=0;r<n;r++){
  have+=books[r];
  while(have > m){
   have-=books[l];
   l++;
  }
  if((r-l)+1 > res) res = (r-l)+1;
 }
 printf("%d",res);
 return 0;
}