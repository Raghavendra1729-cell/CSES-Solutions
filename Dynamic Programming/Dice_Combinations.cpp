#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>


/*
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7.
Constraints

1 \le n \le 10^6

Example
Input:
3

Output:
4

*/ 
int testcase = 0;
void solve(){
    int n;
    cin >> n;
    deque<int> temp;
    temp.push_back(1LL);
    int mod = 1e9 + 7;
    for(int i = 1 ; i <= n ; i++){
        int c = 0;
        for(int j = 1 ; j <= 6 ; j++){
            if(j > i)break;
            c = (c % mod + temp[((int)temp.size())-j]) % mod;
        }
        temp.push_back(c);
        if(temp.size() > 6)temp.pop_front();
    }
    cout << temp.back() << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}