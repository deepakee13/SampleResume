#include<iostream>
using namespace std;
#define INT_MAX 9999
#include <bits/stdc++.h>
int minimum(int a,int b,int c,int d){
	int min1=min(a,b);
	int min2=min(c,d);
	return min(min1,min2);
}
int dp[70][70][70][70];

int recur(int nch,int g1,int g2,int g3,int p1,int p2,int p3){
	//cout<<nch<<endl;
	if(dp[nch][g1][g2][g3]!=-1) return dp[nch][g1][g2][g3];

	if(g1<0 || g3>=nch)
		return dp[nch][g1][g2][g3]=INT_MAX;

	else if(nch==p1+p2+p3){
		//do something
		int sum=0;
		for(int i=0;i<nch;i++){
			if(p1> 0){
				sum+=abs(i-g1)+1;
				p1--;
			}
			else if(p2>0){
				sum+=abs(i-g2)+1;
				p2--;
			}
			else{
				sum+=abs(i-g3)+1;
			}
		}
		dp[nch][g1][g2][g3]=sum;
		if(dp[nch][g1][g2][g3]==82) cout<<g1<<" "<<g2<<" "<<" "<<g3<<endl;
		return sum;

	}

	//4 cases
	// if(g1!=0 && g3!=nch-1)
	
	return dp[nch][g1][g2][g3]=minimum(recur(nch-1,g1-1,g2-1,g3-1,p1,p2,p3),recur(nch-1,g1,g2-1,g3-1,p1,p2,p3),recur(nch-1,g1,g2,g3-1,p1,p2,p3),recur(nch-1,g1,g2,g3,p1,p2,p3));
	// else if(g1!=0 && g3==nch-1)
	// 	return min(recur(nch-1,g1-1,g2-1,g3-1,p1,p2,p3),recur(nch-1,g1,g2-1,g3-1,p1,p2,p3),recur(nch-1,g1,g2,g3-1,p1,p2,p3));
	// else if(g1==0 && g3!=nch-1)
	// 	return min(recur(nch-1,g1,g2-1,g3-1,p1,p2,p3),recur(nch-1,g1,g2,g3-1,p1,p2,p3),recur(nch-1,g1,g2,g3,p1,p2,p3));
	// else return min(recur(nch-1,g1,g2-1,g3-1,p1,p2,p3),recur(nch-1,g1,g2,g3-1,p1,p2,p3));


}
int main(){
	int t;cin>>t;
	while(t--){

		int n;cin>>n;
		int g1,p1,g2,p2,g3,p3;
		cin>>g1>>p1>>g2>>p2>>g3>>p3;
		memset(dp,-1,sizeof(dp));
		cout<<recur(n,g1-1,g2-1,g3-1,p1,p2,p3)<<endl;
		//memset(dp,-1,sizeof(dp));
	}

}