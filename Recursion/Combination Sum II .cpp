/* 
    author: Aditya Gupta 
    created: 06.04.2025 15:14:43
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
    static void combination(int start,vector<int> &candidates,int target,vector<int> &curr,vector<vector<int>> &ans){
       
        if(target == 0){
            ans.push_back(curr);
            return;

        }
        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i] == candidates[i-1] ) continue;
            if(candidates[i]<= target){
                curr.push_back(candidates[i]);
                combination(i+1,candidates,target- candidates[i],curr,ans);
                curr.pop_back();
            }else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        combination(0,candidates,target,curr,ans);
        return ans;
    }
};
void solve(){
   int n,target;
   cin>>n;
   vector<int> candidates(n);
   for(auto &i : candidates)cin>>i;
   cin>>target;
   Solution obj;
   vector<vector<int>> res = obj.combinationSum2(candidates,target);
   for(auto i: res){
    for(auto j: i){
        cout<<j<<" ";
    }
    cout<<endl;
   }
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