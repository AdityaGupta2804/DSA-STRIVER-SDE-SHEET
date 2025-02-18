/* 
    author: Aditya Gupta 
    created: 18.02.2025 15:08:00
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
/*Main sol - : applying Binary search on the matrix, by treating the matrix as a array of integers*/
/*Main problem -: how to find the index of any number*/
/*solution -: (0 based) Row = (x)/n and Column = (x)%n where n is the column no and x is the main element */
bool searchMatrix(vector<vector<int>>& matrix, int target) { 
    int m = matrix.size();
    int n = matrix[0].size();
    int left=0,right=n*m-1;
    while(left<=right){
        int mid = left+(right-left)/2;
        int row = (mid) / n, col = (mid) % n;
        int element =  matrix[row][col];
        if(element == target){
            return true;
        }else if(element<target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return false;   
}
void solve(){
   int m,n,target;
   cin>>m>>n;
   cin>>target;
   vector<vector<int>> matrix(m,vector<int> (n,-1));
   for(auto &i : matrix){
        for(auto &j : i){
            cin>>j;
        }
   } 
   bool ans = searchMatrix(matrix,target);
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