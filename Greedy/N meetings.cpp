/* 
    author: Aditya Gupta 
    created: 05.04.2025 17:31:55
*/

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
template<typename T>
void debug1(const char* varName, T varValue) {
    cout << varName << " = " << varValue << endl;
}
template<typename T1, typename T2>
void debug2(const char* varName1, T1 varValue1, const char* varName2, T2 varValue2) {
    cout << varName1 << " = " << varValue1 << " " << varName2 << " = " << varValue2 << endl;
}
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
    static vector<vector<int>> getIntervals(vector<int> &start, vector<int> &end){
        int n = start.size();
        vector<vector<int>> intervals(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            intervals[i][0] = start[i];
            intervals[i][1] = end[i];
        }
        return intervals;
    }

    static bool customsort(vector<int> &a, vector<int> &b){
        if (b[1] == a[1]) return a[0] < b[0];
        return a[1] < b[1];
    }

    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<vector<int>> intervals = getIntervals(start, end);
        sort(intervals.begin(), intervals.end(), customsort);

        int count = 1;
        int lastEnd = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] > lastEnd) {
                count++;
                lastEnd = intervals[i][1];
            }
        }
        return count;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> start(n), end(n);
    for (int i = 0; i < n; i++) cin >> start[i];
    for (int i = 0; i < n; i++) cin >> end[i];

    Solution sol;
    int maxCount = sol.maxMeetings(start, end);
    cout << maxCount << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) solve();

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cerr << "Execution Time: " << duration.count() << " ms" << std::endl;

    return 0;
}
