/* 
    author: Aditya Gupta 
    created: 09.02.2025 13:46:07
*/

#include <bits/stdc++.h>
using namespace std;
/*Approach 1*/
int maxSubArray(vector<int>& nums) {
    int n = nums.size() , curr = nums[0] , max_sum=nums[0];
    
    for(int i=1;i<n;i++){
        /*Extend the previous subarray or start new from this element*/
        curr = max(nums[i],curr+nums[i]);
        /*take maximum of subarray */
        max_sum =  max(max_sum,curr);
    }
    return max_sum;
}
/*Approach 2 */
int maxSubarray2(vector<int> &nums){
    vector<int> pref = nums;
    for(int i=1;i<pref.size();i++){
        pref[i] += max(0,pref[i-1]);
    }
    return *max_element(pref.begin(),pref.end());
}
/*Appoach 3*/
int Divide_conquer(vector<int>& A, int L, int R) {
    if (L > R) return INT_MIN;  // Base case
    if (L == R) return A[L];    // If single element, return it

    int mid = (L + R) / 2, leftSum = 0, rightSum = 0;

    // leftSum = max subarray sum in [L, mid-1] and starting from mid-1
    for (int i = mid - 1, curSum = 0; i >= L; i--) {
        curSum += A[i];
        leftSum = max(leftSum, curSum);
    }

    // rightSum = max subarray sum in [mid+1, R] and starting from mid+1
    for (int i = mid + 1, curSum = 0; i <= R; i++) {
        curSum += A[i];
        rightSum = max(rightSum, curSum);
    }

    // Return the maximum of three cases:
    // 1. Maximum subarray sum in the left half
    // 2. Maximum subarray sum in the right half
    // 3. Maximum subarray sum crossing the middle
    return max({Divide_conquer(A, L, mid - 1), Divide_conquer(A, mid + 1, R), leftSum + A[mid] + rightSum});
}

int maxSubarray3(vector<int> &nums) {
    return Divide_conquer(nums, 0, nums.size() - 1);
}

void solve(){
   int n;
   cin>>n;
   
   vector<int> nums(n);
   
   for(auto &it : nums) cin>>it;
   int res1 = maxSubarray2(nums);
   
   int res2 = maxSubarray2(nums);
   
   int res3 = maxSubarray3(nums);

   cout<<res1<<endl;
   cout<<res2<<endl;
   cout<<res3<<endl;

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