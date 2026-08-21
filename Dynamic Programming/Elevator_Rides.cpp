#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n, x;
    if (!(cin >> n >> x)) return;

    vector<int> weight(n);
    for (int &w : weight) cin >> w;

    vector<pair<int, int>> dp(1 << n, {n + 1, 0});
    dp[0] = {1, 0};

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                auto prev = dp[mask ^ (1 << i)];
                pair<int, int> option;
                if (prev.second + weight[i] <= x) {
                    option = {prev.first, prev.second + weight[i]};
                } else {
                    option = {prev.first + 1, weight[i]};
                }
                dp[mask] = min(dp[mask], option);
            }
        }
    }

    cout << dp[(1 << n) - 1].first << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}