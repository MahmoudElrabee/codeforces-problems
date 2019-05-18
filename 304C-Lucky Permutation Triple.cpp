#include <bits/stdc++.h>

using namespace std;
const int N = 50;
int n ;

int main(){
        cin >> n;
        if(n&1){
                for(int i=0;i<n;i++) cout<<i<<" ";
                cout<<endl;
                for(int i=0;i<n;i++) cout<<i<<" ";
                cout<<endl;
                for(int i=0;i<n;i++) cout<<i*2%n<<" ";
                return 0;
        }
        return cout<<"-1",0;
}