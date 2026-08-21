#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 1;
vector<pair<int,int>> dp(1e6+1);
int mod = 1e9 + 7;
void fill(){
    dp[1].first = 1;
    dp[1].second = 1;
    for(int i = 2 ; i <= 1e6 ; i++){
        /*
        not connected
        both extented - 1  , only one extended - 2 , none extened
        + 1 conneted and none extended

        dp[i].first = 4*dp[i-1].first + dp[i-1].second
        */ 
        dp[i].first =  (4LL*dp[i-1].first + dp[i-1].second) % mod;

        /*
        connected
        both extended + none exteneded and 1 full block

        not connteted
        only 1 full block
        dp[i].second = 2*dp[i-1].second + dp[i-1].first;
        */ 
        dp[i].second =  (2LL * dp[i-1].second + dp[i-1].first)  % mod;
    } 
}

void solve(){
    int n;
    cin >> n;
    int ans = (dp[n].first + dp[n].second) % mod;
    cout << ans << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fill();
    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}