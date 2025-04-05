/*  
    Author: Aditya Gupta  
    Created: 19.02.2025 23:40:15  

    Problem: Counting Reverse Pairs in an Array
    - A reverse pair is defined as (i, j) where i < j and nums[i] > 2 * nums[j].
    - The naive O(N^2) approach is too slow for large inputs.
    - We use a **modified merge sort** to efficiently count reverse pairs in O(N log N).

    Approach:
    1. **Divide** the array into two halves using merge sort.
    2. **Count** the reverse pairs across the left and right halves before merging.
    3. **Merge** the sorted halves while maintaining the correct order.
*/

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
// Debugging Macros (Only active in local environment)
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

// Function to count reverse pairs during merging two sorted halves
int merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
    int count = 0; // Stores the number of reverse pairs
    int i = left, j = mid + 1;

    // Count reverse pairs before merging
    while (i <= mid && j <= right) {
        if (nums[i] > 2 * nums[j]) {
            count += (mid - i + 1); // All elements from nums[i] to nums[mid] form reverse pairs with nums[j]
            j++;
        } else {
            i++;
        }
    }

    // Standard merge step
    i = left, j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];

    // Copy sorted elements back to original array
    for (int p = left; p <= right; p++) {
        nums[p] = temp[p];
    }
    return count;
}

// Recursive merge sort function that counts reverse pairs
int mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    int count = 0;
    
    // Count in left half, right half, and across both halves
    count += mergeSort(nums, temp, left, mid);
    count += mergeSort(nums, temp, mid + 1, right);
    count += merge(nums, temp, left, mid, right);

    return count;
}

// Wrapper function to count reverse pairs in the given array
int reversePairs(vector<int>& nums) {
    vector<int> temp(nums.size());
    return mergeSort(nums, temp, 0, nums.size() - 1);
}

// Function to take input, call reversePairs, and print result
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto& it : nums) {
        cin >> it;
    }
    int res = reversePairs(nums);
    cout << res << endl;
}

// Main function with execution time measurement
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
    cerr << "Execution Time: " << duration.count() << " ms" << endl;
    
    return 0;
}
