#include <bits/stdc++.h>

using namespace std;

long long int n , x , y , res;
vector<long long int> numbers;

int main(){
  
  cin >> n >> x >> y;
  
  
  
  if(y < n){
    cout<<-1;
    return 0;
  }
  
  long long int test = y/n , sum = 0;
  
  numbers.resize(n);
  for(int i=0;i<n;i++) 
  {
    numbers[i]=test;
    sum += numbers[i];
  }
  
  if(sum != 0)
  numbers[0]+=y-sum;
  
  for(int i=1;i<n;i++){
  numbers[0]+=numbers[i]-1;
  numbers[i]=1;
  }
  
  long long int sum2 = 0;
  
  for(int i=0;i<n;i++) {sum2+=pow(numbers[i],2);
  
    
  }
  if(sum2 >= x && sum <= y){
    for(int i=0;i<n;i++) cout<<numbers[i]<<endl;
  }else cout<<-1;
  
  
  return 0;
}