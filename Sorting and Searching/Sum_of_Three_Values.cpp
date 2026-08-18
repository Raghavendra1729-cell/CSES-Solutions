#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
void solve(){
    int n,t;
    cin >>n >> t;
    vector<pair<int,int>> arr;
    for(int i = 0 ; i < n ; i++){
        int temp;
        cin >> temp;
        arr.push_back({temp,i});
    }
    sort(arr.begin(),arr.end());
    for(int i = 0 ; i < n ; i++){
        int temp = t - arr[i].first;
        int j = i+1;
        int k = n-1;
        while(j < k){
            int sum = arr[j].first + arr[k].first;
            if(sum == temp){
                cout << arr[i].second+1 << " " << arr[j].second+1 << " " << arr[k].second+1 << endl;
                return;
            }else if(sum < temp){
                j++;
            }else{
                k--;
            }
        } 
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