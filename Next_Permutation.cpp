#include<bits/stdc++.h>
using namespace std;
void nextPermuation(vector<int> &nums){
    int n = nums.size(),i = n-2 ; /*length of array*/
    /*Finding break point */
    while(i>=0 && (nums[i]>=nums[i+1])){
        i--;
    }

    if(i>=0){   
        int j = n-1;
        /*Smallest element larger than nums[i]*/
        while(nums[j]<=nums[i]){
            j--;
        }
        swap(nums[i],nums[j]);
    }
    /*reverse subarray of right side of i */
    reverse(nums.begin()+i+1,nums.end());
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    nextPermuation(nums);
    
    for(auto ele : nums ){
        cout<<ele<<" ";
    }
    cout<<endl;
} 