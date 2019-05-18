#include <bits/stdc++.h>
using namespace std;
long long int n , sx , sy , ex , ey;
string path;
int main(){

 cin >> n >> sx >> sy >> ex >> ey;
 cin >> path;

 for (int i = 0 , result = 0; i < path.size(); ++i){
  if(path[i]=='S' && sy > ey)
   sy--;
  else if(path[i]=='W' && sx > ex)
   sx--;
  else if(path[i]=='N' && sy < ey)
   sy++;
  else if(path[i]=='E' && sx < ex)
   sx++;
  if(sx==ex&&sy==ey){
   cout<<i+1;
   return 0;
  }
 }

 cout<<"-1";
 return 0;
}