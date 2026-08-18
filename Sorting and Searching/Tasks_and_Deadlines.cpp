#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;

/*

deadline - time taken


sum(deadline - timetaken)


sum(deadline) - sum(timetaken)

minimize sum(timetaken) sort via duration

*/ 
void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> arr;
    int Dsum = 0LL;
    for(int i = 0 ; i < n ; i++){
        int du,de;
        cin >> du >> de;
        Dsum += de;
        arr.push_back({du,de});
    }

    sort(arr.begin(),arr.end());
    int  carry = 0LL;
    int  Tsum = 0LL;
    for(auto [a,b] : arr){
        carry += a;
        Tsum += carry;
    }


    cout << Dsum - Tsum << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}