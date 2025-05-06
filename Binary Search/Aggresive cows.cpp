/* 
    author: Aditya Gupta 
    created: 06.05.2025 14:07:42
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
        bool check(vector<int> & stalls,int k,int mid)
        {
            int count = 1;
            int prev = stalls[0];
            for(int i = 1;i<stalls.size();i++){
                if(stalls[i]-prev>=mid){
                    prev = stalls[i];
                    count++;
                }
            }
            return (count >= k);
        }
      int aggressiveCows(vector<int> &stalls, int k) {
        sort(begin(stalls),end(stalls));
        int low = 1,high = stalls.back()-stalls[0];
        int res = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(stalls,k,mid)){
                res= mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return res;
      }
  };
void solve(){
   int n;
   cin>>n;
   vector<int> stalls(n);
   for(auto &it: stalls) cin>>it;
   int k;
   cin>>k;
   Solution obj;
   int res = obj.aggressiveCows(stalls,k);
   cout<<" result- : "<<res<<endl;

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