#include <bits/stdc++.h>
using namespace std;
int n , m;
vector<int> v , _left , _right;
int seg[4*(int)1e5];

int bs(int from,int to){
 int Left = from , Right = to,ans =_left[from],have = -1;
 while(Left<=Right){
  int mid = (Left+Right)/2;
  if(_left[mid]<=ans){
   have = max(have,mid);
   Left=mid+1;
  }else Right=mid-1;
 }
 return have;
}

void build(int p,int l,int r){
 if(l==r){
  seg[p]=_right[l];
  return ;
 }
 int mid = (l+r)/2;
 build(p*2,l,mid);
 build(p*2+1,mid+1,r);
 seg[p]=max(seg[p*2],seg[p*2+1]);
}

int get(int p,int l,int r,int s,int e){
 if(l>e||r<s)
  return -1e9;
 if(l>=s&&r<=e)
  return seg[p];
 int mid = (l+r)/2;
 return max(get(p*2,l,mid,s,e),get(p*2+1,mid+1,r,s,e));
}
int main(){
 cin>>n>>m;
 v.resize(n) , _left.resize(n) , _right.resize(n);
 for(int i=0;i<n;i++)
  cin>>v[i];
 _left[0]=0;
 for(int i=1;i<n;i++)
  if(v[i] >= v[i-1])
   _left[i]=_left[i-1];
  else
   _left[i]=i;
 
 _right[n-1]=n-1;
 for(int i=n-2;i>=0;i--)
  if(v[i] >= v[i+1])
   _right[i]=_right[i+1];
  else
   _right[i]=i;

 build(1,0,n-1);
 while(m--){
  int from , to;
  cin>>from>>to;
  from--,to--;
  int idx = bs(from,to);
  int interval = get(1,0,n-1,from,idx);
  if(interval >= to)
   cout<<"Yes"<<endl;
  else 
   cout<<"No"<<endl;
 }

 return 0;
}