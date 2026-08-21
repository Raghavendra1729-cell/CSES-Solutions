#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int MOD = 1e9 + 7;

void generate_next_masks(int current_mask, int next_mask, int row, int n, vector<int>& next_states) {
    if (row == n) {
        next_states.push_back(next_mask);
        return;
    }
    if (current_mask & (1 << row)) {
        generate_next_masks(current_mask, next_mask, row + 1, n, next_states);
    } else {
        // Place horizontal tile extending into next column
        generate_next_masks(current_mask, next_mask | (1 << row), row + 1, n, next_states);
        // Place vertical tile covering (row, row+1) in current column
        if (row + 1 < n && !(current_mask & (1 << (row + 1)))) {
            generate_next_masks(current_mask, next_mask, row + 2, n, next_states);
        }
    }
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<int> dp(1 << n, 0);
    dp[0] = 1;

    for (int col = 0; col < m; ++col) {
        vector<int> next_dp(1 << n, 0);
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[mask] == 0) continue;
            vector<int> next_states;
            generate_next_masks(mask, 0, 0, n, next_states);
            for (int next_mask : next_states) {
                next_dp[next_mask] = (next_dp[next_mask] + dp[mask]) % MOD;
            }
        }
        dp = next_dp;
    }

    cout << dp[0] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}