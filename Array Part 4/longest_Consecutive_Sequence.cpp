/* 
    author: Aditya Gupta 
    created: 22.02.2025 22:46:16
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

int longestConsecutive(vector<int>& nums) {
    unordered_set<int>  s;
    for(auto ele : nums){
        s.insert(ele);
    } 
    int longest = 0;
    for(auto ele : s){
        if(s.find(ele-1) == s.end()){
            int x = ele; 
            int count = 1;
            while(s.find(x+1)!=s.end()){
                x=x+1;
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}
void solve(){
   int n;
   cin>>n;
   vector<int> nums(n);
   for(auto &it : nums){
    cin>>it;
   }
   int res = longestConsecutive(nums);
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