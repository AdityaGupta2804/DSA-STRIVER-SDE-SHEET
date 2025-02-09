/* 
    author: Aditya Gupta 
    created: 09.02.2025 13:46:07
*/

#include <bits/stdc++.h>
using namespace std;

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
void solve(){
   int n;
   cin>>n;
   
   vector<int> nums(n);
   
   for(auto &it : nums) cin>>it;
   
   int res = maxSubArray(nums);
   
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