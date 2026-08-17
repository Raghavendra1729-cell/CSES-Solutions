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
    for(int i = 1 ; i <= n ; i++){
        int total = ((i*i*1LL) * ((i*i*1LL) - 1)) >> 1LL;
        int kill = 4LL * (i-1) * (i-2);
        // cout << i << " " << total << " " << kill << endl;
        cout << total-kill << endl;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}