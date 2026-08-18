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
    vector<int> A(n),B(m);
    for(int &i : A)cin >> i;
    for(int &i : B)cin >> i;

    multiset<int> s;
    for(int i : A)s.insert(i);
    for(int i : B){
        auto it = s.upper_bound(i);
        if(it == s.begin()){
            cout << -1 << endl;
        }else{
            it--;
            cout << *it << endl;
            s.erase(it);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}