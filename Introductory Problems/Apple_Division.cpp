#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;

long long ans = 1e18;
void rec(int i,vector<int>& arr,int s1,int s2){
    if(i == arr.size()){
        ans = min(ans,abs(s1-s2));
        return;
    }
    rec(i+1,arr,s1,s2);
    rec(i+1,arr,s1+arr[i],s2-arr[i]);
}
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr)cin >> i;
    int sum = accumulate(arr.begin(),arr.end(),0LL);
    rec(0,arr,0LL,sum);
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