/* 
    author: Aditya Gupta 
    created: 16.02.2025 22:15:26
*/
/*
    main crux-: observe the sample test case:
    every time k element getting inserted at front 
    so first reverse entire array so all k element are in front now
    but they are in reverse order so reverse first k element
    but now the last n-k will still we reverse orderd, so reverse them 
    
*/
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums , int k){
    k = k % nums.size();
    reverse(nums.begin(),nums.end());
    reverse(nums.begin()+k,nums.end());
    reverse(nums.begin(),nums.begin()+k);

}
void solve(){
   int n,k;
   cin>>n>>k;
   vector<int> nums(n);
   for(auto &it : nums){
       cin>>it;
   }
   rotate(nums,k);
   for(auto it: nums){
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