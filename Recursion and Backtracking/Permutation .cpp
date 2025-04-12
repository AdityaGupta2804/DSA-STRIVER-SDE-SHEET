/* 
    author: Aditya Gupta 
    created: 09.04.2025 02:41:48
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
/*Approach 1*/
// class Solution {
//     public:
//         static bool getnextpermutation(vector<int> &nums){
//             int n = nums.size();
//             int i = n-2;
//             while(i>=0 && nums[i]>= nums[i+1]){
//                 i--;
//             }
//             if(i<0) return false;
//             int j= n-1;
//             while(nums[j]<=nums[i]){
//                 j--;
//             }
//             swap(nums[i],nums[j]);
//             reverse(nums.begin()+i+1,nums.end());
//             return true;

//         }
//         vector<vector<int>> permute(vector<int>& nums) {
//             vector<vector<int>> res;
//             sort(nums.begin(),nums.end());
//             do{
//                 res.push_back(nums);
//             }while(getnextpermutation(nums));
//             return res;
//         }
// };

/*Approach 2*/
// class Solution {
//     public:
//         vector<vector<int>> permute(vector<int>& nums) {
//             vector<vector<int>> res;
//             sort(nums.begin(),nums.end());
//             do{
//                 res.push_back(nums);
//             }while(next_permutation(nums.begin(),nums.end()));
//             return res;
//         }
// };
/*Approach 3*/
class Solution {
        public:
        void backtrack(vector<int> &nums,int idx,vector<vector<int>> &res){
            if(idx == nums.size()){
                res.push_back(nums);
                return;
            }
            for(int i=idx; i<nums.size();i++){
                swap(nums[i],nums[idx]);
                backtrack(nums,idx+1,res);
                swap(nums[i],nums[idx]);
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> res;
            backtrack(nums,0,res);
            return res; 
        }
};
/*Approach 4*/
// class Solution {
//     public:
//         void backtrack(vector<int> &nums,vector<int> &temp,unordered_set<int> &st, vector<vector<int>> &res){
//             if(temp.size() == nums.size()){
//                 res.push_back(temp);
//                 return;
//             }
//             for(int i=0;i<nums.size();i++){
//                 if(st.find(nums[i]) == st.end()){
//                     temp.push_back(nums[i]);
//                     st.insert(nums[i]);
//                     backtrack(nums,temp,st,res);
//                     temp.pop_back();
//                     st.erase(nums[i]);  
//                 }
//             }
//         }
//         vector<vector<int>> permute(vector<int>& nums) {
//             vector<vector<int>> res;
//             unordered_set<int> st;
//             vector<int> temp;
//             backtrack(nums,temp,st,res);
//             return res;
//         }
// };
void solve(){
   int n;
   cin>>n;
   vector<int> nums(n);
   for(auto &it : nums)cin>>it;
    Solution obj;
    vector<vector<int>> res = obj.permute(nums);
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