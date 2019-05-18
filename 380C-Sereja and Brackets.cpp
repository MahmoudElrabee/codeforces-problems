/*
    six months ago i could not solve question C div2
    but now (after six months from my first training) i solved this problem
    Do not forget your ambition
*/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll sz;
vector<ll> seg[4000001];
char s[1000001];
struct point{
    ll place , wheremyclose;
    char whoami;
};
stack<point> stk;
vector<ll> v;
void fullvector(){
    v.resize(sz);
    for(int i=0;i<sz;i++){
        point p;
        p.place = i;
        p.whoami=s[i];
        if(!stk.empty()){
            if(stk.top().whoami=='('&&s[i]==')'){
                v[stk.top().place] = i;
                v[i] = stk.top().place;
                stk.pop();
            }else stk.push(p);
        }else stk.push(p);
    }
    while(!stk.empty()){
        v[stk.top().place]=-1;
        stk.pop();
    }
}
void work(ll in,ll left,ll right){
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
void bulid(ll p , ll l , ll r){
    if(l==r){
        seg[p].push_back(v[l]);
        return ;
    }
    ll mid = (l+r)/2;
    bulid(p*2,l,mid);
    bulid(p*2+1,mid+1,r);
    work(p,p*2,p*2+1);
}
long long int mx=0;
void get(ll p , ll l , ll r , ll a, ll b){
    if(r < a || l > b) return ;
    if(l>=a&&l<=b&&r<=b&&r>=a){
        ll left = 0 , right = seg[p].size()-1 , mid , ans = -1;
        while(left<=right){
            mid=(left+right)/2;
            if(seg[p][mid] <= b){
                if(seg[p][mid] >= a) ans=max(ans,mid);
                left=mid+1;
            }else right=mid-1;
        }
        if(ans==-1) return;
        mx+=ans+1;       
        left = 0 , right = seg[p].size()-1 , mid , ans = -1;
        while(left<=right){
            mid=(left+right)/2;
            if(seg[p][mid] < a){
                ans = max(ans,mid);
                left=mid+1;
            }else right=mid-1;
        }
        mx-=ans+1;
        return ;
    }
    ll mid = (l+r)/2;
    get(p*2,l,mid,a,b);
    get(p*2+1,mid+1,r,a,b);
}
int main(){
    scanf("%s",s);
    sz = strlen(s);
    fullvector();
    bulid(1,0,sz-1);
    ll m , x , y;
    scanf("%d",&m);
    while(m--){
        mx=0;
        scanf("%d%d",&x,&y);
        x--,y--;
        get(1,0,sz-1,x,y);
        printf("%lld\n",mx);
    }
    return 0;
}