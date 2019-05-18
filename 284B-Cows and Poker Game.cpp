#include <bits/stdc++.h>

using namespace std;

int n;
string str;
int A , I , F;

int main(){
 cin >> n;
 cin >> str;
 for(int i=0;i<str.size();i++)
  if(str[i]=='A') A++;
  else if(str[i]=='I') I++;
  else F++;

 if(I == 1) cout<<1;
 else if(I > 1) cout<<0;
 else cout<<A;
 return 0;
}