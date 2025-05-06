/* 
    author: Aditya Gupta 
    created: 19.04.2025 14:35:01
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



/*Main logic- : 

1.   Find the intial mid
2. with the help of mid find which half of array is sorted 
3. then make other binary searches call in the accordingly

*/

class Solution {
    public:

        int search(vector<int>& nums, int target) {
            int low = 0, high = nums.size()-1 , res = -1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid] == target){
                    return mid;
                }
                /*Left half is sorted*/
                if(nums[low]<=nums[mid]){
                    if(nums[low]<=target && target<nums[mid]){
                        high = mid-1;
                    }else{
                        low = mid+1;
                    }
                }else{ /*If right half is sorted*/
                    if(nums[mid]<target && target<=nums[high]){
                        low= mid+1;
                    }else{
                        high = mid-1;
                    }
                }
            }
            return res;
        }
    };
void solve(){
   int n,target;
   cin>>n>>target;
   vector<int> nums(n);
   for(auto &it : nums)cin>>it;
   Solution obj;
   int result  = obj.search(nums,target);
   cout<<result<<endl;
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