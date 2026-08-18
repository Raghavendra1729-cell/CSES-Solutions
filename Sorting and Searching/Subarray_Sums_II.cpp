#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
void solve(){
    int n,t;
    cin >> n >> t;
    vector<int> arr(n);
    for(int &i : arr)cin >> i;
    map<int,int> M;
    M[0]++;
    int s = 0;
    int ans = 0;
    for(int i : arr){
        s += i;
        /*
            s-w = t;
            s-t = w;
        */ 
        int temp = s - t;
        ans += M[temp];
        M[s]++;
    }

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