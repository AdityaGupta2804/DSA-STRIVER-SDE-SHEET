/* 
    author: Aditya Gupta 
    created: 13.02.2025 16:55:39
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





vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}



vector<int> repeatedNumber(const vector<int> &A) {
    long long xr = 0;
    int n = A.size();
    
    // Step 1: XOR all array elements and numbers from 1 to N
    for (int i = 0; i < n; i++) {
        xr ^= A[i];  // XOR elements of array
        xr ^= (i + 1); // XOR numbers 1 to N
    }

    // Step 2: Find the rightmost set bit
    int rightmost_set_bit = (xr & ~(xr - 1));

    // Step 3: Divide into two groups and XOR separately
    int zero = 0, one = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] & rightmost_set_bit)
            one ^= A[i];
        else
            zero ^= A[i];
        
        if ((i + 1) & rightmost_set_bit)
            one ^= (i + 1);
        else
            zero ^= (i + 1);
    }

    // Step 4: Identify missing and repeating numbers
    int duplicate, missing;
    for (int i = 0; i < n; i++) {
        if (A[i] == zero) {
            duplicate = zero;
            missing = one;
            break;
        } else if (A[i] == one) {
            duplicate = one;
            missing = zero;
            break;
        }
    }

    return {duplicate, missing};
}


void solve(){
   int n;
   cin>>n;
   vector<int> nums(n);
   for(auto &it: nums)cin>>it;
   vector<int> res = repeatedNumber(nums);
   
    for(auto it: res){
        cout<<it<<" ";
    }
    cout<<endl;
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