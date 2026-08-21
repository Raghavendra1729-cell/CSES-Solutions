#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0) {
        cout << 0 << endl;
        return;
    }

    int target = sum / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    // Process elements 1 to n-1 to fix element n in the second set
    for (int i = 1; i < n; i++) {
        for (int j = target; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    cout << dp[target] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}