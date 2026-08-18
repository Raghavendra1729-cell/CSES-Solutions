#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
/*
    3 8 2 1 5 

    3 2 1 , 8 5 

    1 2 7 4 3 2 5 6
    
    1 2 5 2 6
    
    1 2 5 6 
*/
void solve(){
    int n;
    cin >> n;
    int c = 0;
    vector<int> A;
    for(int i = 0 ; i < n ; i++){
        int temp;
        cin >> temp;
        if(A.empty() || A.back() <= temp){
            c++;
            A.push_back(temp);
        }else{
            auto it = upper_bound(A.begin(),A.end(),temp);
            *it = temp;
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