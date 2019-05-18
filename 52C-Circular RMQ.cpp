#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll MAX =  2e5+10;
ll n , a[MAX] , seg[MAX*4] , lazy[MAX*4];

ll build(ll p,ll l,ll r){
    if(l==r) return seg[p]=a[l];
    ll mid = (l+r)/2;
    return seg[p]=min(build(p*2,l,mid),build(p*2+1,mid+1,r));
}
void update(ll p,ll l,ll r,ll a,ll b,ll val){
    if(lazy[p]!=0){
        seg[p]+=lazy[p];
        if(l!=r){
            lazy[p*2]+=lazy[p];
            lazy[p*2+1]+=lazy[p];
        }
        lazy[p]=0;
    }
    if(l>b||r<a) return ;
    if(l>=a&&r<=b){
        seg[p]+=val;
        if(l!=r){
            lazy[p*2]+=val;
            lazy[p*2+1]+=val;
        }
        return ;
    }
    ll mid = (l+r)/2;
    update(p*2,l,mid,a,b,val);
    update(p*2+1,mid+1,r,a,b,val);
    seg[p]=min(seg[p*2],seg[p*2+1]);
}
ll get(ll p,ll l,ll r,ll a,ll b){
    if(lazy[p]!=0){
        seg[p]+=lazy[p];
        if(l!=r){
            lazy[p*2]+=lazy[p];
            lazy[p*2+1]+=lazy[p];
        }
        lazy[p]=0;
    }
    if(l>b||r<a) return 1e9;
    if(l>=a&&r<=b) return seg[p];
    ll mid = (l+r)/2;
    return min(get(p*2,l,mid,a,b),get(p*2+1,mid+1,r,a,b));
}
int main(){
    scanf("%lld",&n);
    for(int i=0;i<n;i++) scanf("%lld",a+i);
    build(1,0,n-1);
    ll t;
    scanf("%lld",&t);
    string s;
    cin.ignore();
    while(t--){
        getline(cin,s);
        bool flg = false , sign=false;
        ll x = 0 , y = 0 , v=0;
        for(int i=0,q=0;i<s.size();i++){
            if(s[i]==' ') {q++;sign=(q==2&&s[i+1]=='-');}
            if(s[i]!=' '&&q==0){
                x*=10;
                x+=s[i]-'0';
            }else if(s[i]!=' '&&q==1){
                y*=10;
                y+=s[i]-'0';
            }else if(s[i]!=' '&&q==2&&isdigit(s[i])){
                flg = true;
                v*=10;
                v+=s[i]-'0';
            }
        }
        if(sign) v*=-1;
        if(!flg){
            if(y>=x) printf("%lld\n",get(1,0,n-1,x,y));
            else{
                printf("%lld\n",min(get(1,0,n-1,0,y),get(1,0,n-1,x,n-1)));
            }
        }else{
            if(y>=x) update(1,0,n-1,x,y,v);
            else{
             update(1,0,n-1,0,y,v);
             update(1,0,n-1,x,n-1,v);   
            }
        }
    }
    
    return 0;
}