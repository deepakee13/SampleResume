#include<iostream>
using namespace std;
#include<bits/stdc++.h>
bool isValid(int x,int y,vector<vector<int>>& mat,int n){
	if(x>=0 && x<n && y>=0 && y<n && mat[x][y]>=0) return true;
	return false;

}
bool maxc(vector<vector<int>>& mat,int d,int x,int y,int n, bool flag,int& maxm){
	if(!isValid(x,y,mat,n)) return false;
	if(!flag && x==0 && y==0){
		if(mat[x][y]==1){
			d+=mat[x][y];
			mat[x][y]--;
		}
		if(maxm<d) maxm =d;
		return true;
	}
	if(flag && x==n-1 && y==n-1){
		// if(mat[x][y]==1){
			// d+=mat[x][y];
			// mat[x][y]--;
		// }
		flag=0;
		// return maxc(mat,d,x,y,n,flag,maxm);
	}
	if(flag){
		if(mat[x][y]==1){
			mat[x][y]=0;
			maxc(mat,d+1,x+1,y,n,flag,maxm);
			mat[x][y]=1;
		}
		else maxc(mat,d,x+1,y,n,flag,maxm);
		if(mat[x][y]==1){
			mat[x][y]=0;
			maxc(mat,d+1,x,y+1,n,flag,maxm);
			mat[x][y]=1;
		}
		else maxc(mat,d,x,y+1,n,flag,maxm);
	}
	else{
        if(x==0 && y==0){
            if(mat[x][y]){
                maxm = max(maxm, d+1);
            }
            return true;
        }
		if(mat[x][y]==1){
			mat[x][y]=0;
			maxc(mat,d+1,x-1,y,n,flag,maxm);
			mat[x][y]=1;
		}
		else maxc(mat,d,x-1,y,n,flag,maxm);
		if(mat[x][y]==1){
			mat[x][y]=0;
			maxc(mat,d+1,x,y-1,n,flag,maxm);
			mat[x][y]=1;
		}
		else maxc(mat,d,x,y-1,n,flag,maxm);
	}
    return false;
}
int cherryPickup(vector<vector<int>>& grid) {
    int n=grid[0].size();
    bool flag=1;int maxm=0;
    maxc(grid,0,0,0,n,flag,maxm);
    return maxm;
}
int main(){
	int n;cin>>n;
	vector<vector<int>> mat(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		cin>>mat[i][j];
	}
	cout<<cherryPickup(mat)<<endl;
	return 0;
}