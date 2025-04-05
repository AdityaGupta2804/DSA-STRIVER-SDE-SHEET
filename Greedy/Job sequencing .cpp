/* 
    author: Aditya Gupta 
    created: 05.04.2025 17:34:27
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

class Solution {
    public:
      vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
          // code here
          int n = profit.size();
      /*Deadline, Profit*/
      vector<pair<int,int>> jobs; 
      for(int  i=0;i<n;i++){
          jobs.push_back({deadline[i],profit[i]});
      }
      /*sorting jobs in ascending order of Deadline*/
      sort(jobs.begin(),jobs.end()); 
      /*Min heap*/
      priority_queue<int,vector<int>,greater<int>> pq;
      
      for(auto job : jobs){
          /*If the job can be scheduled within its deadline (i.e., the number of jobs scheduled so far is less than the deadline), push its profit into the heap.*/
          if(job.first > pq.size()){
              pq.push(job.second);
          }
          /*If the heap is full (equal to deadline), replace the existing lowest profit job with the current job if it has a higher profit.*/
          else if(!pq.empty() && pq.top()< job.second){
                  pq.pop();
                  pq.push(job.second);
  
          }
      }
      int count=0,bonus=0;
      while(!pq.empty()){
          bonus+=pq.top();
          pq.pop();
          count++;
      }
      return {count,bonus};
      }
};
void solve() {
    int n;
    cin >> n;

    vector<int> deadline(n), profit(n);
    for (int i = 0; i < n; i++) {
        cin >> deadline[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    Solution obj;
    vector<int> result = obj.jobSequencing(deadline, profit);

    cout << "Jobs Done: " << result[0] << ", Total Profit: " << result[1] << "\n";
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