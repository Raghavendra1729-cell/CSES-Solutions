#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;


#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
/*

0 1 2 3 4 5 6 
1. 2 3 4 5 6 7
*/ 

void solve(){
    int n,k;
    cin >> n >> k;
    oset ose;
    for(int i = 1 ; i <= n ; i++){
        ose.insert(i);
    }
    int c = 0;
    for(int i = 0 ; i < n ; i++){
        c = (c + k) % ose.size();
        auto it = ose.find_by_order(c);
        cout << *it << " ";
        ose.erase(it);
    }
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