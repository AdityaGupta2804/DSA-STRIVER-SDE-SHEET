/* 
    author: Aditya Gupta 
    created: 05.02.2025 14:58:27
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    bool firstRow = false , firstCol = false;
    /*Check if first column of any row is 0 or not */
    for(int i=0;i<n;i++){
        if(matrix[i][0] == 0){
            firstCol =  true;
        }
    }
    /*Check if first row of any column is 0 or not */
    for(int j=0;j<m;j++){
        if(matrix[0][j] == 0){
            firstRow =  true;
        }
    }
    /*mark the 0th row and 0th column of  each i and j if i,j==0*/
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    /*Based on Marking make Row and Column Zero*/
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if( matrix[i][0] == 0 || matrix[0][j] == 0 ){
                matrix[i][j]=0;
            }
        }
    }
    /*Now handle all the Rows where first column is zero */
    if(firstRow){
        for(int j=0;j<m;j++){
            matrix[0][j]=0;
        }
    }

    /*Now handle all the Column  where first row is zero */

    if(firstCol){
        for(int i = 0;i<n;i++){
            matrix[i][0] = 0;
        }
    }
    return;
}
void solve(){
   int n,m;
   cin>>n>>m; 
   vector<vector<int>> matrix(n,vector<int>(m));
   for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
   }
   setZeroes(matrix);
   for(auto row : matrix){
        for(auto column : row){
            cout<<column<<" ";
        }
        cout<<endl;
   }
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