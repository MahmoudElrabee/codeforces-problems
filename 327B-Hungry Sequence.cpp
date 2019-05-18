#include <bits/stdc++.h>

using namespace std;

int const MAX = 10000001; // Change maximum number of numbers if needed
bool prime[MAX]; // Status for each number

void sieve_of_eratosthenes() {
 memset(prime, true, sizeof prime); // Assume every number is prime

 prime[0] = prime[1] = false; // 0 and 1 are not primes

 for(int i = 2; i * i < MAX; ++i)
  if(prime[i])
   for(int j = i * i; j < MAX; j += i)
    prime[j] = false;
}
int main(){
  long long int need;
 cin >> need;
 sieve_of_eratosthenes();
 for(int i=0,q = 2;i<need;q++){
  if(prime[q]){
   cout<<q<<" ";
   i++;
  } 
 }
 return 0;
}