/* 
    author: Aditya Gupta 
    created: 06.05.2025 14:19:28
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
    bool check(vector<int> &arr,int mid,int k){
        int student = 1;
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(sum>mid){
                student++;
                sum = arr[i];
            }
            if(student>k){
                return false;
            }
        }
        return true;
    }
      int findPages(vector<int> &arr, int k) {
          // code here
          if(k>arr.size()){
            return -1;
          }
           int low = *max_element(begin(arr),end(arr));
           int high = accumulate(begin(arr),end(arr),0);
           int res = -1;
           while(low<=high){
                int mid = low + (high-low)/2;
                if(check(arr,mid,k)){
                    res = mid;
                    high = mid-1;
                }else{
                    low = mid+1;
                }
           }
           return res;
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