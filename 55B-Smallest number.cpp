#include <bits/stdc++.h>

using namespace std;
long long int arr[4];
char c1,c2,c3;



int main(){
 cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
 cin >> c1 >> c2 >> c3;

 long long int res = 1e18;

 for(int i=0;i<4;i++){
  for(int j=0;j<4;j++){
   if(i==j) continue;
   long long int r[3];
   if(c1 == '+'){
    r[0] = arr[i]+arr[j];
    for(int z=0,p=0;z<4;z++)
     if(z!=i&&z!=j&&p==0) {p++;r[1] = arr[z];}
     else if(z!=i&&z!=j&&p==1) r[2] = arr[z]; 
   }else{
    r[0] = arr[i]*arr[j];
    for(int z=0,p=0;z<4;z++)
     if(z!=i&&z!=j&&p==0) {p++;r[1] = arr[z];}
     else if(z!=i&&z!=j&&p==1) r[2] = arr[z];
   }
   for(int q=0;q<3;q++){
    for(int w=0;w<3;w++){

     if(q==w) continue;
     long long int val1 , val2;
     if(c2=='+'){
      val1 = r[w]+r[q];
      for(int d=0;d<3;d++)
       if(d!=q&&d!=w){val2 = r[d]; break;}
      if(c3=='+')
      res=min(res,val1+val2);
      else res=min(res,val2*val1);
     }else{
      val1 = r[w]*r[q];
      for(int d=0;d<3;d++)
       if(d!=q&&d!=w){val2 = r[d]; break;}
      if(c3=='+')
      res=min(res,val1+val2);
      else res=min(res,val2*val1);
     }


    }
   }


  }
 }
 cout<<res;
 return 0;
}