/* 
    author: Aditya Gupta 
    created: 06.05.2025 14:21:30
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
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
        {
            int m = nums1.size(),n = nums2.size();
            int size = m+n,idx2 = size/2 ,idx1 = idx2-1, ele1  = -1, ele2 =-1;
            int i=0, j=0,k=0;

            while(i<m && j<n){
                if(nums1[i]< nums2[j]){
                    if(k==idx1){
                        ele1 = nums1[i];
                    }
                    if(k==idx2){
                        ele2 = nums1[i];
                    }
                    i++;
                }else{
                    if(k==idx1){
                        ele1 = nums2[j];
                    }
                    if(k==idx2){
                        ele2 = nums2[j];
                    }
                    j++;
                }
                k++;
            }
            while(i<m){
                if(k==idx1){
                    ele1 = nums1[i];
                }
                if(k==idx2){
                    ele2 = nums1[i];
                }
                i++;
                k++;
            }
            while(j<n){
                if(k==idx1){
                    ele1 = nums2[j];
                }
                if(k==idx2){
                    ele2 = nums2[j];
                }
                j++;
                k++;
            }
            if(size&1){
                return double(ele2);
            }
            return (double)((double)(ele1+ele2))/2.0;

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