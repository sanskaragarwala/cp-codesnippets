#include <bits/stdc++.h>
using namespace std;

class Sparse{

    //Initial Value
    int MAX_N = 100'005;
    int LOG = 17;
    vector<int>a;
    vector<vector<int>> m; // m[i][j] is minimum among a[i..i+2^j-1]
    vector<int> bin_log;

    public:
    Sparse(){
        a.resize(MAX_N);
        m=vector<vector<int>>(MAX_N,vector<int>(LOG,0));
        bin_log.resize(MAX_N,0);
    }
    void build(int n,vector<int>&a){
        bin_log[1] = 0;
        for(int i = 2; i <= n; i++) {
            bin_log[i] = bin_log[i/2]+1;
        }
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            m[i][0] = a[i];
        }
        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i + (1 << k) - 1 < n; i++) {
                m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
            }
        }
    }
    int query(int L, int R) { // O(1)
        int length = R - L + 1;
        int k = bin_log[length];
        return min(m[L][k], m[R-(1<<k)+1][k]);
    }

};


void solve() {
	// 1) read input
	int n;
	cin >> n;
    vector<int>a(n);
	
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
    Sparse s;
    // 2) preprocessing, O(N*log(N))
    s.build(n,a);
	
	// 3) answer queries
	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		int L, R;
		cin >> L >> R;
		cout << s.query(L, R) << "\n";
	}
}