#include <bits/stdc++.h>

using namespace std;

int n , m , l , r , x , seg[1200005];

void SET(int p , int left ,int right , int a , int b , int val){

 if(seg[p]!=-1) return ;
 if(right < a || left > b) return ;
 if(left==right){
  if(left!=val&&seg[p]==-1) seg[p]=val; 
  return ;
 }
 int mid = (right+left)/2;
 if(seg[p*2]==-1) SET(p*2,left,mid,a,b,val);
 if(seg[p*2+1]==-1) SET(p*2+1,mid+1,right,a,b,val);
 if(seg[p*2]==seg[p*2+1]) seg[p]=seg[p*2];
 else if(seg[p*2]!=-1&&seg[p*2+1]!=-1) seg[p]=-2;

}

int get(int p , int left , int right , int val){

 if(left==right&&left==val) return seg[p];
 int mid=(left+right)/2;
 if(val <= mid)
  return get(p*2,left,mid,val);
 else 
  return get(p*2+1,mid+1,right,val);
 
}
int main(){
 scanf("%d%d",&n,&m);
 memset(seg,-1,sizeof(seg));
 while(m--){
  scanf("%d%d%d",&l,&r,&x);
  SET(1,1,n,l,r,x);
 }
 for(int i=1;i<=n;i++){
  int res = get(1,1,n,i);
  if(i!=n) printf("%d ",res!=-1?res:0);
        else printf("%d",res!=-1?res:0);
 }
 
 return 0;
}