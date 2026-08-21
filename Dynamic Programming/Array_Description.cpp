#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> arr(n,0);

    for(int &i : arr)cin >> i;
    vector<int> dp(m+2,0);

    if(arr[0] != 0)dp[arr[0]] = 1;
    else{
        for(int i = 1 ; i <= m ; i++){
            dp[i] = 1;
        }
    }

    int mod = 1e9 + 7;


    for(int i = 1 ; i < n ; i++){
        vector<int> temp(m+2,0);
        if(arr[i] != 0){
            temp[arr[i]] = (dp[arr[i]-1] + dp[arr[i]] + dp[arr[i]+1]) % mod;
        }else{
            for(int j = 1 ; j <= m ; j++){
                temp[j] = (dp[j-1] + dp[j] + dp[j+1]) % mod;
            }
        }
        dp = temp;
        // for(int i : dp)cout << i << " ";
        // cout << endl;
    }

    int sum = accumulate(dp.begin(),dp.end(),0LL);
    sum = sum % mod;
    cout << sum << endl;

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}