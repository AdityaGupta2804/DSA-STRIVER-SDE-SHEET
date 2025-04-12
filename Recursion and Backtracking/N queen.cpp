/* 
    author: Aditya Gupta 
    created: 09.04.2025 14:09:23
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
/*
    Main Solution

    By-: 
Poorva Wadhwa -: 220651
 
Ketki Gupta -: 220597
 
Kasak -: 220591
 
Minal Gupta -: 22063
 
Ishita Shekhawat -: 220575
*/
class Solution {
    public:
        // Function to check if it's safe to place a queen at (row, col)
        bool isvalid(int row, int col, vector<string> &board) {
            int n = board.size();

            // Check for queen in the same column above the current row
            for (int i = 0; i < row; i++) {
                if (board[i][col] == 'Q') return false;
            }

            // Check upper-left diagonal
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                if (board[i][j] == 'Q') return false;
            }

            // Check upper-right diagonal
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
                if (board[i][j] == 'Q') return false;
            }

            // Safe to place the queen
            return true;
        }

        // Recursive backtracking function to try placing queens row by row
        void backtrack(int row, vector<string> &board, vector<vector<string>> &ans, int n) {
            // All queens are placed successfully
            if (row == n) {
                ans.push_back(board);
                return;
            }

            // Try placing a queen in every column of the current row
            for (int col = 0; col < n; col++) {
                if (isvalid(row, col, board)) {
                    board[row][col] = 'Q';               // Place the queen
                    backtrack(row + 1, board, ans, n);   // Recurse to next row
                    board[row][col] = '.';               // Backtrack and remove queen
                }
            }
        }

        // Main function to solve N-Queens problem and return all valid boards
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> ans;                  // To store all valid solutions
            vector<string> board(n, string(n, '.'));     // Initialize empty board
            backtrack(0, board, ans, n);                 // Start placing queens from row 0
            return ans;
        }
};

/*
    Driver Code
*/
void solve(){
    
    int n;
    cin>>n;
    // debug1(n);
    Solution obj;
    vector<vector<string>> res = obj.solveNQueens(n);
    cout<<res.size()<<endl;
    for(auto i:res){
        for(auto j: i){
            cout<<j<<endl;
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