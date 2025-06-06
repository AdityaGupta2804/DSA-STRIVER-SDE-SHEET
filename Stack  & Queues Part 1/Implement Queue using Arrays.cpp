/* 
    author: Aditya Gupta 
    created: 21.05.2025 23:30:37
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
class Queue{
    int *arr;
    int start, end,currsize,maxsize;
    public:
    Queue(){
        arr = new int[16];
        start =-1;
        end = -1;
        currsize = 0; 
    }
    Queue(int maxsize)
    {
        (* this).maxsize = maxsize;
        arr = new int[maxsize];
        start =-1;
        end = -1;
        currsize = 0;
    }
    void push(int element){
        if(currsize == maxsize){
            cout<<"Queue is full \n"<<endl;
            exit(-1);
        }
        if(end ==-1){
            start = 0;
            end = 0;
        }else{
            end = (end+1)%maxsize;
        }
        arr[end] = element;
        currsize++;
    }
    void pop(){
        if(start==-1){
            cout<<"queue is empty\n"<<endl;
            exit(0);
        }
        
        if(currsize == 1){
            start=-1;
            end = -1;
        }else{
            start = (start+1)%maxsize;
        }
        currsize--;

    }
    int top(){
        if(start==-1){
            cout<<"queue is empty\n"<<endl;
            exit(0);
        }
        return arr[start];
    }
    int size(){
        return currsize;
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