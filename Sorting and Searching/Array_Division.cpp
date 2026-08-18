#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;

int check(int m,vector<int>& arr,int k){
    int curr = 0;
    for(int i : arr){
        if(curr + i > m){
            k--;
            curr = 0;
        }
        curr += i;
    }
    k--;
    return k >= 0;
}
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &i : arr)cin >> i;
    int s = *max_element(arr.begin(),arr.end());
    int e = accumulate(arr.begin(),arr.end(),0LL);
    int ans = 0;
    while(s <= e){
        int mid = s + ((e-s) >> 1LL);
        if(check(mid,arr,k)){
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