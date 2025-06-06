/* 
    Author: Aditya Gupta 
    Created: 06.06.2025 14:34:44
*/

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
template<typename T>
void debug1(const char* varName, T varValue) {
    cerr << varName << " = " << varValue << endl;
}
template<typename T1, typename T2>
void debug2(const char* varName1, T1 varValue1, const char* varName2, T2 varValue2) {
    cerr << varName1 << " = " << varValue1 << ", " << varName2 << " = " << varValue2 << endl;
}
template<typename T>
void debug_vector(const char* varName, const vector<T>& vec) {
    cerr << varName << " = [";
    for (size_t i = 0; i < vec.size(); ++i) {
        cerr << vec[i] << (i + 1 < vec.size() ? ", " : "");
    }
    cerr << "]" << endl;
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
    unordered_map<int, int> nextGreaterElementMap(const vector<int>& arr) {
        unordered_map<int, int> result;
        stack<int> st;

        for (int i = arr.size() - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            result[arr[i]] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }

        return result;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge = nextGreaterElementMap(nums2);
        vector<int> ans;
        ans.reserve(nums1.size());

        for (int num : nums1) {
            ans.push_back(nge[num]);
        }

        return ans;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    debug_vector(a);
    debug_vector(b);

    Solution sol;
    vector<int> result = sol.nextGreaterElement(a, b);

    for (int val : result) {
        cout << val << " ";
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) solve();

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cerr << "Execution Time: " << duration.count() << " ms\n";

    return 0;
}
