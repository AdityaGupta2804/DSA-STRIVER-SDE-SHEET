/* 
    author: Aditya Gupta 
    created: 10.04.2025 14:46:14
*/

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
// Debug utility functions for local testing

// Debug 1 variable
template<typename T>
void debug1(const char* varName, T varValue) {
    cout << varName << " = " << varValue << endl;
}

// Debug 2 variables
template<typename T1, typename T2>
void debug2(const char* varName1, T1 varValue1, const char* varName2, T2 varValue2) {
    cout << varName1 << " = " << varValue1 << " " << varName2 << " = " << varValue2 << endl;
}

// Debug a vector
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
    vector<vector<int>> visited;
    vector<string> ans;
    void explore(vector<vector<int>> &mat, int row,int col,string path,int n){
        if(row == n-1 && col == n-1){
            ans.push_back(path);
            return;
        }
        if(mat[row][col] == 0 || visited[row][col] == 1){
            return;
        }
        visited[row][col] = 1; 
        if(row>0){
            explore(mat,row-1,col,path+'U',n);
        }
        if(col>0){
            explore(mat,row,col-1,path+'L',n);
        }
        if(row<n-1){
            explore(mat,row+1,col,path+'D',n);
        }
        if(col<n-1){
            explore(mat,row,col+1,path+'R',n);
        }
        visited[row][col] =0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        ans.clear();
        visited.assign(n,vector<int>(n,0));

        if(mat[0][0] == 0 || mat[n-1][n-1] == 0){
            return ans;
        }
        explore(mat,0,0,"",n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// Handles input, output and calls the main logic
void solve() {
    int n;
    cin >> n;

    // Read the matrix
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (auto &i : mat) {
        for (auto &j : i) {
            cin >> j;
        }
    }

    // Print matrix (for debugging)
    for (auto i : mat) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    // Create object and get all paths
    Solution obj;
    vector<string> ans = obj.findPath(mat);
    
    // Print all valid paths
    for (auto i : ans) {
        cout << i << endl;
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
