/* 
    author: Aditya Gupta 
    created: 06.04.2025 19:03:30
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
        bool isPalindrome(const string& x) {
            for (int i = 0, j = x.length() - 1; i < j; i++, j--) {
                if (x[i] != x[j]) return false;
            }
            return true;
        }
    
        void generatePartition(string s,int idx , vector<string> &curr,vector<vector<string>> &ans){
            int n = s.length();
            if(idx == n){
                ans.push_back(curr);
                return;
            }
            /*Partion from idx to i (idx initially is 0)*/
            for(int i=idx;i<n;i++){
                /*Get substring from idx to i*/
                string temp = s.substr(idx, i - idx + 1);
                /*is left partition is pallidrome ,push in curr*/
                if(isPalindrome(temp)){
                    curr.push_back(temp);
                    /*check for right part*/
                    generatePartition(s,i+1,curr,ans);
                    /*pop because later we need greater left partion */
                    curr.pop_back();
                }
            }
        }
        vector<vector<string>> partition(string s) {
            vector<vector<string>> ans;
            vector<string> curr;
            generatePartition(s,0,curr,ans);
            return ans;
        }
};
void solve(){
   string s;
   cin>>s;
   Solution obj;
   vector<vector<string>> res = obj.partition(s);
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