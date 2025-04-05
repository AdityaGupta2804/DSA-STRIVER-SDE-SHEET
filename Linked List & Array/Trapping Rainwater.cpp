/* 
    author: Aditya Gupta 
    created: 31.03.2025 14:55:17
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
static vector<int> getLeftMax(vector<int> &height){
    int n = height.size();
    vector<int> leftMax(n);
    leftMax[0] = height[0];
    for(int i=1;i<n;i++){
        leftMax[i] = max(leftMax[i-1],height[i]);
    }
    return leftMax;
}
static vector<int> getRightMax(vector<int> &height){
    int n = height.size();
    vector<int> RightMax(n);
    RightMax[n-1] = height[n-1];
    for(int i=n-2;i>=0;i--){
        RightMax[i] = max(RightMax[i+1],height[i]);
    }
    return RightMax;
}
/*Approach 1*/
// int trap(vector<int>& height) {
//     int ans = 0, n = height.size();
//     vector<int> left = getLeftMax(height);
//     vector<int> right = getRightMax(height);
//     for (int i = 0; i < n; i++) {
//         int temp = min(left[i], right[i]);
//         ans += temp - height[i];
//     }
//     return ans;
// }
/*Approach 2 with O(1) space*/
int trap(vector<int>& height) {
    int left=0,right=height.size()-1,lmax=0,rmax=0,ans=0;
    while(left<right){
        lmax = max(lmax,height[left]);
        rmax = max(rmax,height[right]);
        if(lmax<rmax){
            ans+= lmax - height[left];
            left++;
        }else{
            ans+= rmax- height[right];
            right--;
        }
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    int ans = trap(height);
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