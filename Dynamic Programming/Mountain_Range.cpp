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
    vector<int> A(n);
    for(int &i : A)cin >> i;

    priority_queue<pair<int,int>> pq;
    for(int i = 0 ; i < n ; i++){
        pq.push({A[i],i});
    }

    vector<int> left(n);
    deque<int> dq1;
    for(int i = 0 ; i < n ; i++){
        while(!dq1.empty() && A[i] >= A[dq1.back()]){
            dq1.pop_back();
        }
        if(dq1.empty()){
            left[i] = -1;
        }else{
            left[i] = dq1.back();
        }
        dq1.push_back(i);
    }



    vector<int> right(n);
    deque<int> dq2;
    for(int i = n-1 ; i >= 0 ; i--){
        while(!dq2.empty() && A[i] >= A[dq2.back()]){
            dq2.pop_back();
        }
        if(dq2.empty()){
            right[i] = n;
        }else{
            right[i] = dq2.back();
        }
        dq2.push_back(i);
    }

    /*
    -1 0 1 2 3 4 5 6 7 8
    */ 


    vector<int> dp(n+2,0);
    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        int l = left[temp.second];  
        int r = right[temp.second];  
        dp[temp.second+1] = max(dp[l+1],dp[r+1]) + 1;
    }


    int ans = *max_element(dp.begin(),dp.end());
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