#include<bits/stdc++.h>
#include<vector>
using namespace std;
bool func(long long x,long long y){
   if(x==1 || y==1) return true;
   if(x%2!=0 && y%2!=0){
       if(x==y) return false;
       return x>y?func(x+y,y):func(x,x+y);
   }
   if(x%2 ==0) return func(x/2,y);
   if(y%2 == 0) return func(x,y/2);
}
int main(){
    int t;cin >>t;
    while(t--){
    long long x,y;
    cin >> x>>y;
    bool ans=func(x,y);
    cout << ans << "\n";
    }
}

