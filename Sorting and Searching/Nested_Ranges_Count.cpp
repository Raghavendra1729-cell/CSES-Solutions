#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
public:
    explicit FenwickTree(int size) : tree(size + 1, 0) {}

    void add(int index, int value) {
        for (; index < static_cast<int>(tree.size()); index += index & -index) {
            tree[index] += value;
        }
    }

    int prefix_sum(int index) const {
        int result = 0;
        for (; index > 0; index -= index & -index) {
            result += tree[index];
        }
        return result;
    }

private:
    vector<int> tree;
};

struct Range {
    int left;
    int right;
    int original_index;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Range> ranges(n);
    vector<int> right_endpoints;
    right_endpoints.reserve(n);

    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].left >> ranges[i].right;
        ranges[i].original_index = i;
        right_endpoints.push_back(ranges[i].right);
    }

    sort(ranges.begin(), ranges.end(), [](const Range& first, const Range& second) {
        if (first.left != second.left) {
            return first.left < second.left;
        }
        return first.right > second.right;
    });

    sort(right_endpoints.begin(), right_endpoints.end());
    right_endpoints.erase(
        unique(right_endpoints.begin(), right_endpoints.end()),
        right_endpoints.end()
    );

    auto compressed_index = [&](int right) {
        return static_cast<int>(
            lower_bound(right_endpoints.begin(), right_endpoints.end(), right)
            - right_endpoints.begin()
        ) + 1;
    };

    vector<int> contains(n, 0);
    vector<int> contained_by(n, 0);

    FenwickTree fenwick(static_cast<int>(right_endpoints.size()));
    for (int i = n - 1; i >= 0; --i) {
        int index = compressed_index(ranges[i].right);
        contains[ranges[i].original_index] = fenwick.prefix_sum(index);
        fenwick.add(index, 1);
    }

    fenwick = FenwickTree(static_cast<int>(right_endpoints.size()));
    for (int i = 0; i < n; ++i) {
        int index = compressed_index(ranges[i].right);
        contained_by[ranges[i].original_index] =
            i - fenwick.prefix_sum(index - 1);
        fenwick.add(index, 1);
    }

    for (int count : contains) {
        cout << count << ' ';
    }
    cout << '\n';

    for (int count : contained_by) {
        cout << count << ' ';
    }
    cout << '\n';

    return 0;
}
