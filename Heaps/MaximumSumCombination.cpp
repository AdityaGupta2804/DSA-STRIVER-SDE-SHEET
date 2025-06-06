/* 
    author: Aditya Gupta 
    created: 21.05.2025 23:00:19
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
      vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> st;
        pq.push(make_pair(A[N-1]+B[N-1],make_pair(N-1,N-1)));
        st.insert(make_pair(N-1,N-1));
        vector<int> ans;
        for(int i=0;i<K;i++){
            auto temp = pq.top();
            pq.pop();
            int sum = temp.first;
            auto index = temp.second;
            ans.push_back(sum);

            int l = index.first;
            int r = index.second;

            if(l-1>=0){
                int total =  A[l-1]+B[r];
                auto temp1 = make_pair(l-1,r);
                if(st.find(temp1) == st.end()){
                    pq.push(make_pair(total,temp1));
                    st.insert(temp1);
                }
            }
            if(r-1>=0){
                int total =  A[l]+B[r-1];
                auto temp1 = make_pair(l,r-1);
                if(st.find(temp1) == st.end()){
                    pq.push(make_pair(total,temp1));
                    st.insert(temp1);
                }
            }
        }
        return ans;
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