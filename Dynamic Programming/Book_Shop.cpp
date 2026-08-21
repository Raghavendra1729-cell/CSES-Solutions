#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;

/*
You are in a book shop which sells n different books. You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.
Input
The first input line contains two integers n and x: the number of books and the maximum total price.
The next line contains n integers h_1,h_2,\ldots,h_n: the price of each book.
The last line contains n integers s_1,s_2,\ldots,s_n: the number of pages of each book.
Output
Print one integer: the maximum number of pages.
Constraints

1 \le n \le 1000
1 \le x \le 10^5
1 \le h_i, s_i \le 1000

*/ 
void solve(){
    int size,budget;
    cin >> size >> budget;
    vector<int> price(size),pages(size);
    for(int &i : price)cin >> i;
    for(int &i : pages)cin >> i;

    vector<int> budgets(budget+1,0);
    for(int i = 0 ; i < size ; i++){
        int price_curr = price[i];
        int pages_curr = pages[i];
        for(int b = budget ; b >= price_curr ; b--){
            budgets[b] = max(budgets[b],budgets[b-price_curr]+pages_curr);
        }
    }

    // for(auto b : budgets){
    //     cout << b << " ";
    // 
    // cout << endl;

    int max_pages = *max_element(budgets.begin(),budgets.end());
    cout << max_pages << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}