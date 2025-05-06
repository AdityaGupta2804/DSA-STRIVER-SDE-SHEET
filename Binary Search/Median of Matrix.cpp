/* 
    author: Aditya Gupta 
    created: 12.04.2025 18:08:10
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

/*Brute Force*/
// int median(vector<vector<int>> &matrix, int m, int n) {
//     vector<int> arr;
//     for(auto i:matrix){
//         for(auto j:i){
//             arr.push_back(j);
//         }
//     }
//     sort(arr.begin(),arr.end());
//     debug_vector(arr);
//     return arr[(arr.size())/2];
// }

/*Optimal Binary Search Approach */
int median(vector<vector<int>> &matrix, int m, int n) {
    /*finding the min range and max range*/

    int minimum = matrix[0][0],maximum = matrix[0][n-1];
    for(int i = 0;i<m;i++){
        minimum = min(minimum,matrix[i][0]);
        maximum = max(maximum,matrix[i][n-1]);
    }
    /*No of elements which should be less than median = check */
    int check = ((m*n)+1)/2;
    while(minimum<=maximum){
        int mid = minimum + (maximum-minimum)/2;
        /*count of elements less than this particular mid*/
        int count = 0;
        for(int i=0;i<m;i++){
            /*Counts no of elements less than the mid */
            int find = upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
            /*add in count*/
            count += find;
        }
        /*mid is smaller since count still didnt reach check */
        if(count<check){
            minimum = mid+1;
        }else{
            /*mid is greater since count is bigger than check */
            maximum = mid-1;
        }
    }
    return minimum;
}
void solve(){
   int m,n;
   cin>>m>>n;
   vector<vector<int>> matrix (m,vector<int>(n,0));
   /*Input*/
   for(auto &i : matrix){
    for(auto &j: i){
        cin>>j;
    }
   }
//    /*Ouput matrix*/
//    for(auto i : matrix){
//     for(auto j: i){
//         cout<<j<<" ";
//     }
//     cout<<endl;
//    }
   int ans  = median(matrix,m,n);
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