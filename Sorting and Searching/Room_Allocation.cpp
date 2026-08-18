#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
void solve(){
    int n;
    cin >> n;
    vector<tuple<int,int,int>> arr;
    for(int i = 0 ; i < n ; i++){
        int l,r;
        cin >> l >> r;
        arr.push_back({l,1,i});
        arr.push_back({r,2,i});
    }
    sort(arr.begin(),arr.end());
    int c = 0;
    int m = 0;
    vector<int> seat;
    vector<int> used(n,0);
    for(auto [a,e,i] : arr){
        if(e == 1){
            c++;
            if(seat.empty()){
                used[i] = c;
            }else{
                used[i] = seat.back();
                seat.pop_back();
            }
        }else{
            seat.push_back(used[i]);
            c--;
        }
        m = max(m,c);
    }
    cout << m << endl;
    for(int i : used)cout << i << " ";
    cout << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}