#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    vector<int> lis;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), x[i]);
        if (it == lis.end()) {
            lis.push_back(x[i]);
        } else {
            *it = x[i];
        }
    }

    cout << lis.size() << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
