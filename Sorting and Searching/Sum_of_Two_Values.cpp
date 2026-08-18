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
    for(int &i : arr)cin >>i;
    map<int,int> index;
    for(int i = 0 ; i < n ; i++){
        int x = t - arr[i];
        if(index.count(x)){
            cout << index[x]+1 << " " << i+1 << endl;
            return;
        } 
        index[arr[i]] = i;
    }
    cout << "IMPOSSIBLE" << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}