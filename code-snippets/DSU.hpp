#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int>parent;
    vector<int>rank;
    public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        // siz.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    void UnionbyRank(pair<int,int>edg){
        int pn1=findParent(edg.first);
        int pn2=findParent(edg.second);
        if(pn1==pn2)return;
        if(rank[pn1]<=rank[pn2]){
            if(rank[pn1]==rank[pn2]){
                rank[pn2]++;
            } 
            parent[pn1]=pn2;
        }else{
            parent[pn2]=pn1;
        }
    }
};