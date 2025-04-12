/* 
    author: Aditya Gupta 
    created: 11.04.2025 19:26:00
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
    
        // Function to check if we can assign color 'i' to 'node'
        bool ispossible(int i, int node, int v, vector<vector<int>> adj, vector<int>& color) {
            // Traverse all adjacent vertices of current node
            for (int j = 0; j < adj[node].size(); j++) {
                int temp = adj[node][j];
                // If adjacent node already has the same color, return false
                if (color[temp] == i) {
                    return false; // Conflict detected
                }
            }
            return true; // Safe to assign color
        }
    
        // Backtracking function to try all color assignments
        bool assignColor(int v, vector<vector<int>> adj, int m, int node, vector<int>& color) {
            // Base case: all vertices have been assigned a color
            if (node == v) {
                return true;
            }
    
            // Try all colors from 0 to m-1
            for (int i = 0; i < m; i++) {
                // Check if this color can be assigned to this node
                if (ispossible(i, node, v, adj, color)) {
                    color[node] = i; // Assign the color
                    // Recur for next node
                    if (assignColor(v, adj, m, node + 1, color) == true) {
                        return true; // Found a valid coloring
                    }
                    // Backtrack if it leads to no solution
                    color[node] = -1; // Undo the assignment
                }
            }
    
            // If no color could be assigned to this node, return false
            return false;
        }
    
        // Main function to setup adjacency list and call coloring function
        bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
            // Initialize color assignment for all vertices to -1 (unassigned)
            vector<int> color(v, -1);
            
            // Create adjacency list
            vector<vector<int>> adj(v);
            for (auto i : edges) {
                adj[i.first].push_back(i.second);
                adj[i.second].push_back(i.first); // Undirected graph
            }
    
            // Start coloring from node 0
            return assignColor(v, adj, m, 0, color);
        }
    };
    

void solve(){
   int v,m,n;
   cin>>v; /*no of vertices*/
   cin>>n; /*no of edges*/
   vector<pair<int,int>> edges(n);
   for(auto &i : edges){
        cin>>i.first>>i.second;
   }
   cin>>m; /*no of color*/
   Solution obj;
   bool ans = obj.graphColoring(v,edges,m);
   cout<<((ans) ? "True" : "False")<<endl;
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