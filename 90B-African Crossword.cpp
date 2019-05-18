#include <bits/stdc++.h>

using namespace std;
 

int n , m;
char Grid[105][105];
char result[105][105];
int main(){

 cin >> n >> m;
 for(int i=0;i<n;i++)
  for(int j=0;j<m;j++){
     cin>>Grid[i][j];
     result[i][j]=Grid[i][j];
    }

 for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)
   {
    bool flg =1;
    for(int z=0;z<n;z++){
     if(z!=i&&Grid[i][j]==Grid[z][j]) {result[z][j]='#'; 
          flg = 0;
         }
    }
    for(int q=0;q<m;q++){
     if(q!=j&&Grid[i][j]==Grid[i][q]) {result[i][q]='#';
          flg = 0;}
    } 
    if(!flg) result[i][j]='#';
   }
 for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)
   if(result[i][j]!='#') cout<<result[i][j];

 return 0;
}