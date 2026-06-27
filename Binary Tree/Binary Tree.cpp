/* 
    author: Aditya Gupta 
    created: 18.07.2025 14:10:06
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
/* Starting template of binary tree*/
class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
        val = 0;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int x): val(x),left(nullptr),right(nullptr) {};
    TreeNode(int x,TreeNode *left, TreeNode*right): val(x),left(left),right(right) {};
    int getValue(){
        return val;
    }
    void setValue(int newVal){
        val = newVal;
    }
};
class Binary_Tree
{
private:
    TreeNode* root;
public:
    Binary_Tree(){
        root = nullptr;
    };
    TreeNode * getRoot(){
        return root;
    }
    void setRoot(TreeNode *newRoot){
        root = newRoot;
    }
    void createBinaryTree() {
        createhelper(root);
    }
    void createhelper(TreeNode* &node){
        int val;
        cout << "Enter value (-1 for NULL): ";
        cin >> val;

        if (val == -1) {
            node = nullptr;
            return;
        }

        node = new TreeNode(val);
        cout << "Enter left child of " << val << ":\n";
        createhelper(node->left);

        cout << "Enter right child of " << val << ":\n";
        createhelper(node->right);
    }
    void destroy(TreeNode* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
    /*Inorder Traversal*/
    void inorderTraversal(TreeNode* node){
        if(node == nullptr) return;
        inorderTraversal(node->left);
        cout<<node->val<< " ";
        inorderTraversal(node->right);
    }
    void printinorder(){
        inorderTraversal(root);
    }
    /*Preorder Traversal*/

    void preorderTraversal(TreeNode* node){
        if(node == nullptr) return;
        cout<<node->val<< " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
    void printpreorder(){
        preorderTraversal(root);
    }
    /*Postrder Traversal*/

    void postorderTraversal(TreeNode* node){
        if(node == nullptr) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout<<node->val<< " ";

    }
    void printpostorder(){
        postorderTraversal(root);
    }
    void printlevelorder(TreeNode* node){
        if(node == nullptr) return;
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty()){
            TreeNode* node = q.front(); 
            q.pop();
            cout<<node->val<< " ";
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    int height(TreeNode* node) {
        if (node == nullptr) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    ~Binary_Tree(){
        destroy(root);
    };

    void MorrisInorder(TreeNode *node, bool print = false){
        vector<int> result = {};
        if(node == nullptr) return;
        TreeNode* curr = node;
        while(curr!= NULL){
            if(!curr->left){
                result.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* leftchild = curr->left;
                while (leftchild->right!=nullptr && leftchild->right != curr)
                {
                    leftchild = leftchild->right;
                }
                if(leftchild->right == nullptr){
                    leftchild->right = curr; //make the thread first time
                    curr = curr->left;
                }else{
                    leftchild->right = nullptr; // Thread exists => this is second time
                    result.push_back(curr->val);    //visit the node
                    curr= curr->right;
                }
            }
        }
        if(print == true){
            for(auto i: result){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    void MorrisPreorder(TreeNode *node, bool print = false){
        vector<int> result = {};
        if(node == nullptr) return;
        TreeNode* curr = node;
        while(curr!= NULL){
            if(!curr->left){
                result.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* leftchild = curr->left;
                while (leftchild->right!=nullptr && leftchild->right != curr)
                {
                    leftchild = leftchild->right;
                }
                if(leftchild->right == nullptr){
                    result.push_back(curr->val); // visit before threading 
                    leftchild->right = curr; //make the thread first time
                    curr = curr->left;
                }else{
                    leftchild->right = nullptr; // Thread exists => this is second time
                    curr= curr->right;
                }
            }
        }
        if(print == true){
            for(auto i: result){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    
    /*DFS For traversal of Tree for Left view*/
    void dfs(TreeNode *node, int currentLevel, int &maxLevel, vector<int> & result){
        if(!node) return;
        if(currentLevel>maxLevel){
            result.push_back(node->val);
            maxLevel = currentLevel;
        }
        dfs(node->left,currentLevel+1,maxLevel,result);
        dfs(node->right,currentLevel+1,maxLevel,result);
    }
    vector<int> leftView(TreeNode *node,bool print = false) {
        vector<int> result;
        if(node == nullptr){
            return {};
        }
        int currentLevel = 0, maxLevel = -1;
        dfs(node, currentLevel, maxLevel,result);
        if(print == true){
            for(auto i: result){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return result;
    }
    /*Level order for top and bottom view*/
    void Levelorder(TreeNode*node,queue<pair<TreeNode*,int>> &q, map<int,int> &mp){
        if(!node) return;
        int col = 0;
        q.push(make_pair(node,col));
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            auto curr = temp.first;
            auto column = temp.second;
            /*for top view just check if the current column exists in the map ,if yes then dont assign value*/
            mp[column] = curr->val;
            /*Swap the postion of two if's if the follow up quesition is we need to consider the earlier node if two node with same column encouters*/
            if(curr->left){
                auto ele = make_pair(curr->left,column-1);
                q.push(ele);
            }
            if(curr->right){
                auto ele = make_pair(curr->right,column+1);
                q.push(ele);
            }
        }
    }
    vector<int> bottomView(TreeNode*node, bool print = false){
        if(!node) return {};
        vector<int> result;
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        Levelorder(node,q,mp);

        for(auto i : mp)result.push_back(i.second);
        for(auto i: result){
            cout<<i<<" ";
        }
        cout<<endl;
        
        return result;
    }

    /*DFS For all {PRE-IN-POST} order in single traversal  */
    vector<vector<int>> dfs(TreeNode* node, stack<pair<TreeNode*, int>> &st){
        st.push(make_pair(node,1));
        vector<int> preorder,inorder,postorder;
        while(!st.empty()){
            auto temp = st.top();
            st.pop();
            if(temp.second == 1){
                auto curr = temp.first;
                preorder.push_back(curr->val);
                temp.second++;
                st.push(temp);
                if(curr->left){
                    auto leftchild = make_pair(curr->left,1);
                    st.push(leftchild);
                }
            }
            else if(temp.second == 2){
                auto curr = temp.first;
                inorder.push_back(curr->val);
                temp.second++;
                st.push(temp);
                if(curr->right){
                    auto rightchild = make_pair(curr->right,1);
                    st.push(rightchild);
                }
            }else{
                auto curr = temp.first;
                postorder.push_back(curr->val);
            }
        }
        return {preorder,inorder,postorder};
    }
    vector<vector<int>> getTreeTraversal(TreeNode *root,bool print = false){
        if(!root)return{};
        vector<vector<int>> result;
        stack<pair<TreeNode*, int>> st;
        result = dfs(root,st);
        if(print == true){
            for(auto i: result){
                for(auto j : i ){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
        
        return result;
    }
    /*vertical traversal of t*/
    void bfs(TreeNode* node, queue<tuple<TreeNode*,int,int>> &q, map<int,vector<pair<int,int>>> &mp ){
        if(!node)return;
        q.push({node,0,0}); // node, row, col
        while(!q.empty()){
            auto [curr, row, col] = q.front();
            q.pop();
            mp[col].push_back({row,curr->val});
            if(curr ->left){
                q.push({curr->left,row+1,col-1});
            }
            if(curr ->right){
                q.push({curr->right,row+1,col+1});
            }
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;
        map<int,vector<pair<int,int>>> mp;
        queue<tuple<TreeNode*,int,int>> q;
        bfs(root,q,mp);
        for(auto& [col,nodes] : mp){
            sort(nodes.begin(),nodes.end());
            vector<int> temp;
            for(auto& [row,val] : nodes){
                temp.push_back(val);
            }
            result.push_back(temp);
        }
        return result;
    }
    
    string pathToString(const vector<int>& path) {
        string s;
        for (int i = 0; i < path.size(); ++i) {
            s += to_string(path[i]);
            if (i != path.size() - 1) s += "->";
        }
        return s;
    }

    void dfs(TreeNode* root, vector<int>& currentPath, vector<string>& res) {
        if (!root) return;

        currentPath.push_back(root->val);

        if (!root->left && !root->right) {
            res.push_back(pathToString(currentPath));
        } else {
            dfs(root->left, currentPath, res);
            dfs(root->right, currentPath, res);
        }

        currentPath.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root, bool print = false) {
        vector<string> res;
        if (!root) return res;

        vector<int> currentPath;
        dfs(root, currentPath, res);

        if (print) {
            for (const auto& s : res) cout << s << " ";
            cout << endl;
        }

        return res;
    }
/*
    max width of a binary tree
*/  
    int widthOfBinaryTree(TreeNode* root,bool print = false) {
        if (!root) return 0;

        using ull = unsigned long long;
        queue<pair<TreeNode*, ull>> q;
        q.push({root, 0});

        int max_width = 0;
        while (!q.empty()) {
            ull L = q.front().second;   // leftmost index
            ull R = q.back().second;    // rightmost index
            max_width = max(max_width, (int)(R - L + 1));

            int n = q.size();
            while (n--) {
                auto [node, col] = q.front();
                q.pop();
                col-=L;
                if (node->left) q.push({node->left, 2 * col + 1});
                if (node->right) q.push({node->right, 2 * col + 2});
            }
        }
        if(print)cout<< max_width <<endl;
        return max_width;
    }

};




void solve(){
    Binary_Tree bt;
    bt.createBinaryTree();
    // cout<<"Traversals are below"<<endl;

    // cout<<"Preorder Traversal - :"<<endl;
    // bt.printpreorder();cout<<endl;

    // cout<<"Inorder Traversal - :"<<endl;
    // bt.printinorder();cout<<endl;

    // cout<<"Postorder Traversal - :"<<endl;
    // bt.printpostorder();cout<<endl;
    
    // cout<<"Level Order Traversal"<<endl;
    // bt.printlevelorder(bt.getRoot());cout<<endl;
    // cout<<"Height of binary tree-: "<<bt.height(bt.getRoot())<<endl;

    // cout<<"Inorder Traversal By Morris Method- : "<<endl;
    // bt.MorrisInorder(bt.getRoot(),true);

    // cout<<"Preorder Traversal By Morris Method- : "<<endl;
    // bt.MorrisPreorder(bt.getRoot(),true);

    // cout<<"Left View of Binary Tree- : "<<endl;
    // bt.leftView(bt.getRoot(),true);

    // cout<<"Bottom View of Binary Tree -: "<<endl;
    // bt.bottomView(bt.getRoot(),true);

    // cout<<"All 3 order {Pre-order,Inorder,Postorder} of the tree in single traversal -: "<<endl;
    // bt.getTreeTraversal(bt.getRoot(),true);

    // cout<<"Root to leaf -: " <<endl;
    // bt.binaryTreePaths(bt.getRoot());

    //cout<<"Width of binary tree - : "<<endl
    // bt.widthOfBinaryTree(bt.getRoot(),true);
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