/* 
    author: Aditya Gupta 
    created: 05.04.2025 17:33:31
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
      // Function to find the minimum number of platforms required at the
      // railway station such that no train waits.
      int findPlatform(vector<int>& arr, vector<int>& dep) {
          // Your code here
          sort(arr.begin(),arr.end());
          sort(dep.begin(),dep.end());
          int i=1,j=0,res=1,count=1,n= arr.size();
          while(i<n && j<n){
              if(arr[i]<= dep[j]){
                  count++;
                  i++;
              }else{
                  count--;
                  j++;
              }
              res= max(count,res);
          }
          return res;
      }
  };
  
void solve() {
    int n;
    cin >> n;

    vector<int> arr(n), dep(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Arrival times
    }
    for (int i = 0; i < n; i++) {
        cin >> dep[i];  // Departure times
    }

    Solution obj;
    int ans = obj.findPlatform(arr, dep);
    cout << ans << "\n";
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