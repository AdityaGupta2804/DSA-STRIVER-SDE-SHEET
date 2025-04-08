/* 
    author: Aditya Gupta 
    created: 07.04.2025 01:56:24
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
    string getPermutation(int n, int k) {
        int fact = 1;                  // fact will store (n-1)!
        vector<int> digit;            // to store the available digits
    
        // Precompute (n-1)! and fill the digit vector with 1 to n
        for(int i = 1; i < n; i++) {
            fact *= i;                // calculating factorial of (n-1)
            digit.push_back(i);       // storing digits from 1 to n-1
        }
        digit.push_back(n);           // adding the last digit n
    
        string ans = "";              // to build the resulting permutation
        k = k - 1;                    // converting to 0-based indexing
    
        // Generate each digit of the permutation
        while(true) {
            // Pick the index of the current digit using k/fact
            ans += to_string(digit[k / fact]);
    
            // Remove the used digit from the vector
            digit.erase(digit.begin() + k / fact);
    
            // If no digits are left, we are done
            if(digit.size() == 0) {
                break;
            }
    
            // Update k for the next position
            k = k % fact;
    
            // Update fact to be factorial of (remaining - 1) digits
            fact = fact / digit.size();
        }
    
        return ans;
    }    
};
void solve(){
    int n,k;
    cin>>n>>k;
    Solution obj;
    string res = obj.getPermutation(n,k);
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