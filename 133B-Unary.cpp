#include <bits/stdc++.h>

using namespace std;

int MOD = 1000003;
string str , result="";
map<char,string> mp;

long long int QuickPower(long long int b,long long int p){
        if(p==0)return 1;
    if(p==1)return b;
    long long int m=QuickPower(b,p/2);
    m=1ll*m*m%MOD;
    if(p&1)m=1ll*m*b%MOD;
    return m;
    }

int main(){

mp['>']="1000";
mp['<']="1001";
mp['+']="1010";
mp['-']="1011";
mp['.']="1100";
mp[',']="1101";
mp['[']="1110";
mp[']']="1111";

cin >> str;
for(int i=0;i<str.size();i++)
  result+=mp[str[i]];


long long int res = 0;
reverse(result.begin(),result.end());
for(int i=0;i<result.size();i++)
  if(result[i] == '1')
   res = (res +  QuickPower(2,i))%MOD;
   
   cout<<res;
 return 0;
}