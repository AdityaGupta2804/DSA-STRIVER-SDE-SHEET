/* 
    author: Aditya Gupta 
    created: 05.04.2025 20:18:30
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
        static bool  customComparator(const pair<pair<int, int>, double>& a, const pair<pair<int, int>, double>& b) {
            return a.second > b.second; // Compare the double values in descending order
        }    
      // Function to get the maximum total value in the knapsack.
        double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
          // Your code here
          int n = wt.size();
          /*weight , value*/
          vector<pair<pair<int,int>,double>> knapsack;
          for(int i=0;i<n;i++){
              knapsack.push_back({{wt[i],val[i]},(double)val[i]/wt[i]});
          }
          sort(knapsack.begin(),knapsack.end(),customComparator);
          double ans =0;
          for(auto item: knapsack){
            if(item.first.first<= capacity){
                ans+= item.first.second;
                capacity-= item.first.first;
            }else{
                ans+= item.second*capacity;
                break;
            }
          }
          return ans;
      }
};
void solve(){
  int n,capacity;
  cin>>n;
  vector<int> val(n),wt(n);
  for(auto &it : val)cin>>it;
  for(auto &it : wt)cin>>it;
  cin>>capacity;
  Solution obj;
  double ans = obj.fractionalKnapsack(val,wt,capacity);
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