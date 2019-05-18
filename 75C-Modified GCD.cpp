#include <bits/stdc++.h>

using namespace std;
const int N = 1e7;
int a , b , q ;
map<int,int> fr;
vector<int> path; 
void div(int n){
        for(int i = 1; i * i <= n; ++i)
 if(n % i == 0) {
                fr[i]++;
                if(fr[i]==2) path.push_back(i);
  if(n / i != i){
   fr[n / i]++;      
                        if(fr[n / i]==2) path.push_back(n / i);
                }
        }
        sort(path.begin(), path.end());
}
int main(){
        cin >> a >> b >> q;
        div(a) , div(b);
        while(q--){
                int from ,to , l=0,r=path.size()-1,mid , ans = -1;
                cin >> from >> to;
                while(l<=r){
                        mid=(l+r)/2;
                        if((path[mid] >= from && path[mid] <= to)){
                                ans = path[mid];
                                l=mid+1;
                        }else if((path[mid] < from)) l=mid+1;
                        else r=mid-1;
                }
                cout<<ans<<endl;
        }
        return 0;
}