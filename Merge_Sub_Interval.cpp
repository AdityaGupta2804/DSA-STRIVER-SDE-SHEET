/* 
    author: Aditya Gupta 
    created: 10.02.2025 18:29:57
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(),intervals.end());
    int i=1,start=intervals[0][0], end = intervals[0][1];
    while(i<intervals.size()){
        if(end>=intervals[i][0]){
            end  =  (intervals[i][1] > end)  ? intervals[i][1] : end;
            i++;
        }else{
            res.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
            i++;
        }
    }
    res.push_back({start,end});
    return res;  
}  
void solve(){
   int n;
   cin>>n;
   vector<vector<int>> intervals(n,vector<int>(2)),res;
   for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>intervals[i][j];
        }
   }
   res = merge(intervals);
   for(auto it : res){
        cout<<"["<<it[0]<<" , "<<it[1]<<" ],";
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