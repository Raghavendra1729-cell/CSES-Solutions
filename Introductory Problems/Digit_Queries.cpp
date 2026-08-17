#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 1;
int countOfDigitsBefore(int n){
    int d = to_string(n).size();
    long long t = 1;
    long long c = 0;
    for(int i = 1 ; i < d ; i++){
        c += 9LL * t * i;
        t = t * 10;
    }
    c += (n - t + 1) * d;
    return c;
}
void solve(){
    int n;
    cin >> n;
    int ans = 1;
    int s = 1;
    int e = 1e18;
    while(s <= e){
        int mid = s + ((e-s) >> 1);
        int c = countOfDigitsBefore(mid);
        if(c >= n){
            ans = mid;
            e = mid-1;
        }else{
            s = mid+1;
        }
    }

    int c = countOfDigitsBefore(ans);
    while(c > n){
        ans = ans/10;
        c--;
    }

    ans = ans % 10;
    cout << ans << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}