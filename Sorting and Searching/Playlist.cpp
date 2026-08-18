#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
void solve(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int &i : A)cin >> i;
    map<int,int> M;
    int m = -1;
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(M.count(A[i]))m = max(m,M[A[i]]);
        ans = max(ans,i-m);
        M[A[i]] = i;
    }
    cout << ans << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}