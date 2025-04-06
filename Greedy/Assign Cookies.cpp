/* 
    author: Aditya Gupta 
    created: 06.04.2025 13:06:15
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
        int findContentChildren(vector<int>& g, vector<int>& s) {
            int n = g.size(), m = s.size();
            sort(g.begin(),g.end());
            sort(s.begin(),s.end());
            int count = 0, i=0,j=0;
            while(i<n && j<m){
                if(s[j]>=g[i]){
                    count++;
                    i++;
                }
                j++;
            }
            return count;
        }
};
void solve(){
   int n,m;
   cin>>n>>m;
   vector<int> g(n),s(m);
   for(auto &i : g )cin>>i;
   for(auto &i : s )cin>>i;
   Solution obj;
   int ans = obj.findContentChildren(g,s);
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