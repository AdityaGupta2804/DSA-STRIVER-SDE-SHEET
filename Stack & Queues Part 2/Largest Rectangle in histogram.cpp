/* 
    author: Aditya Gupta 
    created: 21.06.2025 00:55:41
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
    vector<int> NextSmallerToLeft(vector<int>& heights){
        int n = heights.size(), pseudoIdx  = -1;
        vector<int> left;
        stack<pair<int,int>> s; //NSL & idx
        for(int i=0;i<n;i++){
            if(s.empty()){
                left.push_back(pseudoIdx);
            }else if(!s.empty() && s.top().first < heights[i]){
                left.push_back(s.top().second);
            }else if(!s.empty() && s.top().first >= heights[i]){
                while(!s.empty() && s.top().first>=heights[i]){
                    s.pop();
                }
                if(s.empty()) left.push_back(pseudoIdx);
                else left.push_back(s.top().second);
            }
            s.push(make_pair(heights[i],i));
        }
        return left;
    }
    vector<int> NextSmallerToRight(vector<int>& heights){
        int n = heights.size(), pseudoIdx  = n;
        vector<int> right;
        stack<pair<int,int>> s; //NSR & idx
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                right.push_back(pseudoIdx);
            }else if(!s.empty() && s.top().first < heights[i]){
                right.push_back(s.top().second);
            }else if(!s.empty() && s.top().first >= heights[i]){
                while(!s.empty() && s.top().first>=heights[i]){
                    s.pop();
                }
                if(s.empty()) right.push_back(pseudoIdx);
                else right.push_back(s.top().second);
            }
            s.push(make_pair(heights[i],i));
        }
        reverse(begin(right),end(right));
        return right;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = NextSmallerToLeft(heights);
        vector<int> right = NextSmallerToRight(heights);
        int ans = -1;
        for(int i=0;i<heights.size();i++){
            // debug2((right[i]-left[i]-1),heights[i]);
            int area = ((right[i]-left[i]-1)*heights[i]);
            // debug1(area);
            ans = max(ans,area);
        }       
        return ans;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> stack;         // Stores indices of increasing bars
        heights.push_back(0);      // Sentinel to process all bars
        int result = 0;

        for(int i = 0; i < heights.size(); ++i) {
            if(stack.empty() || heights[stack.back()] <= heights[i]) {
                stack.push_back(i);  // Maintain increasing order
                continue;
            }

            int h = heights[stack.back()];
            stack.pop_back();
            int len = stack.empty() ? i : i - 1 - stack.back();  // Calculate width
            result = max(result, h * len);  // Update max area

            --i;  // Reprocess current bar
        }

        return result;
    }
};
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