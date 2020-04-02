#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    int t;cin >>t;
    while(t--){
        int n;cin>>n;
        char arr[n];
        srand(time(0)); 
        char letter[3]={'a','b','c'};
        for(int i=0;i<n;i++){arr[i]=letter[rand()%3];}
        //cout<<endl;
        int count=0;
        for(int p=1;p<=n;p++){
           for(int q=p+1;q<=sqrt(n*p);q++){
              if((q*q)%p==0){
               int r= q*q/p;
               cout<<p<<" "<<q<<" "<<r<<endl;
               if(r>n) break;
               if(arr[p-1]='a' && arr[q-1]=='b' && arr[r-1]=='c') count++;
               else if(arr[p-1]='c' && arr[q-1]=='b' && arr[r-1]=='a') count++;
             }
           } 
        }
        cout<<count<<endl;
    }
}

