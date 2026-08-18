#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
/*
    to check if a range is inside i can use lower_bound same range to check
    l r i m1   m2
    1 6 0 -1e9 4
    2 4 1 6   6 
    3 6 3 6   8
    4 8 2 6   1e9




    1 1000000000 
    2 1000000000 
*/ 
void solve(){
    int n;
    cin >> n;
    vector<tuple<int,int,int>> arr;
    for(int i = 0 ; i < n ; i++){
        int a,b;
        cin >> a >> b;
        arr.push_back({a,b,i});
    }
    
    sort(arr.begin(),arr.end(),[](tuple<int,int,int> a,tuple<int,int,int> b){
        if(get<0>(a) == get<0>(b)){
            return get<1>(a) > get<1>(b);
        }
        return get<0>(a) < get<0>(b);
    });
    vector<int> mini(n,1e9);
    vector<int> maxi(n,-1e9);
    int m = -2*1e9;
    for(int i = 0 ; i < n ; i++){
        maxi[i] = m;
        m = max(m,get<1>(arr[i]));
    }
    m = 2*1e9;
    for(int i = n-1 ; i >= 0 ; i--){
        mini[i] = m;
        m = min(m,get<1>(arr[i]));
    }

    vector<int> ans1(n,0);
    vector<int> ans2(n,0);
    for(int i = 0 ; i < n ; i++){
        auto [a,b,c] = arr[i];
        // cout << a << " " << b << " " << c << " " << maxi[i] << " " << mini[i] << endl;
        if(b >= mini[i]){
            ans1[c] = 1;
        }
        if(b <= maxi[i]){
            ans2[c] = 1;
        }
    }
    for(int i : ans1)cout << i << " ";
    cout << endl;
    for(int i : ans2)cout << i << " ";
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