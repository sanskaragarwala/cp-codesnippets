#include<bits/stdc++.h>
using namespace std;


const int MAXN=1e6;
//Size of BIT is same as size of array except that 1 based indexing is done
class FenTree{

    int BIT[MAXN];
    int N;
    vector<int>a;
    public:
    FenTree(int n,vector<int>&b){
        N=n;
        a=b;
    }
    void update(int x,int val) { 
        ++x;  
        while(x<=N) {  
            BIT[x]+=val;
            x+=(x&-x);  
        } 
    }
    void initialize(){
        BIT[0]=0;
        for (int i=1; i<=N; i++) BIT[i] = 0; 
  
        // Store the actual values in BITree[] using update() 
        for (int i=0; i<N; i++) 
            update(i, a[i]); 
    }


    int query(int x) {  

        //Making 1 based Index
        ++x;  
        int res=0;  
        while(x>0){  
            res+=BIT[x];  
            x-=(x&-x);  //Removing last set lsb x&-x
        } 
        return res; 
    } 
};




