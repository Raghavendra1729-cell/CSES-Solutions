#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
void solve(){
    int n,t;
    cin >> n >> t;
    vector<int> arr(n);
    for(int &i : arr)cin >> i;
    vector<int> dp(t+1,0);
    dp[0] = 1;
    int mod = 1e9 + 7;
    sort(arr.begin(),arr.end());
    for(int j : arr){
        for(int i = j ; i <= t  ; i++){
            dp[i] = (dp[i] + dp[i-j]) % mod;
        }
    }
    cout << dp[t] << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}