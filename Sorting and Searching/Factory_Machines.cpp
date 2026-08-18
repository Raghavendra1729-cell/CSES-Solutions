#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
int check(vector<int>& arr,int m,int k){
    for(int i : arr){
        if(i > m)break;
        k -= m/i;
    }
    return k <= 0;
}
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &i : arr)cin >> i;
    sort(arr.begin(),arr.end());
    int s = 0;
    int e = arr[0] * 1LL* k;
    int ans = e;
    while(s <= e){
        int mid = s + ((e-s) >> 1);
        if(check(arr,mid,k)){
            ans = mid;
            e = mid-1;
        }else{
            s = mid+1;
        }
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