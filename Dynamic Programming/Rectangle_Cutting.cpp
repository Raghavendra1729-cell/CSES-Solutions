#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
/*

00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33

*/ 
int testcase = 0;
void solve(){
    int n,m;
    cin >> n >> m;
    if(n > m)swap(n,m);
    vector<vector<int>> dp(n+1,vector<int>(m+1,1e9));

    for(int i = 1 ; i <= min(n,m) ; i++)dp[i][i] = 0;

    for(int i = 1  ; i <= n ; i++){
        for(int j = i ; j <= m ; j++){
            for(int k = 1 ; k < i ; k++){
                dp[i][j] = min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
            }
            for(int k = 1 ; k < j ; k++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
            }
            if(j <= n && i <= m){
                dp[j][i] = dp[i][j];
            }
        }
    }
    cout << dp[n][m] << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}