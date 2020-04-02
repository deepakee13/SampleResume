#include<iostream>
using namespace std;
int pos(int a){
    if(a>=0)return a;
    else return -1*a;
}
int cost(int p[],int f[],int g[] ){
    int t=0;
    for(int v1=0;v1<3;v1++)
    {
    for(int v=0;v<f[v1];v++)
    {
        t+=pos(g[v1]-p[v1]-v);
    }
    t+=f[v1];
    }
    return t;
}
int main(){
    int N;
    int g[3];
    int f[3];
    int t;
    cin>>t;
    while(t--){
        int ans=1000000;
        cin>>N;
        cin>>g[0]>>f[0]>>g[1]>>f[1]>>g[2]>>f[2];
        for(int i=0;i<3;i++)g[i]--;
        //cin>>f[0]>>f[1]>>f[2];
        int ts=N-f[0]-f[1]-f[2];
        int p[3]={0};
        if(ts<0){cout<<"wrong_config\n";continue;}
        if(ts==0){
            p[0]=0;
            p[1]=p[0]+f[0];
            p[2]=p[1]+f[1];
           cout<<cost(p,f,g)<<"\n";
        }
        else{
        for(int i=0;i<=ts;i++){
            for(int j=0;j<=ts-i;j++){
                for(int k=0;k<=ts-j-i;k++){
                // l=ts-i-j-k;
                p[0]=i;
                p[1]=p[0]+f[0]+j;
                p[2]=p[1]+f[1]+k;
                int ff=cost(p,f,g);
                if(ans>ff){
                    ans=ff;
                    if(ans==82){
                        cout<<g[0]<<" "<<g[1]<<" "<<g[2]<<endl;
                    }
                }
                }
            }
        }
        cout<<ans<<"\n";
        }
        
        
        
    }
}