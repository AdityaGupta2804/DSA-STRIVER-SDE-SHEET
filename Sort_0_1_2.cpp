#include<bits/stdc++.h>
using namespace std;

/*Dutch National Flag Algorithm*/
void sortColors(vector<int>& nums) {
    int left = 0, mid = 0, right = nums.size()-1;  
    while(mid<=right){
        if(nums[mid]==0){
            swap(nums[left],nums[mid]);
            left++;
            mid++;
        }else if(nums[mid]==1){
            mid++;
        }else{
            swap(nums[right],nums[mid]);
            right--;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &it : nums)cin>>it;

    sortColors(nums);
    
    for(auto i : nums){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}