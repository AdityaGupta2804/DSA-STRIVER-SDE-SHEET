/* 
    author: Aditya Gupta 
    created: 21.06.2025 00:59:42
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
int celebrity(vector<vector<int>> & mat) {
    int n = mat.size();
    stack<int> st;

    // Push everybody in stack
    for (int i = 0; i < n; i++)
        st.push(i);

    // Find a potential celebrity
    while (st.size() > 1) {

        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        // if a knows b
        if (mat[a][b]) {
            st.push(b);
        }
        else {
            st.push(a);
        }
    }

    // Potential candidate of celebrity
    int c = st.top();
    st.pop();

    // Check if c is actually
    // a celebrity or not
    for (int i = 0; i < n; i++) {
        if(i == c) continue;

        // If any person doesn't
        // know 'c' or 'c' doesn't
        // know any person, return -1
        if (mat[c][i]|| !mat[i][c])
            return -1;
    }

    return c;
}
int celebrity(vector<vector<int>> & mat) {
    int n = mat.size();

    int i = 0, j = n - 1;
    while (i < j) {
        
        // j knows i, thus j can't be celebrity
        if (mat[j][i] == 1) 
            j--;

        // else i can't be celebrity
        else
            i++;
    }

    // i points to our celebrity candidate
    int c = i;

    // Check if c is actually
    // a celebrity or not
    for (i = 0; i < n; i++) {
        if(i == c) continue;

        // If any person doesn't
        // know 'c' or 'c' doesn't
        // know any person, return -1
        if (mat[c][i] || !mat[i][c])
            return -1;
    }

    return c;
}
void solve(){
   
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