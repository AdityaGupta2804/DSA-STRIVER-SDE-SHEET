/* 
    author: Aditya Gupta 
    created: 16.04.2025 20:13:43
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
// #define int long long

// Function to check if mid^n is equal to, less than, or greater than m
int ispossible(int mid, int n, int m) {
    long long ans = 1;

    // Try to compute mid^n step by step
    for (int i = 1; i <= n; i++) {
        ans *= mid;

        // If at any point, the result exceeds m, break early
        if (ans > m) return 2;  // Too large
    }

    // Check if we exactly reached m
    if (ans == m) return 1;     // Perfect match
    return 0;                   // Too small
}

// Function to find the integer Nth root of m
int NthRoot(int n, int m) {
    int low = 1;
    int high = m;
    int ans = -1; // Default if no such integer root exists

    // Binary Search between 1 and m
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check whether mid^n == m, < m, or > m
        int check = ispossible(mid, n, m);

        if (check == 1) {
            // Found the exact nth root
            ans = mid;
            break;
        } 
        else if (check == 2) {
            // mid^n is too large, move to smaller values
            high = mid - 1;
        } 
        else {
            // mid^n is too small, try larger values
            low = mid + 1;
        }
    }

    return ans;
}
void solve(){
   int n,m;
   cin>>n>>m;
   int ans = NthRoot(n,m);
   cout<<ans<<endl;
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
