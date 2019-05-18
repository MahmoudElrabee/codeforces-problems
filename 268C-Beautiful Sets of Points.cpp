#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > points;
int main(){

 int n , m , res = 0;
 cin >> n >> m;
 for(int i = m , j = 0;i >=0  && j <= n ;i--,j++)
 if(i+j > 0){
   points.push_back({j,i});
   res++;
 }
 if(res!=0){
 cout<<res<<endl;
 for(int i=0;i<points.size();i++)
 cout<<points[i].first<<" "<<points[i].second<<endl;
 }else{
   if(n + m > 0){
     cout<<1<<endl<<n<<" "<<m<<endl;
   }
 }
   return 0;
}