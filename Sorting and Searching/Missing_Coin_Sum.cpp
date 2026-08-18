#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
/*
    what can we do ?
    sort it

    1 2 2 7 9 

    now what can i do

    can i apply dp 
    no constrainsts are till 10^9

    1 - 1;
    2 - 1;
    3 - 1;


    lets do range wise 

    start with 1 
    [0,1) to ....
*/ 
void solve(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int &i : A)cin >> i;
    sort(A.begin(),A.end());
    int r = 1; 
    for(int i : A){
        if(i > r){
            break;
        }else{
            r = r + i;
        }
    }
    cout << r << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}