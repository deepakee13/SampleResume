#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int gcost=999;
int dist(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}
class point{
public:
	int x,y;
	point(int s, int d){
		x=s;y=d;
	}

};
void minDist(int** space,int size,bool vis[],int curr,int cost){
	if(curr==size-1){
		//destination reached compare cost
		if(gcost>cost)
			gcost=cost;
		return;
	}
	for(int i=1;i<size;i++){
		if(!vis[i]){
			vis[i]=1;
			minDist(space,size,vis,i,cost+space[curr][i]);
			vis[i]=0;
		}
	}
}

class wormhole{
public:
	int x1,y1,x2,y2,d;
	void getData(){
		cin>>x1>>y1>>x2>>y2>>d;
	}
	// wormhole(){

	// }
	// wormhole(int x1,int y1,int x2,int y2,int d){
	// 	x1=x1;y1=y1;x2=x2;y2=y2;d=d;
	// }

};
int main(){
	int s1,s2,d1,d2;
	cin>>s1>>s2>>d1>>d2;
	point src(s1,s2);
	point dest(d1,d2);
	int n;cin>>n;
	wormhole holes[n];
	int x1,x2,y1,y2,d;
	for(int i=0;i<n;i++){
		holes[i].getData();
	}
	// for(int i=0;i<n;i++){
	// 	cout<<holes[i].x1<<holes[i].y1<<endl;
	// }
	//make adjacency matrix
	//starting is source
	//point space[2*n+2][2*n+2];
	//cout<<src.x<<" "<<src.y<<endl;
	int** space=new int*[2*n+2];
	for(int i=0;i<2*n+2;i++){
		space[i]=new int[2*n+2];
	}
	int size=2*n+2;
	for(int i=0;i<size;i++)for(int j=0;j<size;j++)space[i][j]=0;
	//index of wormholes
	for(int i=1;i<=n;i++){
		//start to source
		int st=2*i-1,nd=2*i;
		space[0][st]=dist(holes[i-1].x1,holes[i-1].y1,src.x,src.y);
		space[st][0]=space[0][st];
		//cout<<space[st][0]<<endl;
		//start to dest
		space[2*n+1][st]=dist(holes[i-1].x1,holes[i-1].y1,dest.x,dest.y);
		space[st][2*n+1]=space[2*n+1][st];
		//cout<<space[st][2*n+1]<<endl;
		//end to source
		space[0][nd]=dist(holes[i-1].x2,holes[i-1].y2,src.x,src.y);
		space[nd][0]=space[0][nd];
		//end to dest
		space[2*n+1][nd]=dist(holes[i-1].x2,holes[i-1].y2,dest.x,dest.y);
		space[nd][2*n+1]=space[2*n+1][nd];
		//cout<<space[i][2*n+1]<<endl;
		//start to end
		space[st][nd]=holes[i-1].d;
		space[nd][st]=space[st][nd];
		//source to destination
		space[0][size-1]=dist(src.x,src.y,dest.x,dest.y);
		space[size-1][0]=space[0][size-1];
		for(int j=1;j<=n;j++){
			int jst=2*j-1,jnd=2*j;
			if(i!=j){
				space[st][jst]=dist(holes[i-1].x1,holes[i-1].y1,holes[j-1].x1,holes[j-1].y1);
				space[st][jnd]=dist(holes[i-1].x1,holes[i-1].y1,holes[j-1].x2,holes[j-1].y2);
				space[nd][jst]=dist(holes[i-1].x2,holes[i-1].y2,holes[j-1].x1,holes[j-1].y1);
				space[nd][jnd]=dist(holes[i-1].x2,holes[i-1].y2,holes[j-1].x2,holes[j-1].y2);

				space[jst][st]=space[st][jst];
				space[jnd][st]=space[st][jnd];
				space[jst][nd]=space[nd][jst];
				space[jnd][nd]=space[nd][jnd];
			}
			
		}
	}
	//Now find the minimum distance from index 0 to index 2*n+1;
	
	bool vis[size]={0};
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<space[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	minDist(space,size,vis,0,0);
	cout<<gcost<<endl;
	//cout<<dist(5,5,9,9)<<endl;




}