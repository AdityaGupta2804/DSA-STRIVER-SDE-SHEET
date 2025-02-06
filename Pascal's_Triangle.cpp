/* 
    author: Aditya Gupta 
    created: 06.02.2025 23:13:18
*/
/*
 Visualization 
 1
 1 1
 1 2 1
 1 3 3 1
 1 4 6 4 1d

*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows) {
    int n = numRows;
    vector<vector<int>> pascal;
    vector<int> previous;
    for(int i=0;i<n;i++){
            vector<int> current(i+1,1);
            for(int j=1;j<i;j++){
                current[j] = previous[j-1] + previous[j];
            }
            pascal.push_back(current);
            previous = current;
    }
    return pascal;    
}
void solve(){
   int n;
   cin>>n;
   vector<vector<int>> output = generate(n);
   for(auto i:output){
        for(auto j: i){
            cout<<j<<" ";
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