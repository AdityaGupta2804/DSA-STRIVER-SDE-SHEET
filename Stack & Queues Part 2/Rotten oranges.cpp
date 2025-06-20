/* 
    author: Aditya Gupta 
    created: 21.06.2025 00:57:46
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
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size(),total = 0, days = 0 , count = 0;
        queue<pair<int,int>> q;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    total++; /*total oranges(rotten + fresh*/
                    if(grid[i][j]==2){
                        q.push(make_pair(i,j));
                    }
                }
            }
        }
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        while(!q.empty()){
            int k = q.size();
            count+=k;
            while(k--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x + dx[i], ny = y+dy[i];
                    if(nx<0||ny<0||nx>=m||ny>=n||grid[nx][ny]!=1)continue;
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty()) days++;
        }
        return (total == count ) ? days : -1;
    }
};
void solve(){
   
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