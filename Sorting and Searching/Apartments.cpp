#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for(int &i : a)cin >> i;
    for(int &i : b)cin >> i;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int j = 0;
    int c = 0;

    // for(int i : a)cout << i << " ";
    // cout << endl;
    // for(int i : b)cout << i << " ";
    // cout << endl;
    for(int i = 0 ; i < n ; i++){
        while(j < m && b[j] < a[i]-k){
            j++;
        }
        if(j == m)break;
        // cout << i << " " << j << endl;
        if(b[j] <= a[i]+k){
            j++;
            c++;
        }
    }
    cout << c << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}