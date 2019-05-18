#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAX = 1e6;
ll n , a[MAX];
vector<ll> seg[MAX*4];
void work(int in,int left,int right){
    for(int i=0, j=0;;){
        if(i<seg[left].size()&&j<seg[right].size()){
            if(seg[left][i] < seg[right][j]){
                seg[in].push_back(seg[left][i]);
                i++;
            }else{
                seg[in].push_back(seg[right][j]);
                j++;
            }
        }else if(i<seg[left].size()){
            seg[in].push_back(seg[left][i]);
            i++;
        }else if(j<seg[right].size()){
            seg[in].push_back(seg[right][j]);
            j++;
        }else break;
    }
}

void build(ll p,ll l,ll r){
    if(l==r){
        seg[p].push_back(a[l]);
        return ;
    }
    ll mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    work(p,p*2,p*2+1);
}
ll get(ll p,ll l,ll r,ll a,ll b,ll val,bool great){
    if(l > b||r < a) return 0;
    if(l>=a&&r<=b){
        if(great){
            ll have = upper_bound(seg[p].begin(),seg[p].end(),val)-seg[p].begin();
            return seg[p].size()-have;
        }else{
            ll have = lower_bound(seg[p].begin(),seg[p].end(),val)-seg[p].begin();
            return have;
        }
    }
    ll mid=(l+r)/2;
    return get(p*2,l,mid,a,b,val,great)+get(p*2+1,mid+1,r,a,b,val,great);
}
int main(){

    scanf("%lld",&n);
    for(int i=0;i<n;i++) scanf("%lld",a+i);
    build(1,0,n-1);
    ll res = 0;
    for(int i=1;i<n-1;i++)
        res+=get(1,0,n-1,0,i-1,a[i],1)*get(1,0,n-1,i+1,n-1,a[i],0);
    printf("%lld",res);
    return 0;
}