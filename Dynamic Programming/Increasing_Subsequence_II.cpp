#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;


int mod = 1e9 + 7;
int Findex(vector<int>& arr,int num){
    auto it = lower_bound(arr.begin(),arr.end(),num) - arr.begin();
    return it+1;
}


struct fenwickTree{
    vector<int> bits;
    int n;
    fenwickTree(int n){
        bits.assign(n+1,0);
        this->n = n;
    }

    void update(int index,int num){
        while(index <= n){
            bits[index] = (num + bits[index]) % mod;
            index += index & -index;
        }
    }


    int query(int index){
        int sum = 0;
        while(index > 0){
            sum = (sum + bits[index]) % mod;
            index -= index & -index;
        }
        return sum;
    }

};

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr)cin >> i;


    vector<int> arr2;
    for(int i : arr)arr2.push_back(i);
    sort(arr2.begin(),arr2.end());
    arr2.erase(unique(arr2.begin(),arr2.end()),arr2.end());

    fenwickTree ft(n);

    int ans = 0;
    for(int i : arr){
        int index = Findex(arr2,i);
        int temp = (1 + ft.query(index-1)) % mod;
        ft.update(index,temp);
        ans = (ans + temp) % mod;
    }


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