/* 
    author: Aditya Gupta 
    created: 18.07.2025 14:10:06
*/

#include <bits/stdc++.h>
using namespace std;

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

    ~Binary_Tree(){
        destroy(root);
    };

    int height(TreeNode* node) {
        if (node == nullptr) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
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
    /*Function to get all traversal  */
    vector<vector<int>> getTreeTraversal(TreeNode *root,bool print = false){
        if(!root)return{};
        vector<vector<int>> result;
        stack<pair<TreeNode*, int>> st;
        result = dfs(root,st);
        if(print == true){
            for(int i=0;i<result.size();i++){
                if(i==0){
                    cout<<"Preorder -: ";
                }else if(i==1){
                    cout<<"Inorder -: ";
                }else{
                    cout<<"Postorder -: ";
                }
                for(auto j : result[i] ){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
        
        return result;
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
    
    // cout<<"Level Order Traversal"<<endl;
    // bt.printlevelorder(bt.getRoot());cout<<endl;

    // cout<<"Height of binary tree-: "<<bt.height(bt.getRoot())<<endl;


    cout<<"All 3 order {Pre-order,Inorder,Postorder} of the tree in single traversal -: "<<endl;
    bt.getTreeTraversal(bt.getRoot(),true);

//     cout<<"Width of binary tree - : "<<endl;
//     bt.widthOfBinaryTree(bt.getRoot());
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