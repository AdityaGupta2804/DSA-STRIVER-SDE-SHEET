/* 
    author: Aditya Gupta 
    created: 06.05.2025 14:20:34
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
      int kthElement(vector<int>& a, vector<int>& b, int k) {
          if (a.size() > b.size())
              return kthElement(b, a, k);
      
          int m = a.size(), n = b.size();
          int l = max(0ll, k - n), r = min(k, m);
      
          while (l <= r) {
              int i = l + (r - l) / 2;   // Elements from a
              int j = k - i;             // Elements from b
      
              int aLeft = (i == 0) ? INT_MIN : a[i - 1];
              int bLeft = (j == 0) ? INT_MIN : b[j - 1];
              int aRight = (i == m) ? INT_MAX : a[i];
              int bRight = (j == n) ? INT_MAX : b[j];
      
              if (aLeft <= bRight && bLeft <= aRight) {
                  return max(aLeft, bLeft);
              } else if (aLeft > bRight) {
                  r = i - 1;
              } else {
                  l = i + 1;
              }
          }
      
          return -1;  // Should never reach here if k is valid
      }
  
  };
void solve(){
   
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