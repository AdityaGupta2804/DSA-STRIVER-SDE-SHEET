/* 
    author: Aditya Gupta 
    created: 10.02.2025 15:35:52
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices){
    int buy =  prices[0], profit = 0;
    for(int i=1;i<prices.size();i++){
        if(prices[i]<buy){
            buy = prices[i];
        }
        profit=max(profit,prices[i]-buy);
    }
    return profit;
}
void solve(){
    int n;
    cin>>n;
    vector<int> prices(n);
    for(auto &it : prices) cin>>it;
    int res = maxProfit(prices);
    cout<<res<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cerr << "Execution Time: " << duration.count() << " ms" << std::endl;

    return 0;
}