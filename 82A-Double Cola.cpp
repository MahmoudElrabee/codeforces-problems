#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include <stdio.h>
using namespace std ;
int main () 
{
    string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"}; 
 int n;
 cin >> n;
 while(n > 5){
     n/=2;
     n-=2;
 }
 cout<<names[--n]<<endl;

}