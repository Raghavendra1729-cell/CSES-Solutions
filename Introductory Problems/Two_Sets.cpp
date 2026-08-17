#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
void solve(){
    int n;
    cin >> n;
    int sum = (n * (n+1)) >> 1LL;
    if(sum&1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int half = sum/2;
    vector<int> a,b;
    for(int i = n; i >= 1 ; i--){
        if(half >= i){
            half -= i;
            a.push_back(i);
        }else{
            b.push_back(i);
        }
    }
    int n_a = a.size();
    int n_b = b.size();
    cout << n_a << endl;
    for(int i = 0 ; i < n_a ; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    cout << n_b << endl;
    for(int i = 0 ; i < n_b ; i++){
        cout << b[i] << " ";
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