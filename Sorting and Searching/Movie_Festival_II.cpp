#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;

/*
5 
5 


1 5 1 
2 5 2
3 6 cant 
6 9 1 
8 10 2 


*/ 
void solve(){
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> arr;
    for(int i = 0 ;i < n ; i++){
        int l,r;
        cin >> l >> r;
        arr.push_back({l,r});
    }
    sort(arr.begin(),arr.end(),[](pair<int,int>& a,pair<int,int>& b){
        if(a.second == b.second)return a.first < b.first;
        return a.second < b.second;
    });

    multiset<int> ms;
    int c = 0;
    for(auto[a,b] : arr){
        auto it = ms.lower_bound(a);
        if(it == ms.begin() && *it != a){
            if(k){
                ms.insert(b);
                c++;
                k--;
            }
        }else{
            if(*it != a){
                it--;
            }
            ms.erase(it);
            ms.insert(b);
            c++;
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