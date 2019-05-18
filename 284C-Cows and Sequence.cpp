#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


ll m , _stack[200005] , stacktop = 0 , sum;
map<ll,ll> mp;
void print(){
    printf("%lf\n",sum*1.0/(stacktop+1));
}

void addatlast(ll item){
    stacktop++;
    _stack[stacktop]=item;
    sum+=_stack[stacktop];
    print();
}
void addinfirst(ll ind,ll item){
    mp[ind-1]+=item;
    sum+=item*ind;
    print();
}
void remove(){
    if(!(stacktop+1 >= 2)) return ;
    mp[stacktop-1]+=mp[stacktop];
    sum-=(_stack[stacktop]+mp[stacktop]);
    mp[stacktop]=0;
    stacktop--;
    print();
}



int main(){
    
    
    scanf("%lld",&m);
    while(m--){
        ll sign , spare;
        scanf("%lld",&sign);
        if(sign==3) remove();
        else if(sign==1){
            ll ind;
            scanf("%lld",&ind);
            scanf("%lld",&spare);
            addinfirst(ind,spare);
        }else{
            scanf("%lld",&spare);
            addatlast(spare);
        }
    }
    
    return 0;
}