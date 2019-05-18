#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

#define p(V) for(int iiv=0;iiv<V.size();iiv++) cout<<V[iiv]<<" ";
#define mp make_pair
#define pb push_back
#define graph vector<vector<int> >
#define pf first
#define ps second
#define pq priority_queue
const int N = 2e5;
const int l = 18;
const double pi = acos(-1);

string s;
int main(){   
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin >> s;
    stack<int> lastIdx;
    if(s[0] == '(') lastIdx.push(0);
    vector<int> path(s.size(),0);
    for(int i=1;i<s.size();i++){
        if(lastIdx.size()==0 || s[i] == '('){
            if(s[i]=='(') lastIdx.push(i);
        }else{
            path[i] = 1;
            path[lastIdx.top()]=1;
            lastIdx.pop();
        }
    }
    int ans = 0 , len = 0;
    for(int i=0,l=0;i<path.size();i++) {
        if(path[i]==1) {l++; if(i!=path.size()-1) continue;}
        if(path[i]==0){
            if(l == len) ans++;
            else if(l > len) ans=1,len=l;
            l = 0;
        }else if(l==len) ans++;
        else if(l>len) ans=1,len=l;
    }
    if(len == 0) cout<<"0 1";
    else cout<<len<<" "<<ans;
    return 0;
}