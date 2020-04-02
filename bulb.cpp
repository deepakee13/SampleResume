#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main() {
	// your code goes here
	int n;cin>>n;
	int k;cin>>k;
	string str;cin>>str;
	
	int z=0;
	int arr[n]={0};
	for(int i=0;i<n;i++)if(str[i]=='0'){arr[z]=i;z++;}
	k=k+1;
	int diff=INT_MAX;
	int st,nd,mid,mid1;
	if(k%2!=0){
	    for(int i=0;i<z;i++){
	        st=i;nd=i+k-1;
	        if(nd<z){
	           mid=(st+nd)/2;
	           //print
	           diff=min(diff,max(arr[mid]-arr[st],arr[nd]-arr[mid]));
	        }
	    }
	}
	else{
	    for(int i=0;i<z;i++){
	        st=i;nd=i+k-1;
	        if(nd<z){
	           mid=(st+nd)/2;mid1=mid+1;
	           diff=min(diff,max(arr[mid]-arr[st],arr[nd]-arr[mid]));
	           diff=min(diff,max(arr[mid1]-arr[st],arr[nd]-arr[mid1]));
	        }
	    }
	}
	cout<<diff<<endl;
	return 0;
}
