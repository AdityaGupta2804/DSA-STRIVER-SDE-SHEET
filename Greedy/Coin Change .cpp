/* 
    author: Aditya Gupta 
    created: 05.04.2025 21:00:20
*/

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
// Template to debug 1 variable
template<typename T>
void debug1(const char* varName, T varValue) {
    cout << varName << " = " << varValue << endl;
}
// Template to debug 2 variables
template<typename T1, typename T2>
void debug2(const char* varName1, T1 varValue1, const char* varName2, T2 varValue2) {
    cout << varName1 << " = " << varValue1 << " " << varName2 << " = " << varValue2 << endl;
}
// Template to print a vector
template<typename T>
void debug_vector(const char* varName, const vector<T>& vec) {
    cout << varName << " = [";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

#define debug1(var) debug1(#var, var)
#define debug2(var1, var2) debug2(#var1, var1, #var2, var2)
#define debug_vector(vec) debug_vector(#vec, vec)

#else
#define debug1(var)
#define debug2(var1, var2)
#define debug_vector(vec)
#endif

#define int long long
class Solution {
    public:
      int minCoins(vector<int> &coins, int sum) {
          int n = coins.size();
          vector<int> dp(sum+1,1e8);
          dp[0] = 0;
          for(int i=1;i<=sum;i++){
              for(auto coin : coins){
                  if(coin<=i){ 
                      dp[i] = min(dp[i],1+dp[i-coin]);
              
                  }
                      
              }
          }
          return (dp[sum] == 1e8) ? -1 : dp[sum];   
      }
  };
void solve(){
   int n,sum;
   cin>>n;
   vector<int> coins(n);
   for(auto &it : coins)cin>>it;
   cin>>sum;
   Solution obj;
   int ans = obj.minCoins(coins,sum);
   cout<<ans<<endl;
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