#include <bits/stdc++.h>

using namespace std;

int n , k , fr[200000] , s = -1e9, e = 1e9;
vector<int> v;
int main(){
    
        cin >> n >> k;
        v.resize(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int l = 0 ,r = 0 , dis = 0;
        for(;r<n;r++){
            if(fr[v[r]] == 0) dis++;
            fr[v[r]]++;
            if(dis == k && ((e-s+1) > (r-l+1))) s = l, e =r; 
            while(l < r && dis >= k){
                if(dis == k && ((e-s+1) > (r-l+1))) s = l, e =r;
                if(fr[v[l]] == 1) dis--;
                fr[v[l]]--;
                l++;
                if(dis == k && ((e-s+1) > (r-l+1))) s = l, e =r;
            }
        }
        if(s == -1e9) cout<<-1<<" "<<-1;
        else cout<<s+1<<" "<<e+1;
    return 0;
}