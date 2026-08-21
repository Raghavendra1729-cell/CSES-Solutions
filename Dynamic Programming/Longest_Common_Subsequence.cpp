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
    vector<int> arr1(n),arr2(m);
    for(int &i : arr1)cin >> i;
    for(int &i : arr2)cin >> i;

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i = 1 ; i <= n ; i++){
        // vector<int> temp(m+1,0);
        for(int j = 1 ; j <= m ; j++){
            if(arr1[i-1] == arr2[j-1]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            }
            dp[i][j] = max({dp[i][j],dp[i-1][j],dp[i][j-1]});
        }
        // dp = temp;
    }
    
    cout << dp[n][m] << endl;
    vector<int> ans;
    int i = n;
    int j = m;
    while(i > 0 && j > 0){
        if(arr1[i-1] == arr2[j-1]){
            ans.push_back(arr1[i-1]);
            i--;
            j--;
        }else{
            if(dp[i][j]== dp[i-1][j]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i : ans)cout << i << " ";
    cout << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}