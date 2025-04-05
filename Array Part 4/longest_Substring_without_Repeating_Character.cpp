/* 
    author: Aditya Gupta 
    created: 28.02.2025 17:13:12
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

int lengthOfLongestSubstring(string s) {
    int n = s.size(), longest = 0 , start = 0,current =0 ;
    unordered_map<char,int> track;
    for(int i=0;i<n;i++){
        if(track.find(s[i])!=track.end()){
            start = max(start, track[s[i]]+1);
        }
        track[s[i]] = i;
        current = (i-start+1);
        longest=max(current,longest);
        
    }
    return longest;
}
void solve(){
   string s;
   cin>>s;
   int ans = lengthOfLongestSubstring(s);
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