#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 1;
void solve(){
    int a,b;
    cin >> a >> b;

    int x = 2*a - b;
    int y = 2*b - a;
    if(((a + b) % 3 == 0) && x >= 0 && y >= 0 ){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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