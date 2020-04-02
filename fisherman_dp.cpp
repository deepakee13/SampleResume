// #include<iostream>
// using namespace std;
// #define INT_MAX 9999
// #include <bits/stdc++.h>
// int minimum(int a,int b,int c,int d){
// 	int min1=min(a,b);
// 	int min2=min(c,d);
// 	return min(min1,min2);
// }

// int recur(int nch,int g1,int g2,int g3,int p1,int p2,int p3){
// 	if(g1<0 || g3>=nch)
// 		return INT_MAX;

// 	else if(nch==p1+p2+p3){
// 		//do something
// 		int sum=0;
// 		for(int i=0;i<nch;i++){
// 			if(p1> 0){
// 				sum+=abs(i-g1)+1;
// 				p1--;
// 			}
// 			else if(p2>0){
// 				sum+=abs(i-g2)+1;
// 				p2--;
// 			}
// 			else{
// 				sum+=abs(i-g3)+1;
// 			}
// 		}
// 		return sum;

// 	}

// 	//4 cases
// 	// if(g1!=0 && g3!=nch-1)
// 	return minimum(recur(nch-1,g1-1,g2-1,g3-1,p1,p2,p3),recur(nch-1,g1,g2-1,g3-1,p1,p2,p3),recur(nch-1,g1,g2,g3-1,p1,p2,p3),recur(nch-1,g1,g2,g3,p1,p2,p3));
// 	// else if(g1!=0 && g3==nch-1)
// 	// 	return min(recur(nch-1,g1-1,g2-1,g3-1,p1,p2,p3),recur(nch-1,g1,g2-1,g3-1,p1,p2,p3),recur(nch-1,g1,g2,g3-1,p1,p2,p3));
// 	// else if(g1==0 && g3!=nch-1)
// 	// 	return min(recur(nch-1,g1,g2-1,g3-1,p1,p2,p3),recur(nch-1,g1,g2,g3-1,p1,p2,p3),recur(nch-1,g1,g2,g3,p1,p2,p3));
// 	// else return min(recur(nch-1,g1,g2-1,g3-1,p1,p2,p3),recur(nch-1,g1,g2,g3-1,p1,p2,p3));


// }
// int main(){
// 	int t;cin>>t;
// 	while(t--){
// 		int n;cin>>n;
// 		int g1,p1,g2,p2,g3,p3;
// 		cin>>g1>>p1>>g2>>p2>>g3>>p3;
// 		cout<<recur(n,g1,g2,g3,p1,p2,p3)<<endl;
// 	}

// }
#include<iostream>
using namespace std;

int posi[3];
int people[3];
bool *filled;
int minDis;



void fillPerson(int n, string perm, int i, int person, int l, int r, int tillNow){
	if(i>=3){
		// cout << tillNow << endl;
		minDis=min(minDis, tillNow);
		return;
	}
	else{
		if(tillNow > minDis){
			return;
		}
		if(person==people[perm[i]-'0']){
			fillPerson(n, perm, i+1, 0, posi[(int)(perm[i+1]-'0')], posi[(int)(perm[i+1]-'0')], tillNow);
		}
		else{
			while(l>=0 && filled[l]){
				l--;
			}
			while(r<n && filled[r]){
				r++;
			}
			if(person==people[perm[i]-'0']-1){
				if(person%2==1){
					if(l>=0 && !filled[l]){
						filled[l]=1;
						fillPerson(n, perm, i, person+1, l, r, tillNow+posi[(int)(perm[i]-'0')]-l+1);
						filled[l]=0;
					}
					else{
						filled[r]=1;
						fillPerson(n, perm, i, person+1, l, r, tillNow-posi[(int)(perm[i]-'0')]+r+1);
						filled[r]=0;
					}
				}
				else{
					if(l>=0 && !filled[l]){
						filled[l]=1;
						fillPerson(n, perm, i, person+1, l, r, tillNow+posi[(int)(perm[i]-'0')]-l+1);
						filled[l]=0;
					}
					if(r<n && !filled[r]){
						filled[r]=1;
						fillPerson(n, perm, i, person+1, l, r, tillNow-posi[(int)(perm[i]-'0')]+r+1);
						filled[r]=0;
					}
				}
			}
			else{
				if(l>=0 && !filled[l]){
					filled[l]=1;
					fillPerson(n, perm, i, person+1, l, r, tillNow+posi[(int)(perm[i]-'0')]-l+1);
					filled[l]=0;
				}
				else{
					filled[r]=1;
					fillPerson(n, perm, i, person+1, l, r, tillNow-posi[(int)(perm[i]-'0')]+r+1);
					filled[r]=0;
				}
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i=0;i<3;i++){
			cin >> posi[i] >> people[i];
		}
		filled = new bool[n];
		for(int i=0;i<n;i++){
			filled[i]=0;
		}
		string perm[6];
		perm[0]="012";
		perm[1]="021";
		perm[2]="102";
		perm[3]="120";
		perm[4]="201";
		perm[5]="210";
		minDis=(1<<15)-1;
		for(int i=0;i<6;i++){
			fillPerson(n, perm[i], 0, 0, posi[(int)(perm[i][0]-'0')], posi[(int)(perm[i][0]-'0')], 0);
		}
		cout << minDis << endl;
	}
}