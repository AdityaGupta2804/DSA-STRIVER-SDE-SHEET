/* 
    Author: Aditya Gupta
    Created: 10.04.2025 00:19:13
    Cleaned & Documented Version
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
template<typename T>
void debug1(const char* varName, T value) {
    cout << varName << " = " << value << endl;
}
template<typename T1, typename T2>
void debug2(const char* var1, T1 val1, const char* var2, T2 val2) {
    cout << var1 << " = " << val1 << ", " << var2 << " = " << val2 << endl;
}
template<typename T>
void debug_vector(const char* varName, const vector<T>& vec) {
    cout << varName << " = [";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i + 1 < vec.size()) cout << ", ";
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

class SudokuSolver {
public:
    static constexpr int SIZE = 9;
    bool solutionFound = false;

    // Checks if placing digit at board[row][col] is valid
    bool isValidPlacement(int row, int col, char digit, const vector<vector<char>>& board) {
        // Check the row and column
        for (int i = 0; i < SIZE; ++i) {
            if (board[row][i] == digit || board[i][col] == digit)
                return false;
        }

        // Determine starting index of the 3x3 subgrid
        int subgridRowStart = (row / 3) * 3;
        int subgridColStart = (col / 3) * 3;

        // Check the 3x3 subgrid
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[subgridRowStart + i][subgridColStart + j] == digit)
                    return false;
            }
        }

        return true;
    }

    // Recursive backtracking function to fill the Sudoku
    void solveFrom(int row, int col, vector<vector<char>>& board) {
        if (row == SIZE) {
            solutionFound = true;
            return;
        }

        int nextRow = (col == SIZE - 1) ? row + 1 : row;
        int nextCol = (col + 1) % SIZE;

        if (board[row][col] != '.') {
            solveFrom(nextRow, nextCol, board);
            return;
        }

        for (char digit = '1'; digit <= '9'; ++digit) {
            if (isValidPlacement(row, col, digit, board)) {
                board[row][col] = digit;
                solveFrom(nextRow, nextCol, board);

                if (solutionFound) return; // Stop early if solution found
                board[row][col] = '.';     // Backtrack
            }
        }
    }

    // Entry point to start solving
    void solveSudoku(vector<vector<char>>& board) {
        solveFrom(0, 0, board);
    }
};

// Handles a single test case
void handleTestCase() {
    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n));

    for (auto& row : board) {
        for (char& cell : row) {
            cin >> cell;
        }
    }

    SudokuSolver solver;
    solver.solveSudoku(board);

    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto startTime = chrono::high_resolution_clock::now();

    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        handleTestCase();
    }

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
    cerr << "Execution Time: " << duration.count() << " ms\n";

    return 0;
}
