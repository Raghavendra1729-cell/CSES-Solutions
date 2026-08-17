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
    int m = max(a,b);
    int t = m-1;
    int num = t * t;
    num += m;
    if(b < a){
        if(m&1){
            num -= a-b;
        }else{
            num += a-b;
        }
    }else if(a < b){
        if(m&1){
            num += b-a;
        }else{
            num -= b-a;
        }
    }

    cout << num << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}