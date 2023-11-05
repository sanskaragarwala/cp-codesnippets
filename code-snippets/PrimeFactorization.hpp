#include<bits/stdc++.h>
using namespace std;

const int N=1e7;
vector<int>prime(N+1);

void build(){
    iota(prime.begin(),prime.end(),0);

    for(int i=2;i*i<=1e7;i++){
        if(prime[i]!=i)continue;
        prime[i]=i;
        for(int j=i*i;j<=1e7;j+=i){
            if(prime[j]==j){
                prime[j]=i;
            }
        }
    }
    
}