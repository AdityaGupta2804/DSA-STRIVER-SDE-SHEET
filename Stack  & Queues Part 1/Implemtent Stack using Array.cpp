/* 
    author: Aditya Gupta 
    created: 21.05.2025 23:02:28
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
class Stack {
private:
    vector<int> arr;  // now private, cannot access directly from outside

public:
    void push(int element) {
        arr.push_back(element);
    }

    void pop() {
        if (!arr.empty())
            arr.pop_back();
        else
            cout << "Stack is empty! Cannot pop.\n";
    }

    int sizeofstack() {
        return arr.size();
    }

    int top() {
        if (!arr.empty())
            return arr.back();
        else {
            cout << "Stack is empty! Returning -1\n";
            return -1;
        }
    }

    bool isEmpty() {
        return arr.empty();
    }
};

void solve(){
   int n;
   cin>>n;
   Stack st;
   st.push(10);
   st.push(50);
   st.push(140);
   st.push(30);
   st.pop();
   st.pop();
   cout<<st.sizeofstack()<<endl;
   st.pop();
   st.push(1000);
   st.push(90);
   cout<<st.top()<<endl;
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