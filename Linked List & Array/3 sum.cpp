/* 
    author: Aditya Gupta 
    created: 05.04.2025 17:27:14
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
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> res;
            sort(nums.begin(), nums.end());
    
            for (int i = 0; i < nums.size(); i++) {
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
    
                int j = i + 1;
                int k = nums.size() - 1;
    
                while (j < k) {
                    int total = nums[i] + nums[j] + nums[k];
    
                    if (total > 0) {
                        k--;
                    } else if (total < 0) {
                        j++;
                    } else {
                        res.push_back({nums[i], nums[j], nums[k]});
                        j++;
    
                        while (nums[j] == nums[j - 1] && j < k) {
                            j++;
                        }
                    }
                }
            }
            return res;
        }
};
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    Solution sol;
    vector<vector<int>> result = sol.threeSum(nums);

    if (result.empty()) {
        cout << "No triplets found.\n";
        return;
    }

    cout << "Triplets with sum 0:\n";
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "\n";
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