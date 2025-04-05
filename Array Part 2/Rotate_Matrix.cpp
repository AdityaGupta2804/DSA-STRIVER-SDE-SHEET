/* 
    author: Aditya Gupta 
    created: 10.02.2025 16:21:32
*/

/*
The CRUX of the problem is that we need to take transpose of matrix
then swap the columns of matrix
optimal solution -
space complexity  - O(1);
time Complexity - : O(N);
*/

#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>>& matrix) {
    int i=0,j=0,n=matrix.size();
    while((i < n) && (j < n)){
        int start=i,end=j;
        while((start<n) && (end<n)){
            swap(matrix[i][start],matrix[end][j]);
            start++,end++;
        }
        i++,j++;
    }
}
void swap_column(vector<vector<int>> &matrix){
    int n = matrix.size(),i=0;
    while(i<n){
        int start=0,end=n-1;
        while(start<=end){
            swap(matrix[i][start],matrix[i][end]);
            start++,end--;
        }
        i++;
    }
}
void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    swap_column(matrix);
    
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix (n,vector<int>(m));
    for(auto &row: matrix){
        for(auto &col:row){
            cin>>col;
        }
    }
    transpose(matrix);
    swap_column(matrix);
    for(auto &row: matrix){
        for(auto &col:row){
            cout<<col<<" ";
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