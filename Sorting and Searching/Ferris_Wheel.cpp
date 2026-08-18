#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int &i : arr)cin >> i;
    sort(arr.begin(),arr.end());
    int i = 0;
    int j = n-1;
    int c = 0;
    while(i <= j){
        if(i < j && arr[i]+arr[j] <= x){
            c++;
            i++;
            j--;
        }else{
            c++;
            j--;
        }
    }
    cout << c << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}