/* 
    author: Aditya Gupta 
    created: 06.04.2025 13:16:25
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
    void backtrack(vector<int> &nums,int start,vector<int> &curr,vector<vector<int>> &res){
        res.push_back(curr);
        
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            backtrack(nums,i+1,curr,res);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(nums,0,curr,res);
        return res;
    }
};
void solve(){
   int n;
   cin>>n;
   vector<int> nums(n);
   for(auto &i: nums)cin>>i;
   Solution obj;
   vector<vector<int>> res = obj.subsetsWithDup(nums);
   for(auto i: res){
        for(auto j: i ){
            cout<<j<<" ";
        }
        cout<<endl;
   }
   cout<<"Answer end here"<<endl;
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