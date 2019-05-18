#include <bits/stdc++.h>
using namespace std;

long long int l , r;
vector<long long int> numbers;
void genaretor(long long int x){
 numbers.push_back(x);
 if(x > 1e9)
  return ;
 genaretor(x*10+4);
 genaretor(x*10+7);
}
int main(){
 genaretor(0);
 
 sort(numbers.begin(),numbers.end());
 
 cin >> l >> r;
 
 long long int result = 0;
 
 for(int i=1;i<numbers.size();i++)
     if(l<=r && numbers[i]>=l){
         if(numbers[i] <= r){
             result+=(numbers[i]-l+1)*numbers[i];
             l=numbers[i]+1;
         }else{
             result+=(r-l+1)*numbers[i];
             break;
         }
     }
 cout<<result;
 return 0;
}