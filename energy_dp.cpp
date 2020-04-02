#include<bits/stdc++.h>
using namespace std;
#define INF 99999;
int H=4000,D=1000;
int dp[4000][1000][5];

int recur(int h,int d, int k,int cost[],int time[]){
    if(h<0) return INF;
    if(d==0) return 0;
    if(k<0) return INF;
    if(dp[h][d][k]!=-1) return dp[h][d][k];
    else {
        dp[h][d][k] = min(recur(h,d,k-1,cost,time),time[k]+recur(h-cost[k],d-1,k,cost,time));
        return dp[h][d][k];
    }
}
int main(){
    memset(dp,-1,sizeof dp);
    int cost[]= {4,3, 5, 2, 6};
    int time[]={5,7,11,14,16 };
    //int H=14,D=4;
    cout<<recur(11,3,4,cost,time)<<endl;
    memset(dp,-1,sizeof dp);
}