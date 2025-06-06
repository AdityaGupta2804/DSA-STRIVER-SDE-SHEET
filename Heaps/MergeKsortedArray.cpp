/* 
    author: Aditya Gupta 
    created: 17.05.2025 13:17:49
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
class Solution{
public:
    /* ppi- 1. Value of the element(ele)
            2. pair -> 1. index of array(temp) in the arr from which ele is taken.
                2. index of ele in the its array 

    */
    typedef pair<int,pair<int,int>> ppi;
   vector<int> MergeKSortedArray(vector<vector<int>> & arr){
        int  k = arr.size();  //total no of sorted arrays
        //Min heap
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        /*Insert the first element of every sorted array into priority queue along with the index of array it belongs to , and also the index of the element in its array*/

        for(int i=0;i<k;i++){
            int ele = arr[i][0];
            pq.push(make_pair(ele,make_pair(i,0)));
        }
        vector<int> sortedArray;
        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();
            int ele = i.first;
            sortedArray.push_back(ele);

            auto p = i.second;
            int idx_ele_arr =  p.first;
            int idx_ele =  p.second;

            if((idx_ele+1) < (arr[idx_ele_arr].size())){
                int next_ele = arr[idx_ele_arr][idx_ele+1];
                pq.push(make_pair(next_ele,make_pair(idx_ele_arr,idx_ele+1)));
            }
        }
        return sortedArray;
   }
};

/*Driver Code*/
void solve(){
   int k;
   cin>>k;
   vector<vector<int>> arr(k);
   for(int i=0;i<k;i++){
        int m;
        cin>>m;
        vector<int> temp;
        for(int j=0;j<m;j++){
            int ele;
            cin>>ele;
            temp.push_back(ele);
        }
        arr[i] = temp;
   }
   Solution obj;
   vector<int> sortedArray = obj.MergeKSortedArray(arr);
   for(auto  i: sortedArray){
        cout<<i<<" ";
   }
   cout<<endl;
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