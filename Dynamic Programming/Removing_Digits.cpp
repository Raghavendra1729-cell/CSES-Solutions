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
    vector<int> dp(n+1,1e9);
    dp[0]=0;
    for(int i = 1 ; i <= 9 ; i++)dp[i] = 1;
    for(int i = 10 ; i <= n ; i++){
        int temp = i;
        while(temp > 0){
            int m = temp % 10;
            dp[i] = min(dp[i],dp[i-m]+1);
            temp = temp/10;
        }
    }
    cout << dp[n] << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}