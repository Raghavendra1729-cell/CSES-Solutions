#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;

vector<int> col(8,0),row(8,0),diag1(14,0),diag2(14,0);
int rec(int i,vector<string>& arr){
    if(i == 8)return 1;
    int ans = 0;
    for(int j = 0 ; j <= 7 ; j++){
        if(arr[i][j] == '*')continue;
        if(row[i] || col[j] || diag1[i+j] || diag2[i-j+7])continue;
        row[i] = col[j] = diag1[i+j] = diag2[i-j+7] = 1;
        ans += rec(i+1,arr);
        row[i] = col[j] = diag1[i+j] = diag2[i-j+7] = 0;
    }
    return ans;
}
void solve(){
    vector<string> arr(8);
    for(auto &i : arr)cin >> i;
    int ans = rec(0,arr);
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