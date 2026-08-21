#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;

/*
   L O V E
M. 
O
V
I
E

*/ 
/*
Add one character to the string.
dp[i][j] = dp[i-1][j] + 1;
Remove one character from the string.
dp[i][j] = dp[i][j-1] + 1;
Replace one character in the string.
dp[i][j] = dp[i-1][j-1] + 1;
*/
void solve(){
    string s,t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<int> dp(m+1,1e9);
    for(int j = 0 ; j <= m ; j++)dp[j] = j;
    for(int i = 1 ; i <= n ; i++){
        vector<int> temp(m+1,1e9);
        temp[0] = i;
        for(int j = 1 ; j <= m ; j++){
            if(s[i-1] == t[j-1]){
                temp[j] = min(temp[j],dp[j-1]);
            }
            temp[j] = min({temp[j],dp[j]+1,temp[j-1]+1,dp[j-1]+1});
        }
        dp = temp;
    }


    cout << dp[m] << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}